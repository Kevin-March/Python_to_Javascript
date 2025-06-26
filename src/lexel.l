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
#include "parser.tab.h"
YYSTYPE yylval;
YYLTYPE yylloc;

yypstate* pstate = yypstate_new();

#define PUSH_TOKEN(token) do {  \
  int s = yypush_parse(pstate, token, &yylval, &yylloc);  \
  if (s != YYPUSH_MORE) {                                 \
    yypstate_delete(pstate);                              \
    return s;                                             \
  }                                                       \
} while(0)


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
                PUSH_TOKEN((yylval.token = INDENT));
              } else {
                /**/
                while (!_indent_stack.empty() && _indent_stack.top() != yyleng) {
                  _indent_stack.pop();
                  //std::cout << "DEDENT" << std::endl;
                  PUSH_TOKEN((yylval.token = DEDENT));
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
                PUSH_TOKEN((yylval.token = DEDENT));
              }
              REJECT;
            }

\r?\n       {
                PUSH_TOKEN((yylval.token = NEWLINE)); 
                //std::cout << "NEWLINE" << std::endl;
            }

<<EOF>>     {
              /**/
              while(_indent_stack.top() != 0) {
                _indent_stack.pop();
                //std::cout << "DEDENT" << std::endl;
                PUSH_TOKEN((yylval.token = DEDENT));
              }

              int s = yypush_parse(pstate, 0, NULL, NULL);
                yypstate_delete(pstate);
                return s;
              //yyterminate();
            }

[ \t]       { /* Ignoramos espacios blancos que no sean los de arriba */ }

"and"       { PUSH_TOKEN((yylval.token = AND));}
"break"     { PUSH_TOKEN((yylval.token = BREAK));}
"def"       { PUSH_TOKEN((yylval.token = DEF));}
"elif"      { PUSH_TOKEN((yylval.token = ELIF));}
"else"      { PUSH_TOKEN((yylval.token = ELSE));}
"for"       { PUSH_TOKEN((yylval.token = FOR));}
"if"        { PUSH_TOKEN((yylval.token = IF));}
"not"       { PUSH_TOKEN((yylval.token = NOT));}
"or"        { PUSH_TOKEN((yylval.token = OR));}
"return"    { PUSH_TOKEN((yylval.token = RETURN));}
"while"     { PUSH_TOKEN((yylval.token = WHILE));}
"True"      { yylval.bool_val = true;
              PUSH_TOKEN(BOOLEAN);}
"False"     { yylval.bool_val = false;
              PUSH_TOKEN(BOOLEAN);}
"in"        { PUSH_TOKEN((yylval.token = IN));}
"range"     { PUSH_TOKEN((yylval.token = RANGE));}
"print"     { PUSH_TOKEN((yylval.token = PRINT));}

[A-Z][A-Z0-9_]*           {yylval.str = new std::string(yytext);
                          PUSH_TOKEN(CONSTANT);}

[a-zA-Z_][a-zA-Z0-9_]*  {yylval.str = new std::string(yytext);
                        PUSH_TOKEN(IDENTIFIER);}

-?[0-9]*\.[0-9]{1,7}   {yylval.float_val = atof(yytext);
                        PUSH_TOKEN(FLOAT);}

-?[0-9]+                {yylval.int_val = atoi(yytext);
                        PUSH_TOKEN(INTEGER);}

(\"[^\"]+\")            {yylval.str = new std::string(yytext);
                        PUSH_TOKEN(STRING);}

"=="        { PUSH_TOKEN((yylval.token = EQ));}
"!="        { PUSH_TOKEN((yylval.token = NEQ));}
">"         { PUSH_TOKEN((yylval.token = GT));}
">="        { PUSH_TOKEN((yylval.token = GTE));}
"<"         { PUSH_TOKEN((yylval.token = LT));}
"<="        { PUSH_TOKEN((yylval.token = LTE));}
"("         { PUSH_TOKEN((yylval.token = LPAREN));}
")"         { PUSH_TOKEN((yylval.token = RPAREN));}
","         {  PUSH_TOKEN((yylval.token = COMMA));}
":"         { PUSH_TOKEN((yylval.token = COLON));}
"["         { PUSH_TOKEN((yylval.token = LBRACK));}
"]"         { PUSH_TOKEN((yylval.token = RBRACK));}

"+"         { PUSH_TOKEN((yylval.token = PLUS));}
"-"         { PUSH_TOKEN((yylval.token = MINUS));}

.           { PUSH_TOKEN((yylval.token = UNKNOWN));}

%%