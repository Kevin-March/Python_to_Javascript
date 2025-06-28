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
%type <str> print_stmt
%type <str> func_call
%type <str> id_declared

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
  : /* empty */ { std::cout << "[stmt_list_opt] vacío" << std::endl; $$ = new std::string(""); }
  | stmt_list_opt stmt {  std::cout << "[stmt_list_opt] agregando stmt" << std::endl;
                          $$ = new std::string(*$1 + "\n"+ *$2);
                                    delete $1; delete $2; }
  ;

stmt
  : simple_stmt
  | compound_stmt
  | NEWLINE { $$ = new std::string(""); }
  | print_stmt { 
      std::cout << "[stmt] print suelto\n";
      $$ = new std::string(*$1 + ";\n");
      delete $1;
    }
  | func_call NEWLINE {
      std::cout << "[stmt] llamada de función suelta: " << *$1 << std::endl;
      $$ = new std::string(*$1 + ";");
      delete $1;
    }
  ;

simple_stmt
  : small_stmt_list NEWLINE { $$ = new std::string(*$1 + "\n");
                              delete $1; }
  | small_stmt_list { $$ = new std::string(*$1 + ";");
                              delete $1; }
  | print_stmt
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
  | print_stmt
  ; 
print_stmt
  : PRINT LPAREN arglist RPAREN {
        $$ = new std::string("console.log(" + *$3 + ")");
        delete $3;
    }
  ;
expr_stmt
  : IDENTIFIER EQUALS test
      {
        std::cout << "[expr_stmt] Asignación a variable: " << *$1 << std::endl;
        if (symbol_table[current_scope.back()].count(*$1) == 0) {
            // no estaba declarada
            std::cout << "  Variable NO declarada previamente. Declarando...\n";
            symbol_table[current_scope.back()][*$1] = "variable";
            $$ = new std::string("let " + *$1 + " = " + *$3 + ";");
        } else {
            // ya estaba declarada
            std::cout << "  Variable ya declarada. Asignando valor.\n";
            $$ = new std::string(*$1 + " = " + *$3);
        }
        delete $1;
        delete $3;
      }
  | IDENTIFIER annasign EQUALS test
      {
         std::cout << "[expr_stmt] Asignación con anotación a variable: " << *$1 << std::endl;
         if (symbol_table[current_scope.back()].count(*$1) == 0) {
            // no estaba declarada
            std::cout << "  Variable NO declarada previamente. Declarando...\n";
            symbol_table[current_scope.back()][*$1] = "variable";
            $$ = new std::string("let " + *$1 + " = " + *$4 + ";");
        } else {
            // ya estaba declarada
            std::cout << "  Variable ya declarada. Asignando valor.\n";
            $$ = new std::string(*$1 + " = " + *$4);
        }
        delete $1; delete $4;
      }
  | IDENTIFIER augassign test
      {
        std::cout << "[expr_stmt] variable augassign test: " << *$1 << std::endl;
        if (symbol_table[current_scope.back()].count(*$1) == 0) {
            // no estaba declarada
            std::cout << "  Variable NO declarada previamente. Declarando...\n";
            symbol_table[current_scope.back()][*$1] = "variable";
            $$ = new std::string("let " + *$1 + " = " + *$3 + ";");
        } else {
            // ya estaba declarada
            std::cout << "  Variable ya declarada. Asignando valor.\n";
            $$ = new std::string(*$1 + " = " + *$3);
        }
        delete $1;
        delete $3;
      }
  | atom_expr  
      {
        std::cout << "[expr_stmt] llamada de función o atom_expr" << std::endl;
        $$ = new std::string(*$1 + ";");
        delete $1;
      }
  | test
      {
        std::cout << "[expr_stmt] expresión simple" << std::endl;
        // forzamos punto y coma siempre
        $$ = new std::string(*$1 + ";");
        delete $1;
      }
  ;

annasign
  : COLON test {std::cout << "[annasign] Declaración de tipo ignorada en JS" << std::endl; delete $2; } // Declaración de tipo que no se utiliza en JS
  ;

augassign
  : PLUS EQUALS {std::cout << "[augassign] Operador += detectado" << std::endl; $$ = new std::string("+=");}
  | MINUS EQUALS {std::cout << "[augassign] Operador -= detectado" << std::endl; $$ = new std::string("-=");}
  | TIMES EQUALS { std::cout << "[augassign] Operador *= detectado" << std::endl; $$ = new std::string("*=");}
  | DIVIDEDBY EQUALS { std::cout << "[augassign] Operador /= detectado" << std::endl; $$ = new std::string("/=");}
  ;

flow_stmt
  : BREAK { std::cout << "[flow_stmt] break detectado" << std::endl; $$ = new std::string("break"); }
  | RETURN test { std::cout << "[flow_stmt] return con expresión detectado" << std::endl; $$ = new std::string("return" + *$2);
                  delete $2; }
  | RETURN { std::cout << "[flow_stmt] return sin expresión detectado" << std::endl; $$ = new std::string("return"); }
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
        std::cout << "[if_stmt] if detectado con condición: " << *$2 << std::endl;
        std::stringstream ss;
        ss << "if (" << *$2 << ") {\n" << *$5 << "}\n";

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
  : /* empty */ { $$ = new std::string(""); }
  | elif_clauses ELIF test COLON NEWLINE suite
      {
        std::cout << "[elif_clauses] elif detectado con condición: " << *$3 << std::endl;
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
  : /* empty */ { $$ = new std::string(""); }
  | ELSE COLON NEWLINE suite { std::cout << "[else_clause_opt] else detectado" << std::endl; $$ = new std::string("else {\n" + *$4 + "}\n"); delete $4; }
  ;

suite
  : simple_stmt 
  | NEWLINE INDENT stmt_list DEDENT {
    std::cout << "[suite] suite con bloque indentado" << std::endl;

    if (!$3) {
        yyerror("stmt_list nulo dentro de suite");
        $$ = new std::string("\t// suite vacío forzado\n");
    } else {
        std::string indented;
        std::stringstream ss(*$3);
        std::string line;
        while (std::getline(ss, line)) {
            if (!line.empty())
                indented += "\t" + line + "\n";
        }
        if (indented.empty()) indented = "\t// suite vacío\n";
        $$ = new std::string(indented);
        delete $3;
    }
  }
stmt_list
  : stmt
  | stmt_list stmt { std::cout << "[stmt_list] stmt_list + stmt" << std::endl; $$ = new std::string(*$1 + "\n" + *$2); 
                     delete $1; delete $2; }
  ;

while_stmt
  : WHILE test COLON suite 
      {
        std::cout << "[while_stmt] while detectado con condición: " << *$2 << std::endl;
        std::stringstream ss;

        // generar el while
        ss << "while (" << *$2 << ") {\n" << *$4 << "}\n";

        $$ = new std::string(ss.str());
        delete $2;
        delete $4;
      }
  ;
for_stmt
  : FOR id_declared IN test COLON suite
      {
        // esto es para "for x in lista"
        symbol_table["global"][*$2] = "variable";
        std::cout << "[for_stmt] for-of detectado, iterando variable: " << *$2 << std::endl;
        std::stringstream ss;
        ss << "for (let " << *$2 << " of " << *$4 << ") {\n"
           << *$6 << "}\n";
        $$ = new std::string(ss.str());
        delete $2; delete $4; delete $6;
      }
  | FOR id_declared IN RANGE LPAREN testlist RPAREN COLON suite
      {
        // esto es para "for x in range(n)"
        symbol_table["global"][*$2] = "variable";
        std::cout << "[for_stmt] for-range detectado, variable: " << *$2 << std::endl;
        std::stringstream ss;
        ss << "for (let " << *$2 << " = 0; "
           << *$2 << " < " << *$6 << "; " << *$2 << "++) {\n"
           << *$9 << "}\n";
        $$ = new std::string(ss.str());
        delete $2; delete $6; delete $9;
      }
  ;
  id_declared
  : IDENTIFIER
    {
      symbol_table["global"][*$1] = "variable";
      std::cout << "[id_declared] variable de for detectada y declarada: " << *$1 << std::endl;
      $$ = $1;
    }
funcdef
  : DEF IDENTIFIER parameters return_type_opt COLON suite
      {
        std::cout << "[funcdef] función detectada: " << *$2 << std::endl;
        symbol_table[current_scope.back()][*$2] = "function";
        std::cout << "[funcdef] se guardo la funcion detectada: " << symbol_table[current_scope.back()][*$2] << std::endl;
        std::stringstream ss;

        // función en JavaScript con parámetros
        ss << "function " << *$2 <<*$3 << " {\n" << *$6 << "}\n\n"<<*$2<<"()\n";

        // en JS no hay anotaciones de tipo de retorno, así que ignoramos $4
        $$ = new std::string(ss.str());
        
        delete $2; delete $3; delete $4; delete $6;
      }
  ;
parameters
  : LPAREN RPAREN { std::cout << "[parameters] sin parámetros" << std::endl; $$ = new std::string("()"); }
  | LPAREN parameter_list RPAREN
      {
        std::cout << "[parameters] lista de parámetros" << std::endl;
        $$ = new std::string("(" + *$2 + ")");
        delete $2;
      }
  ;

parameter_list
  : IDENTIFIER { $$ = $1; }
  | parameter_list COMMA IDENTIFIER
      {
        std::cout << "[parameter_list] Parámetro agregado: " << *$3 << std::endl;
        $$ = new std::string(*$1 + ", " + *$3);
        delete $1; delete $3;
      }
  ;

return_type_opt
  : /* empty */ { /*En JavaScript no hay tipado de retorno, por eso solo parseamos, pero no lo incluimos en la salida. */ $$ = new std::string(""); }
  | ARROW test { std::cout << "[return_type_opt] Tipo de retorno encontrado" << std::endl; $$ = $2; }
  ;

test
  : or_test { std::cout << "[test] or_test evaluado" << std::endl; $$ = $1; }
  | or_test IF or_test ELSE test
  {
      std::cout << "[test] expresión condicional ternaria detectada" << std::endl;
      $$ = new std::string("(" + *$3 + " ? " + *$1 + " : " + *$5 + ")");
      delete $1; delete $3; delete $5;
  }
  ;

or_test
  : and_test { std::cout << "[or_test] and_test evaluado" << std::endl; $$ = $1; }
  | or_test OR and_test
  {
      std::cout << "[or_test] OR lógico detectado" << std::endl;
      $$ = new std::string("(" + *$1 + " || " + *$3 + ")");
      delete $1; delete $3;
  }
  ;

and_test
  : not_test {  std::cout << "[and_test] not_test evaluado" << std::endl; $$ = $1; }
  | and_test AND not_test
  {
      std::cout << "[and_test] AND lógico detectado" << std::endl;
      $$ = new std::string("(" + *$1 + " && " + *$3 + ")");
      delete $1; delete $3;
  }
  ;

not_test
  : NOT not_test
  {
      std::cout << "[not_test] NOT lógico detectado" << std::endl;
      $$ = new std::string("!(" + *$2 + ")");
      delete $2;
  }
  | comparison { std::cout << "[not_test] comparison evaluado" << std::endl; $$ = $1; }
  ;

comparison
  : expr { std::cout << "[comparison] expr evaluado" << std::endl; $$ = $1; }
  | comparison comp_op expr
  {
      std::cout << "[comparison] comparación con operador detectada" << std::endl;
      $$ = new std::string("(" + *$1 + " " + *$2 + " " + *$3 + ")");
      delete $1; delete $2; delete $3;
  }
  | comparison IN expr  // Manejo especial para 'in'
  {
      // JS: arrays → includes(), objetos → in
      std::cout << "[comparison] operador IN detectado" << std::endl;
      $$ = new std::string("(Array.isArray(" + *$3 + ") ? " + 
                            *$3 + ".includes(" + *$1 + ") : " +
                            "(" + *$1 + " in " + *$3 + "))");
      delete $1; delete $3;
  }
  ;

comp_op
  : EQ { std::cout << "[comp_op] Operador ===" << std::endl; $$ = new std::string("==="); }
  | NEQ { std::cout << "[comp_op] Operador !==" << std::endl; $$ = new std::string("!=="); }
  | LT { std::cout << "[comp_op] Operador <" << std::endl; $$ = new std::string("<"); }
  | GT { std::cout << "[comp_op] Operador >" << std::endl; $$ = new std::string(">"); }
  | LTE { std::cout << "[comp_op] Operador <=" << std::endl; $$ = new std::string("<="); }
  | GTE { std::cout << "[comp_op] Operador >=" << std::endl; $$ = new std::string(">="); }
  ;

expr
  : arith_expr {std::cout << "[expr] arith_expr evaluado" << std::endl; $$ = $1; }
  | expr '|' expr  // Bitwise OR (JS compatible)
  {
      std::cout << "[expr] Bitwise OR detectado" << std::endl;
      $$ = new std::string("(" + *$1 + " | " + *$3 + ")");
      delete $1; delete $3;
  }
  ;

arith_expr
  : term { std::cout << "[arith_expr] term evaluado" << std::endl; $$ = $1; }
  | arith_expr PLUS term
  {
      std::cout << "[arith_expr] Suma detectada" << std::endl;
      $$ = new std::string("(" + *$1 + " + " + *$3 + ")");
      delete $1; delete $3;
  }
  | arith_expr MINUS term
  {
      std::cout << "[arith_expr] Resta detectada" << std::endl;
      $$ = new std::string("(" + *$1 + " - " + *$3 + ")");
      delete $1; delete $3;
  }
  ;

term
  : factor { std::cout << "[term] factor evaluado" << std::endl; $$ = $1; }
  | term TIMES factor
  {
      std::cout << "[term] Multiplicación detectada" << std::endl;
      $$ = new std::string("(" + *$1 + " * " + *$3 + ")");
      delete $1; delete $3;
  }
  | term DIVIDEDBY factor
  {
      std::cout << "[term] División detectada" << std::endl;
      $$ = new std::string("(" + *$1 + " / " + *$3 + ")");
      delete $1; delete $3;
  }
  | term MOD factor
  {
      std::cout << "[term] Módulo detectado" << std::endl;
      $$ = new std::string("(" + *$1 + " % " + *$3 + ")");
      delete $1; delete $3;
  }
  | term '&' factor  // AND bitwise
  {
      std::cout << "[term] AND bitwise detectado" << std::endl;
      $$ = new std::string("(" + *$1 + " & " + *$3 + ")");
      delete $1; delete $3;
  }
  | term "<<" factor  // Shift left
  {
      std::cout << "[term] Shift left detectado" << std::endl;
      $$ = new std::string("(" + *$1 + " << " + *$3 + ")");
      delete $1; delete $3;
  }
  | term ">>" factor  // Shift right
  {
      std::cout << "[term] Shift right detectado" << std::endl;
      $$ = new std::string("(" + *$1 + " >> " + *$3 + ")");
      delete $1; delete $3;
  }
  | term "//" factor
  {
      std::cout << "[term] División entera detectada" << std::endl;
      $$ = new std::string("Math.floor(" + *$1 + " / " + *$3 + ")");
      delete $1; delete $3;
  }
  ;

factor
  : PLUS factor { std::cout << "[factor] factor con signo positivo" << std::endl; $$ = $2; }
  | MINUS factor %prec UMINUS
  {
      std::cout << "[factor] factor con signo negativo" << std::endl;
      $$ = new std::string("-(" + *$2 + ")");
      delete $2;
  }
  | power { std::cout << "[factor] power evaluado" << std::endl; $$ = $1; }
  ;

power
  : atom_expr { std::cout << "[power] atom_expr evaluado" << std::endl; $$ = $1; }
  | atom_expr POW factor
  {
      std::cout << "[power] potenciación detectada" << std::endl;
      $$ = new std::string("(" + *$1 + " ** " + *$3 + ")");
      delete $1; delete $3;
  }
  ;

atom_expr
  : atom { std::cout << "atom_expr -> atom: " << *$1 << std::endl; $$ = $1; }
  | atom trailer {
      std::cout << "atom_expr -> atom trailer: " << *$1 << *$2 << std::endl;
      // detectar llamada a función (IDENTIFIER + ())
      if ($2 && *$2 == "()") {
        // validamos que sea función
        if (
          symbol_table[current_scope.back()][*$1] != "function" &&
          symbol_table["global"][*$1] != "function"
        ) {
          yyerror(("Se intenta llamar algo que no es función: " + *$1).c_str());
        }
        std::cout << "[atom_expr] llamada a función: " << *$1 << std::endl;
      } 
      $$ = new std::string(*$1 + *$2); 
      delete $1; delete $2;
  }
  ;

atom
  : func_call
  | IDENTIFIER {
      std::cout << "atom -> IDENTIFIER: " << *$1 << std::endl;
      if (
        symbol_table[current_scope.back()].count(*$1) == 0 &&
        symbol_table["global"].count(*$1) == 0
      ) {
        yyerror(("Variable no declarada: " + *$1).c_str());
      } 
      $$ = $1;
  }
  | INTEGER { std::cout << "atom -> INTEGER: " << *$1 << std::endl;$$ = $1; }
  | FLOAT { std::cout << "atom -> FLOAT: " << *$1 << std::endl;$$ = $1; }
  | STRING { std::cout << "atom -> STRING: " << *$1 << std::endl;$$ = $1; }
  | BOOLEAN {std::cout << "atom -> BOOLEAN: " << *$1 << std::endl;$$ = new std::string($1 ? "true" : "false"); }
  | NONE { std::cout << "atom -> NONE: " << std::endl; $$ = new std::string("null"); }
  | list { std::cout << "atom -> LIST: " << *$1 << std::endl; $$ = $1; }
  | LPAREN expr RPAREN { std::cout << "atom -> ( EXPR ): " << *$2 << std::endl; $$ = new std::string("(" + *$2 + ")"); delete $2; }
  ;
func_call:
    IDENTIFIER LPAREN arglist RPAREN 
    {
        std::cout << "func_call (args): " << *$1 << std::endl;
        // Verificar si es función
        if (symbol_table[current_scope.back()].find(*$1) == symbol_table[current_scope.back()].end() &&
            symbol_table["global"].find(*$1) == symbol_table["global"].end()) {
            yyerror(("Función no declarada: " + *$1).c_str());
        }
        $$ = new std::string(*$1 + "(" + *$3 + ")");
        delete $1; delete $3;
    }
    | IDENTIFIER LPAREN RPAREN
    {
      std::cout << "func_call (no args): " << *$1 << std::endl;
      // Verificar si es función
        if (symbol_table[current_scope.back()].find(*$1) == symbol_table[current_scope.back()].end() &&
            symbol_table["global"].find(*$1) == symbol_table["global"].end()) {
            yyerror(("Función no declarada: " + *$1).c_str());
        }
        $$ = new std::string(*$1 + "(" + ")");
        delete $1;
    }
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
  : '(' ')' { std::cout << "Entro a trailer por ()" << std::endl; $$ = new std::string("()"); }
  | '(' arglist ')' { std::cout << "Entro a trailer por (args)" << std::endl; $$ = new std::string("(" + *$2 + ")"); delete $2; }
  | '[' subscriptlist ']' { std::cout << "Entro a trailer por []" << std::endl; $$ = new std::string("[" + *$2 + "]"); delete $2; }
  | '.' IDENTIFIER { std::cout << "Entro a trailer por ." << std::endl; $$ = new std::string("." + *$2); delete $2; }
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


