%{
#include <iostream>
#include <map>
#include <algorithm> // Incluir para std::find
#include <cstring>
#include <sstream> // Para usar std::stringstream
#include <string>  // Para usar std::string
#include <vector>
#include "parser.hpp"

std::map<std::string, std::map<std::string, std::string>> symbol_table; // Tabla de símbolos
std::string* goalStr;
std::string* functionDeclarationsStr;
std::vector<std::string> current_scope;



extern int yylex();
extern int yylineno;



void yyerror(const char* err) {
  extern int yychar;
  std::cerr << "Error de sintaxis: " << err << " en la línea " << yylineno;
  std::cerr << " (token: " << yychar << ")";
  std::cerr << std::endl;
}

int tipo_actual = 0;
int tipo_actual2 = 0;
int tipo_actual3 = 0;
int es_id = 0;

%}

%union {
  float value;
  std::string* str;
  int token;
}

%define parse.error verbose




%token <str> IDENTIFIER INTEGER BOOLEAN FLOAT STRING CHAR DOUBLE CONSTANT
%token <token> EQUALS PLUS MINUS TIMES DIVIDEDBY
%token <token> EQ NEQ GT GTE LT LTE RETURN
%token <token> INDENT DEDENT NEWLINE IF COLON
%token <token> AND BREAK ELIF ELSE FOR IN RANGE NOT OR WHILE DEF
%token <token> SEMICOLON LPAREN RPAREN COMMA LBRACK RBRACK
%token <token> PRINT UNKNOWN ENDMARKER
%token <token> POW
%token <token> CLASS
%token <token> ARROW
%token <token> MOD
%token <token> NONE


%type <str> parameter_list 
%type <str> small_stmt expr_stmt

/* %type <str> flowcontrol */

%type <str> program stmt_list_opt stmt simple_stmt compound_stmt small_stmt_list 

%type <str> test or_test and_test not_test comparison comp_op expr
%type <str> arith_expr term factor power atom_expr atom
%type <str> list testlist subscriptlist trailer subscript sliceop argument arglist

/*faltantes*/
%type <str> augassign
%type <str> flow_stmt
%type <str> if_stmt elif_clauses else_clause_opt
%type <str> while_stmt
%type <str> for_stmt
%type <str> parameters
%type <str> funcdef
%type <str> return_type_opt

%type <str> suite stmt_list

%left PLUS MINUS 
%left TIMES DIVIDEDBY
%right UMINUS
%start program

%%

program
  : stmt_list_opt { goalStr = new std::string(*$1); 
                              delete $1; }
  ;

stmt_list_opt
  : /* empty */ { $$ = new std::string(""); }
  | stmt_list_opt stmt { $$ = new std::string(*$1 + "\n"+ *$2);
                                    delete $1; delete $2; }
  ;

stmt
  : simple_stmt
  | compound_stmt
  | NEWLINE { $$ = new std::string(""); }
  ;

simple_stmt
  : small_stmt_list NEWLINE { $$ = new std::string(*$1 + ";");
                              delete $1; }
  | small_stmt_list { $$ = new std::string(*$1 + ";");
                              delete $1; }
  ;


small_stmt_list
  : small_stmt_list SEMICOLON small_stmt { $$ = new std::string(*$1 + *$3);
                                           delete $1; delete $3;}
  | small_stmt SEMICOLON { $$ = $1; }
  | small_stmt
  ;

small_stmt
  : expr_stmt
  | flow_stmt
  ; 

// TODO agregar manejo de scope
// TODO especificar que solo se puede hacer una asignación (no se puede hacer a=b=c=3)
expr_stmt
  : IDENTIFIER EQUALS test
      {
        if (symbol_table[current_scope.back()].count(*$1) == 0) {
            // no estaba declarada
            symbol_table[current_scope.back()][*$1] = "variable";
            $$ = new std::string("let " + *$1 + " = " + *$3 + ";");
        } else {
            // ya estaba declarada
            $$ = new std::string(*$1 + " = " + *$3);
        }
        delete $1;
        delete $3;
      }
  | IDENTIFIER annasign EQUALS test
      {
         if (symbol_table[current_scope.back()].count(*$1) == 0) {
            // no estaba declarada
            symbol_table[current_scope.back()][*$1] = "variable";
            $$ = new std::string("let " + *$1 + " = " + *$4 + ";");
        } else {
            // ya estaba declarada
            $$ = new std::string(*$1 + " = " + *$4);
        }
        delete $1; delete $4;
      }
  | IDENTIFIER 
      {
        if (symbol_table[current_scope.back()].count(*$1) == 0) {
            // no estaba declarada
            symbol_table[current_scope.back()][*$1] = "variable";
            $$ = new std::string("let " + *$1);
        } else {
            // ya estaba declarada
            $$ = new std::string(*$1);
        }
        delete $1;
      }
  | IDENTIFIER annasign
      {
        if (symbol_table[current_scope.back()].count(*$1) == 0) {
            // no estaba declarada
            symbol_table[current_scope.back()][*$1] = "variable";
            $$ = new std::string("let " + *$1 );
        } else {
            // ya estaba declarada
            $$ = new std::string(*$1);
        }
        delete $1;
      }
  | IDENTIFIER augassign test
      {
        if (symbol_table[current_scope.back()].count(*$1) == 0) {
            // no estaba declarada
            symbol_table[current_scope.back()][*$1] = "variable";
            $$ = new std::string("let " + *$1 + " = " + *$3 + ";");
        } else {
            // ya estaba declarada
            $$ = new std::string(*$1 + " = " + *$3);
        }
        delete $1;
        delete $3;
      }
  /*| test
      {
        $$ = $1;
      }
  */
  ;

annasign
  : COLON test { delete $2; } // Declaración de tipo que no se utiliza en JS
  ;

augassign
  : PLUS EQUALS { $$ = new std::string("+=");}
  | MINUS EQUALS { $$ = new std::string("-=");}
  | TIMES EQUALS { $$ = new std::string("*=");}
  | DIVIDEDBY EQUALS { $$ = new std::string("/=");}
  ;

flow_stmt
  : BREAK { $$ = new std::string("break"); }
  | RETURN test { $$ = new std::string("return" + *$2);
                  delete $2; }
  | RETURN { $$ = new std::string("return"); }
  ;  

compound_stmt
  : if_stmt
  | while_stmt
  | for_stmt
  | funcdef
  ;

if_stmt
  : IF test COLON suite elif_clauses else_clause_opt
      {
        // base if
        std::stringstream ss;
        ss << "if (" << *$2 << ") {\n\t" << *$5 << "}\n";

        // elif
        if ($5) {
          ss << *$5;
          delete $5;
        }

        // else
        if ($6) {
          ss << *$6;
          delete $6;
        }

        $$ = new std::string(ss.str());
        delete $2; delete $4;
      }
  ;
elif_clauses
  : /* empty */ { $$ = nullptr; }
  | elif_clauses ELIF test COLON NEWLINE suite
      {
        std::stringstream ss;
        if ($1) {
          ss << *$1;
          delete $1;
        }
        ss << "else if (" << *$3 << ") {\n" << *$6 << "}\n";
        $$ = new std::string(ss.str());
        delete $3; delete $6;
      }
  ;


else_clause_opt
  : /* empty */ { $$ = nullptr; }
  | ELSE COLON NEWLINE suite { $$ = new std::string("else {\n" + *$4 + "}\n"); delete $4; }
  ;

suite
  : simple_stmt 
  | NEWLINE INDENT stmt_list DEDENT { $$ = new std::string(*$3);
                                      delete $3;}
  ;

stmt_list
  : stmt
  | stmt_list stmt { $$ = new std::string(*$1 +*$2); 
                     delete $1; delete $2; }
  ;

while_stmt
  : WHILE test COLON suite 
      {
        std::stringstream ss;

        // generar el while
        ss << "while (" << *$2 << ") {\n" << *$4 << "}\n";

        $$ = new std::string(ss.str());
        delete $2;
        delete $4;
      }
  ;
for_stmt
  : FOR IDENTIFIER IN test COLON suite
      {
        // esto es para "for x in lista"
        std::stringstream ss;
        ss << "for (let " << *$2 << " of " << *$4 << ") {\n"
           << *$6 << "}\n";
        $$ = new std::string(ss.str());
        delete $2; delete $4; delete $6;
      }
  | FOR IDENTIFIER IN RANGE LPAREN testlist RPAREN COLON suite
      {
        // esto es para "for x in range(n)"
        std::stringstream ss;
        ss << "for (let " << *$2 << " = 0; "
           << *$2 << " < " << *$6 << "; " << *$2 << "++) {\n"
           << *$9 << "}\n";
        $$ = new std::string(ss.str());
        delete $2; delete $6; delete $9;
      }
  ;
funcdef
  : DEF IDENTIFIER parameters return_type_opt COLON suite
      {
        std::stringstream ss;

        // función en JavaScript con parámetros
        ss << "function " << *$2 << *$3 << " {\n" << *$6 << "}\n";

        // en JS no hay anotaciones de tipo de retorno, así que ignoramos $4
        $$ = new std::string(ss.str());

        delete $2; delete $3; delete $4; delete $6;
      }
  ;
parameters
  : LPAREN RPAREN { $$ = new std::string("()"); }
  | LPAREN parameter_list RPAREN
      {
        $$ = new std::string("(" + *$2 + ")");
        delete $2;
      }
  ;

parameter_list
  : IDENTIFIER { $$ = $1; }
  | parameter_list COMMA IDENTIFIER
      {
        $$ = new std::string(*$1 + ", " + *$3);
        delete $1; delete $3;
      }
  ;

return_type_opt
  : /* empty */ { /*En JavaScript no hay tipado de retorno, por eso solo parseamos, pero no lo incluimos en la salida. */ $$ = new std::string(""); }
  | ARROW test { $$ = $2; }
  ;

test
  : or_test { $$ = $1; }
  | or_test IF or_test ELSE test
  {
      $$ = new std::string("(" + *$3 + " ? " + *$1 + " : " + *$5 + ")");
      delete $1; delete $3; delete $5;
  }
  ;

or_test
  : and_test { $$ = $1; }
  | or_test OR and_test
  {
      $$ = new std::string("(" + *$1 + " || " + *$3 + ")");
      delete $1; delete $3;
  }
  ;

and_test
  : not_test { $$ = $1; }
  | and_test AND not_test
  {
      $$ = new std::string("(" + *$1 + " && " + *$3 + ")");
      delete $1; delete $3;
  }
  ;

not_test
  : NOT not_test
  {
      $$ = new std::string("!(" + *$2 + ")");
      delete $2;
  }
  | comparison { $$ = $1; }
  ;

comparison
  : expr { $$ = $1; }
  | comparison comp_op expr
  {
      $$ = new std::string("(" + *$1 + " " + *$2 + " " + *$3 + ")");
      delete $1; delete $2; delete $3;
  }
  | comparison IN expr  // Manejo especial para 'in'
  {
      // JS: arrays → includes(), objetos → in
      $$ = new std::string("(Array.isArray(" + *$3 + ") ? " + 
                            *$3 + ".includes(" + *$1 + ") : " +
                            "(" + *$1 + " in " + *$3 + "))");
      delete $1; delete $3;
  }
  ;

comp_op
  : EQ { $$ = new std::string("==="); }
  | NEQ { $$ = new std::string("!=="); }
  | LT { $$ = new std::string("<"); }
  | GT { $$ = new std::string(">"); }
  | LTE { $$ = new std::string("<="); }
  | GTE { $$ = new std::string(">="); }
  ;

expr
  : arith_expr { $$ = $1; }
  | expr '|' expr  // Bitwise OR (JS compatible)
  {
      $$ = new std::string("(" + *$1 + " | " + *$3 + ")");
      delete $1; delete $3;
  }
  ;

arith_expr
  : term { $$ = $1; }
  | arith_expr PLUS term
  {
      $$ = new std::string("(" + *$1 + " + " + *$3 + ")");
      delete $1; delete $3;
  }
  | arith_expr MINUS term
  {
      $$ = new std::string("(" + *$1 + " - " + *$3 + ")");
      delete $1; delete $3;
  }
  ;

term
  : factor { $$ = $1; }
  | term TIMES factor
  {
      $$ = new std::string("(" + *$1 + " * " + *$3 + ")");
      delete $1; delete $3;
  }
  | term DIVIDEDBY factor
  {
      $$ = new std::string("(" + *$1 + " / " + *$3 + ")");
      delete $1; delete $3;
  }
  | term MOD factor
  {
      $$ = new std::string("(" + *$1 + " % " + *$3 + ")");
      delete $1; delete $3;
  }
  | term '&' factor  // AND bitwise
  {
      $$ = new std::string("(" + *$1 + " & " + *$3 + ")");
      delete $1; delete $3;
  }
  | term "<<" factor  // Shift left
  {
      $$ = new std::string("(" + *$1 + " << " + *$3 + ")");
      delete $1; delete $3;
  }
  | term ">>" factor  // Shift right
  {
      $$ = new std::string("(" + *$1 + " >> " + *$3 + ")");
      delete $1; delete $3;
  }
  | term "//" factor
  {
      $$ = new std::string("Math.floor(" + *$1 + " / " + *$3 + ")");
      delete $1; delete $3;
  }
  ;

factor
  : PLUS factor { $$ = $2; }
  | MINUS factor %prec UMINUS
  {
      $$ = new std::string("-(" + *$2 + ")");
      delete $2;
  }
  | power { $$ = $1; }
  ;

power
  : atom_expr { $$ = $1; }
  | atom_expr POW factor
  {
      $$ = new std::string("(" + *$1 + " ** " + *$3 + ")");
      delete $1; delete $3;
  }
  ;

atom_expr
  : atom { $$ = $1; }
  | atom trailer { 
      $$ = new std::string(*$1 + *$2); 
      delete $1; delete $2;
  }
  ;

atom
  : IDENTIFIER { 
      $$ = $1;
  }
  | INTEGER { $$ = $1; }
  | FLOAT { $$ = $1; }
  | STRING { $$ = $1; }
  | BOOLEAN { $$ = new std::string($1 ? "true" : "false"); }
  | NONE { $$ = new std::string("null"); }
  | list { $$ = $1; }
  | LPAREN expr RPAREN { $$ = new std::string("(" + *$2 + ")"); delete $2; }
  ;

list
  : LBRACK testlist RBRACK 
  { 
      $$ = new std::string("[" + *$2 + "]"); 
      delete $2;
  }
  ;

testlist
  : /* vacío */ { $$ = new std::string(""); }
  | test { $$ = $1; }
  | testlist COMMA test 
  { 
      $$ = new std::string(*$1 + ", " + *$3); 
      delete $1; delete $3;
  }
  ;

trailer
  : '(' ')' { $$ = new std::string("()"); }
  | '(' arglist ')' { $$ = new std::string("(" + *$2 + ")"); delete $2; }
  | '[' subscriptlist ']' { $$ = new std::string("[" + *$2 + "]"); delete $2; }
  | '.' IDENTIFIER { $$ = new std::string("." + *$2); delete $2; }
  ;

subscriptlist
  : subscript { $$ = $1; }
  | subscriptlist ',' subscript { 
      $$ = new std::string(*$1 + ", " + *$3); 
      delete $1; delete $3;
  }
  ;

subscript
  : test { $$ = $1; }
  | ':' test { $$ = new std::string(":" + *$2); delete $2; }
  | test ':' test { 
      $$ = new std::string(*$1 + ":" + *$3); 
      delete $1; delete $3;
  }
  | test ':' test sliceop {
      $$ = new std::string(*$1 + ":" + *$3 + *$4); 
      delete $1; delete $3; delete $4;
  }
  ;

sliceop
  : ':' { $$ = new std::string(":"); }
  | ':' test { $$ = new std::string(":" + *$2); delete $2; }
  ;

argument
  : test { $$ = $1; }
  | test '=' test { 
      $$ = new std::string(*$1 + " = " + *$3); 
      delete $1; delete $3;
  }
  ;

arglist
  : argument { $$ = new std::string(*$1);
                delete $1;}
  | arglist COMMA argument { $$ = new std::string(*$1 + ", " + *$3);
                delete $1; delete $3;}
  ;
%%


