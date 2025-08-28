%{
#include <string>
#include <iostream>
#include "parser.tab.hh"

    // Global variables for passing values to parser
std::string string_val;
int num_val;
int line_num = 1;
%}

%option noyywrap

    /* Define patterns */
DIGIT       [0-9]
LETTER      [a-zA-Z_]
ALNUM       [a-zA-Z0-9_]
WHITESPACE  [ \t\r]
NEWLINE     \n
STRING      \"([^\"\\]|\\.)*\"

%%

{WHITESPACE}+   { /* ignore whitespace */ }
{NEWLINE}       { line_num++; }

"//".*          { /* ignore single-line comments */ }
"/*"([^*]|\*+[^*/])*\*+"/" { /* ignore multi-line comments */ }

    /* Keywords and operators - using TOKMAP/TOKSET to avoid AST enum conflicts */
"map"           { return TOKMAP; }
"Set"           { return TOKSET; }
"List"          { return LIST; }
"string"        { return STRING_TYPE; }
"int"           { return INT_TYPE; }

"PRECONDITION"  { return PRECONDITION; }
"POSTCONDITION" { return POSTCONDITION; }

"OK"            { return OK; }
"CREATED_201"   { return CREATED_201; }
"BAD_REQUEST_400" { return BAD_REQUEST_400; }
"NIL"           { return NIL; }
"ADMIN"         { return ADMIN; }

"AND"           { return AND; }
"OR"            { return OR; }
"NOT"           { return NOT; }
"in"            { return IN; }
"UNION"         { return UNION; }
"∪"             { return UNION; }

    /* identifiers (AFTER keywords) */
{LETTER}{ALNUM}* {
    string_val = std::string(yytext);
    yylval.str_val = new std::string(string_val);             
    return IDENTIFIER;
}

    /* Punctuation */
":"             { return COLON; }
";"             { return SEMICOLON; }
","             { return COMMA; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"["             { return LBRACKET; }
"]"             { return RBRACKET; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
"="             { return EQUALS; }
"==>"           { return IMPLIES; }
"->"            { return ARROW; }
"'"             { return PRIME; }
"."             { return DOT; }
"*"             { return STAR; }
"\\"            { return BACKSLASH; }

    /* Numbers */
{DIGIT}+        {
    num_val = atoi(yytext);
    yylval.int_val = num_val;        /* NEW: attach to token value */
    return NUMBER;
}

    /* String literals */
{STRING}        {
    string_val = std::string(yytext);
    string_val = string_val.substr(1, string_val.length() - 2); // strip quotes
    yylval.str_val = new std::string(string_val);               /* NEW */
    return STRING_LIT;
}

    /* Separator lines (ignore) */
"-"{20,}[^\n]*  { /* ignore separator lines */ }

    /* Identifiers - must come after keywords */
{LETTER}{ALNUM}* { 
    string_val = std::string(yytext);
    return IDENTIFIER; 
}

    /* Catch-all for any other character */
.               { 
    std::cerr << "Unknown character: " << yytext << std::endl; 
}

%%
