/* 
Basado en la documentacion: https://docs.python.org/3/reference/lexical_analysis.html#

Python Keywords:
False      await      else       import     pass
None       break      except     in         raise
True       class      finally    is         return
and        continue   for        lambda     try
as         def        from       nonlocal   while
assert     del        global     not        with
async      elif       if         or         yield

Python Operators:
+       -       *       **      /       //      %      @
<<      >>      &       |       ^       ~       :=
<       >       <=      >=      ==      !=

*/

%{
#include <iostream>
#include <stack>
#include <cstdlib>
#include <string.h>
#include "parser.hpp"
extern YYSTYPE yylval;
extern YYLTYPE yylloc;


int comment_start_line;
std::stack<int> _indent_stack;
%}


%option noyywrap
%option yylineno
%x COMMENT

%%

%{
  /**/
  if (_indent_stack.empty()) {
    _indent_stack.push(0);
  }
%}

(\"\"\")           { BEGIN(COMMENT); comment_start_line = yylineno; }

<COMMENT>{
(\"\"\")           { BEGIN(INITIAL); } // Fin del comentario
\n               { /* Ignorar saltos de línea dentro del comentario */ }
.                { /* Ignorar cualquier otro carácter dentro del comentario */ }
<<EOF>>          { 
                   std::cerr << "Error: Comentario multilínea sin cerrar. Iniciado en la línea " 
                             << comment_start_line << std::endl;
                   yyterminate();
                 }
}

^[ \t]*\r?\n   { /* Ignoramos lineas en blanco */ }
^[ \t]*#.*\r?\n    { /* Ignoramos comentarios en una linea fisica */ }
#.*$        { /* Ignoramos comentarios que estan dps de un statement */ }


^[ \t]+     {
              /**/
              if (_indent_stack.top() < yyleng) {
                /**/
                //std::cout << "INDENT" << std::endl;
                _indent_stack.push(yyleng);
                yylval.token = INDENT; return INDENT;
              } else {
                /**/
                while (!_indent_stack.empty() && _indent_stack.top() != yyleng) {
                  _indent_stack.pop();
                  //std::cout << "DEDENT" << std::endl;
                  yylval.token = DEDENT; return DEDENT;
                }

                /**/
                if (_indent_stack.empty()) {
                  std::cerr << "Error: Incorrect indentation on line "
                    << yylineno << std::endl;
                  return 1;
                  exit(1);
                }
              }
            }

^[^ \t\n]+  {
              /**/
              while(_indent_stack.top() != 0) {
                _indent_stack.pop();
                //std::cout << "DEDENT" << std::endl;
                yylval.token = DEDENT; return DEDENT;
              }
              REJECT;
            }

\r?\n       {
                yylval.token = NEWLINE; return NEWLINE;
                //std::cout << "NEWLINE" << std::endl;
            }

<<EOF>>     {
              /**/
              while(_indent_stack.top() != 0) {
                _indent_stack.pop();
                //std::cout << "DEDENT" << std::endl;
                yylval.token = DEDENT; return DEDENT;
              }
              return ENDMARKER;
            }

[ \t]       { /* Ignoramos espacios blancos que no sean los de arriba */ }

"and"       { yylval.token = AND; return AND; }
"break"     { yylval.token = BREAK; return BREAK; }
"def"       { yylval.token = DEF; return DEF; }
"elif"      { yylval.token = ELIF; return ELIF; }
"else"      { yylval.token = ELSE; return ELSE; }
"for"       { yylval.token = FOR; return FOR; }
"if"        { yylval.token = IF; return IF; }
"not"       { yylval.token = NOT; return NOT; }
"or"        { yylval.token = OR; return OR; }
"return"    { yylval.token = RETURN; return RETURN; }
"while"     { yylval.token = WHILE; return WHILE; }
"True"      { yylval.str = new std::string("true"); return TBOOLEAN; }
"False"     { yylval.str = new std::string("false"); return FBOOLEAN; }
"for"       { yylval.token = FOR; return FOR; }
"in"        { yylval.token = IN; return IN; }
"range"     { yylval.token = RANGE; return RANGE; }
"def"       { yylval.token = DEF; return DEF; }
"print"     { yylval.token = PRINT; return PRINT; }

[A-Z][A-Z0-9_]*           {yylval.str = new std::string(yytext, yyleng);
                          return CONSTANT;}

[a-zA-Z_][a-zA-Z0-9_]*  {yylval.str = new std::string(yytext, yyleng);
                        return IDENTIFIER;}

-?[0-9]*\.[0-9]{1,7}   {yylval.str = new std::string(yytext, yyleng);
                        return FLOAT;}

-?[0-9]*"."[0-9]+       {yylval.str = new std::string(yytext, yyleng);
                        return DOUBLE;}

-?[0-9]+                {yylval.str = new std::string(yytext, yyleng);
                        return INTEGER;}

(\"[^\"]+\")            {yylval.str = new std::string(yytext, yyleng);
                        return STRING;}

(\'[^\']\')                  {yylval.str = new std::string(yytext, yyleng);
                              return CHAR;}

"="         { yylval.token = EQUALS; return EQUALS; }
"+"         { yylval.token = PLUS; return PLUS; }
"-"         { yylval.token = MINUS; return MINUS; }
"*"         { yylval.token = TIMES; return TIMES; }
"/"         { yylval.token = DIVIDEDBY; return DIVIDEDBY; }
"=="        { yylval.token = EQ; return EQ; }
"!="        { yylval.token = NEQ; return NEQ; }
">"         { yylval.token = GT; return GT; }
">="        { yylval.token = GTE; return GTE; }
"<"         { yylval.token = LT; return LT; }
"<="        { yylval.token = LTE; return LTE; }
"("         { yylval.token = LPAREN; return LPAREN; }
")"         { yylval.token = RPAREN; return RPAREN; }
","         { yylval.token = COMMA; return COMMA; }
":"         { yylval.token = COLON; return COLON; }
"["         { yylval.token = LBRACK; return LBRACK; }
"]"         { yylval.token = RBRACK; return RBRACK; }

.           { yylval.token = UNKNOWN; return UNKNOWN; }

%%