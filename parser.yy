/* parser.yy — typed tokens (IDENTIFIER/STRING_LIT/NUMBER carry values),
   flat item stream; safe against string_val races. */

%define parse.error verbose

%code requires {
  #include <memory>
  #include <vector>
  #include <string>
  #include <cstdio>
  #include "ast.hpp"
}

%code {
  #include <iostream>
  #include <fstream>
  #include <utility>
  #include <unistd.h>

  extern int line_num;
  extern FILE* yyin;

  int yylex();
  void yyerror(const char* s);

  std::unique_ptr<Spec> parsed_spec;

  std::unique_ptr<Map> create_empty_map() {
      std::vector<std::pair<std::unique_ptr<Var>, std::unique_ptr<Expr>>> pairs;
      return std::unique_ptr<Map>(new Map(std::move(pairs)));
  }
  std::unique_ptr<Set> create_set(std::vector<std::unique_ptr<Expr>> elements) {
      return std::unique_ptr<Set>(new Set(std::move(elements)));
  }
  void ensure_spec() {
      if (!parsed_spec) {
          parsed_spec = std::make_unique<Spec>(
            std::vector<std::unique_ptr<Decl>>{},
            std::vector<std::unique_ptr<Init>>{},
            std::vector<std::unique_ptr<FuncDecl>>{},
            std::vector<std::unique_ptr<API>>{}
          );
      }
  }
}

/* semantic value union */
%union {
    std::string* str_val;
    int int_val;

    Spec*      spec_val;
    Decl*      decl_val;
    Init*      init_val;
    FuncDecl*  func_decl_val;
    API*       api_val;
    APIcall*   api_call_val;
    TypeExpr*  type_val;
    Expr*      expr_val;

    std::vector<std::unique_ptr<TypeExpr>>*  type_list_val;
    std::vector<std::unique_ptr<Expr>>*      expr_list_val;

    HTTPResponseCode http_code_val;
}

/* tokens with values */
%token <str_val> IDENTIFIER STRING_LIT
%token <int_val> NUMBER

/* other tokens (no attached value) */
%token TOKMAP TOKSET LIST STRING_TYPE INT_TYPE
%token PRECONDITION POSTCONDITION
%token OK CREATED_201 BAD_REQUEST_400 NIL ADMIN
%token AND OR NOT IN UNION
%token COLON SEMICOLON COMMA LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE
%token EQUALS IMPLIES ARROW PRIME DOT STAR BACKSLASH

/* precedence */
%left OR
%left AND
%right NOT
%left EQUALS
%left IN
%left DOT BACKSLASH
%right PRIME

/* typed nonterminals */
%type <spec_val>       spec
%type <decl_val>       global_declaration
%type <init_val>       initialization
%type <func_decl_val>  function_declaration
%type <api_val>        api_block
%type <api_call_val>   api_call
%type <type_val>       type_expr
%type <type_list_val>  type_list param_list return_types
%type <expr_val>       expression primary_expr
%type <expr_list_val>  expression_list argument_list
%type <http_code_val>  http_code

%start spec

%%

spec:
      /* empty */ { ensure_spec(); $$ = parsed_spec.get(); }
    | items      { ensure_spec(); $$ = parsed_spec.get(); }
    ;

items:
      item
    | items item
    ;

item:
      global_declaration { ensure_spec(); parsed_spec->globals.push_back(std::unique_ptr<Decl>($1)); }
    | initialization     { ensure_spec(); parsed_spec->init.push_back(std::unique_ptr<Init>($1)); }
    | function_declaration { ensure_spec(); parsed_spec->functions.push_back(std::unique_ptr<FuncDecl>($1)); }
    | api_block            { ensure_spec(); parsed_spec->blocks.push_back(std::unique_ptr<API>($1)); }
    ;

/* U : (string -> string) map */
global_declaration:
    IDENTIFIER COLON type_expr {
        $$ = new Decl(*$1, std::unique_ptr<TypeExpr>($3));
        delete $1;
    }
    ;

/* U = {} */
initialization:
    IDENTIFIER EQUALS expression {
        $$ = new Init(*$1, std::unique_ptr<Expr>($3));
        delete $1;
    }
    ;

/* register_student: string * string * string -> HTTPResponse * string */
function_declaration:
    IDENTIFIER COLON param_list ARROW return_types {
        $$ = new FuncDecl(*$1, std::move(*$3),
                          std::make_pair(HTTPResponseCode::OK_200, std::move(*$5)));
        delete $1; delete $3; delete $5;
    }
    ;

param_list:
      type_expr {
        $$ = new std::vector<std::unique_ptr<TypeExpr>>();
        $$->push_back(std::unique_ptr<TypeExpr>($1));
      }
    | param_list STAR type_expr {
        $1->push_back(std::unique_ptr<TypeExpr>($3));
        $$ = $1;
      }
    ;

return_types:
      type_expr {
        $$ = new std::vector<std::unique_ptr<TypeExpr>>();
        $$->push_back(std::unique_ptr<TypeExpr>($1));
      }
    | return_types STAR type_expr {
        $1->push_back(std::unique_ptr<TypeExpr>($3));
        $$ = $1;
      }
    ;

/* labeled or unlabeled */
api_block:
      IDENTIFIER COLON PRECONDITION COLON expression api_call POSTCONDITION COLON expression {
        Response response(HTTPResponseCode::OK_200, std::unique_ptr<Expr>($9));
        $$ = new API(std::unique_ptr<Expr>($5), std::unique_ptr<APIcall>($6), std::move(response));
        delete $1;
      }
    | PRECONDITION COLON expression api_call POSTCONDITION COLON expression {
        Response response(HTTPResponseCode::OK_200, std::unique_ptr<Expr>($7));
        $$ = new API(std::unique_ptr<Expr>($3), std::unique_ptr<APIcall>($4), std::move(response));
      }
    ;

/* f(x: T, y: U) ==> (OK)  or  ==> (OK, token) */
api_call:
      IDENTIFIER LPAREN argument_list RPAREN IMPLIES LPAREN http_code RPAREN {
        auto func_call = std::make_unique<FuncCall>(*$1, std::move(*$3));
        Response response($7, nullptr);
        $$ = new APIcall(std::move(func_call), std::move(response));
        delete $1; delete $3;
      }
    | IDENTIFIER LPAREN argument_list RPAREN IMPLIES LPAREN http_code COMMA IDENTIFIER RPAREN {
        auto func_call = std::make_unique<FuncCall>(*$1, std::move(*$3));
        Response response($7, std::make_unique<Var>(*$9));
        $$ = new APIcall(std::move(func_call), std::move(response));
        delete $1; delete $3; delete $9;
      }
    ;

/* x: T, y: U – we store names as Vars for now; drop the types */
argument_list:
      IDENTIFIER COLON type_expr {
        $$ = new std::vector<std::unique_ptr<Expr>>();
        $$->push_back(std::make_unique<Var>(*$1));
        delete $1; delete $3;
      }
    | argument_list COMMA IDENTIFIER COLON type_expr {
        $1->push_back(std::make_unique<Var>(*$3));
        $$ = $1;
        delete $3; delete $5;
      }
    | /* empty */ {
        $$ = new std::vector<std::unique_ptr<Expr>>();
      }
    ;

type_expr:
      STRING_TYPE { $$ = new TypeConst("string"); }
    | INT_TYPE    { $$ = new TypeConst("int"); }
    | IDENTIFIER  { $$ = new TypeConst(*$1); delete $1; }
    | LPAREN type_expr ARROW type_expr RPAREN TOKMAP {
        $$ = new MapType(std::unique_ptr<TypeExpr>($2), std::unique_ptr<TypeExpr>($4));
      }
    | type_expr TOKSET {
        $$ = new SetType(std::unique_ptr<TypeExpr>($1));
      }
    | LIST LBRACKET type_expr RBRACKET {
        $$ = new SetType(std::unique_ptr<TypeExpr>($3)); /* map List[T] -> Set[T] */
      }
    | LBRACE type_list RBRACE {
        $$ = new TupleType(std::move(*$2));
        delete $2;
      }
    ;

type_list:
      type_expr {
        $$ = new std::vector<std::unique_ptr<TypeExpr>>();
        $$->push_back(std::unique_ptr<TypeExpr>($1));
      }
    | type_list COMMA type_expr {
        $1->push_back(std::unique_ptr<TypeExpr>($3));
        $$ = $1;
      }
    ;

expression:
      primary_expr                  { $$ = $1; }
    | expression AND expression     {
        auto args = new std::vector<std::unique_ptr<Expr>>();
        args->push_back(std::unique_ptr<Expr>($1));
        args->push_back(std::unique_ptr<Expr>($3));
        $$ = new FuncCall("AND", std::move(*args)); delete args;
      }
    | expression OR expression      {
        auto args = new std::vector<std::unique_ptr<Expr>>();
        args->push_back(std::unique_ptr<Expr>($1));
        args->push_back(std::unique_ptr<Expr>($3));
        $$ = new FuncCall("OR", std::move(*args)); delete args;
      }
    | NOT expression                {
        auto args = new std::vector<std::unique_ptr<Expr>>();
        args->push_back(std::unique_ptr<Expr>($2));
        $$ = new FuncCall("NOT", std::move(*args)); delete args;
      }
    | expression IN expression      {
        auto args = new std::vector<std::unique_ptr<Expr>>();
        args->push_back(std::unique_ptr<Expr>($1));
        args->push_back(std::unique_ptr<Expr>($3));
        $$ = new FuncCall("inMapVerify", std::move(*args)); delete args;
      }
    | expression LBRACKET expression RBRACKET {
        auto args = new std::vector<std::unique_ptr<Expr>>();
        args->push_back(std::unique_ptr<Expr>($1));
        args->push_back(std::unique_ptr<Expr>($3));
        $$ = new FuncCall("[]", std::move(*args)); delete args;
      }
    | expression LBRACKET expression ARROW expression RBRACKET {
        auto args = new std::vector<std::unique_ptr<Expr>>();
        args->push_back(std::unique_ptr<Expr>($1));
        args->push_back(std::unique_ptr<Expr>($3));
        args->push_back(std::unique_ptr<Expr>($5));
        $$ = new FuncCall("mapupdate", std::move(*args)); delete args;
      }
    | expression PRIME              {
        auto args = new std::vector<std::unique_ptr<Expr>>();
        args->push_back(std::unique_ptr<Expr>($1));
        $$ = new FuncCall("'", std::move(*args)); delete args;
      }
    | expression EQUALS expression  {
        auto args = new std::vector<std::unique_ptr<Expr>>();
        args->push_back(std::unique_ptr<Expr>($1));
        args->push_back(std::unique_ptr<Expr>($3));
        $$ = new FuncCall("=", std::move(*args)); delete args;
      }
    | expression DOT IDENTIFIER     {
        auto args = new std::vector<std::unique_ptr<Expr>>();
        args->push_back(std::unique_ptr<Expr>($1));
        args->push_back(std::make_unique<String>(*$3));
        $$ = new FuncCall("field", std::move(*args)); delete args; delete $3;
      }
    | expression BACKSLASH expression {
        auto args = new std::vector<std::unique_ptr<Expr>>();
        args->push_back(std::unique_ptr<Expr>($1));
        args->push_back(std::unique_ptr<Expr>($3));
        $$ = new FuncCall("\\", std::move(*args)); delete args;
      }
    | IDENTIFIER LPAREN expression_list RPAREN {
        $$ = new FuncCall(*$1, std::move(*$3)); delete $1; delete $3;
      }
    ;

primary_expr:
      IDENTIFIER   { $$ = new Var(*$1); delete $1; }
    | NUMBER       { $$ = new Num($1); }
    | STRING_LIT   { $$ = new String(*$1); delete $1; }
    | NIL          {
        auto args = new std::vector<std::unique_ptr<Expr>>();
        $$ = new FuncCall("NIL", std::move(*args)); delete args;
      }
    | ADMIN        { $$ = new Var("ADMIN"); }
    | LBRACE RBRACE { $$ = create_empty_map().release(); }
    | LBRACE expression_list RBRACE {
        $$ = create_set(std::move(*$2)).release(); delete $2;
      }
    | LPAREN expression RPAREN { $$ = $2; }
    ;

expression_list:
      expression {
        $$ = new std::vector<std::unique_ptr<Expr>>();
        $$->push_back(std::unique_ptr<Expr>($1));
      }
    | expression_list COMMA expression {
        $1->push_back(std::unique_ptr<Expr>($3));
        $$ = $1;
      }
    | /* empty */ {
        $$ = new std::vector<std::unique_ptr<Expr>>();
      }
    ;

http_code:
      OK              { $$ = HTTPResponseCode::OK_200; }
    | CREATED_201     { $$ = HTTPResponseCode::CREATED_201; }
    | BAD_REQUEST_400 { $$ = HTTPResponseCode::BAD_REQUEST_400; }
    ;

%%

void yyerror(const char* s) {
    std::cerr << "Parse error at line " << line_num << ": " << s << std::endl;
}

std::unique_ptr<Spec> parse_spec(std::istream& in) {
    parsed_spec.reset();

    std::string temp_filename = "/tmp/spec_input.txt";
    std::ofstream temp_file(temp_filename);
    std::string line;
    while (std::getline(in, line)) temp_file << line << '\n';
    temp_file.close();

    yyin = fopen(temp_filename.c_str(), "r");
    if (!yyin) {
        std::cerr << "Failed to open temporary file" << std::endl;
        return nullptr;
    }

    int result = yyparse();
    fclose(yyin);
    unlink(temp_filename.c_str());

    if (result == 0 && parsed_spec) return std::move(parsed_spec);
    std::cerr << "Parse failed" << std::endl;
    return nullptr;
}
