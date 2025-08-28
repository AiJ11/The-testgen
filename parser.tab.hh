/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_HH_INCLUDED
# define YY_YY_PARSER_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 6 "parser.yy"

  #include <memory>
  #include <vector>
  #include <string>
  #include <cstdio>
  #include "ast.hpp"

#line 57 "parser.tab.hh"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    STRING_LIT = 259,              /* STRING_LIT  */
    NUMBER = 260,                  /* NUMBER  */
    TOKMAP = 261,                  /* TOKMAP  */
    TOKSET = 262,                  /* TOKSET  */
    LIST = 263,                    /* LIST  */
    STRING_TYPE = 264,             /* STRING_TYPE  */
    INT_TYPE = 265,                /* INT_TYPE  */
    PRECONDITION = 266,            /* PRECONDITION  */
    POSTCONDITION = 267,           /* POSTCONDITION  */
    OK = 268,                      /* OK  */
    CREATED_201 = 269,             /* CREATED_201  */
    BAD_REQUEST_400 = 270,         /* BAD_REQUEST_400  */
    NIL = 271,                     /* NIL  */
    ADMIN = 272,                   /* ADMIN  */
    AND = 273,                     /* AND  */
    OR = 274,                      /* OR  */
    NOT = 275,                     /* NOT  */
    IN = 276,                      /* IN  */
    UNION = 277,                   /* UNION  */
    COLON = 278,                   /* COLON  */
    SEMICOLON = 279,               /* SEMICOLON  */
    COMMA = 280,                   /* COMMA  */
    LPAREN = 281,                  /* LPAREN  */
    RPAREN = 282,                  /* RPAREN  */
    LBRACKET = 283,                /* LBRACKET  */
    RBRACKET = 284,                /* RBRACKET  */
    LBRACE = 285,                  /* LBRACE  */
    RBRACE = 286,                  /* RBRACE  */
    EQUALS = 287,                  /* EQUALS  */
    IMPLIES = 288,                 /* IMPLIES  */
    ARROW = 289,                   /* ARROW  */
    PRIME = 290,                   /* PRIME  */
    DOT = 291,                     /* DOT  */
    STAR = 292,                    /* STAR  */
    BACKSLASH = 293                /* BACKSLASH  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 48 "parser.yy"

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

#line 131 "parser.tab.hh"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_HH_INCLUDED  */
