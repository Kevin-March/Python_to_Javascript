%{
#include <iostream>
#include <map>
#include <algorithm> // Incluir para std::find
#include <cstring>
#include <sstream> // Para usar std::stringstream
#include <string>  // Para usar std::string

#include "parser.hpp"

std::map<std::string, std::string> symbol_table; // Tabla de símbolos
std::string* goalStr;
std::string* functionDeclarationsStr;


void yyerror(const char* err) {
  std::cerr << "Error de sintaxis: " << err << std::endl;
}
extern int yylex();
extern int yylineno;

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






%token <str> IDENTIFIER INTEGER TBOOLEAN FBOOLEAN FLOAT STRING CHAR DOUBLE CONSTANT
%token <token> EQUALS PLUS MINUS TIMES DIVIDEDBY
%token <token> EQ NEQ GT GTE LT LTE RETURN
%token <token> INDENT DEDENT NEWLINE IF COLON
%token <token> AND BREAK ELIF ELSE FOR IN RANGE NOT OR WHILE DEF
%token <token> SEMICOLON LPAREN RPAREN COMMA LBRACK RBRACK
%token <token> PRINT UNKNOWN ENDMARKER


%type <str> expression statement list elements expression_for parameter_list argument_list argument
%type <str> conditional conditionalExpr ifelse
%type <str> flowcontrol 

%type <str> program stmt_or_newline_list_opt stmt simple_stmt compound_stmt small_stmt_list_opt stmt_or_newline

%type <str> test or_test and_test not_test comparison comp_op expr
%type <str> arith_expr term factor power atom_expr atom
%type <str> list testlist subscriptlist trailer subscript sliceop exprlist dictorsetmaker classdef argument arglist

%left PLUS MINUS 
%left TIMES DIVIDEDBY

%start program

%%

program
  : stmt_or_newline_list_opt ENDMARKER { goalStr = new std::string(*$1); 
                              delete $1; }

stmt_or_newline_list_opt
  : /* empty */ { $$ = new std::string(""); }
  | stmt_or_newline_list_opt stmt_or_newline { $$ = new std::string(*$1 + "\n"+ *$2);
                                    delete $1; delete $2; }
  ;

stmt_or_newline
  : stmt  
  | NEWLINE
  ;

stmt
  : simple_stmt
  | compound_stmt
  | global_stmt
  ;

simple_stmt
  : small_stmt_list NEWLINE { $$ = new std::string($1 + ";")
                              delete $1; }
  ;


small_stmt_list
  : small_stmt_list SEMICOLON small_stmt { $$ = new std::string(*$1 + *$3);
                                           delete $1; delete $2; }
  | small_stmt SEMICOLON { $$ = $1 }
  | small_stmt
  ;

small_stmt
  : expr_stmt
  | flow_stmt
  ; 

// TODO agregar manejo de scope
// TODO especificar que solo se puede hacer una asignación (no se puede hacer a=b=c=3)
expr_stmt
  : test annasign { $$ = new std::string(*$1);              // No asigna
                    delete $1; }
  | test annasign EQUALS test { $$ = new std::string(*$1 + "=" + *$4);  // Asigna
                    delete $1; delete $4; }
  | test augassign test { $$ = new std::string(*$1 + *$2 + *$3);  // Asigna
                    delete $1; delete $2; delete $3;}
  | test EQUALS test { $$ = new std::string(*$1 + "=" + *$3);     // Asigna
                    delete $1; delete $3;}
  | test { $$ = new std::string("")}                              // No asigna
  ;

annasign
  : COLON test { delete $2; } // Declaración de tipo que no se utiliza en JS
  ;

augassign
  : PLUS EQUALS { $$ = new std::string("+=")}
  | MINUS EQUALS { $$ = new std::string("-=")}
  | TIMES EQUALS { $$ = new std::string("*=")}
  | DIVIDEBY EQUALS { $$ = new std::string("/=")}
  ;

flow_stmt
  : BREAK { $$ = new std::string("break"); }
  | RETURN test { $$ = new std::string("return" + $2);
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
        if ($6) {
          ss << *$6;
          delete $6;
        }

        // else
        if ($7) {
          ss << *$7;
          delete $7;
        }

        $$ = new std::string(ss.str());
        delete $2; delete $5;
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
  | NEWLINE INDENT stmt_list DEDENT

stmt_list
  : stmt
  | stmt_list stmt { $$ = new std::string($1 +$2); 
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
  | FOR IDENTIFIER IN RANGE LPAREN expression RPAREN COLON suite
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
    | IN  { $$ = new std::string(" in "); }
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
    | term DIV factor
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
    : atom { $$ = $1; }
    | power '**' factor
    {
        $$ = new std::string("(" + *$1 + " ** " + *$3 + ")");
        delete $1; delete $3;
    }
    ;

atom_expr
    : atom { $$ = $1; }
    | AWAIT atom { $$ = new std::string("await " + *$2); delete $2; }
    | atom trailer { 
        $$ = new std::string(*$1 + *$2); 
        delete $1; delete $2;
    }
    ;

atom
    : IDENTIFIER { 
        // Verificar existencia en tabla de símbolos
        if (symbol_table[current_scope.back()].find(*$1) == symbol_table[current_scope.back()].end()) {
            yyerror(("Variable no declarada: " + *$1).c_str());
        }
        $$ = $1;
    }
    | INTEGER { $$ = new std::string(std::to_string($1)); }
    | FLOAT { $$ = new std::string(std::to_string($1)); }
    | STRING { $$ = $1; }
    | BOOLEAN { $$ = new std::string($1 ? "true" : "false"); }
    | NONE { $$ = new std::string("null"); }
    | list { $$ = $1; }
    | func_call { $$ = $1; }
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
    | '.' NAME { $$ = new std::string("." + *$2); delete $2; }
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

exprlist
    : expr { $$ = $1; }
    | star_expr { $$ = $1; }
    | exprlist ',' expr { 
        $$ = new std::string(*$1 + ", " + *$3); 
        delete $1; delete $3;
    }
    ;

dictorsetmaker
    : test ':' test { $$ = new std::string(*$1 + ": " + *$3); delete $1; delete $3; }
    | test { $$ = $1; }
    | dictorsetmaker ',' test ':' test { 
        $$ = new std::string(*$1 + ", " + *$3 + ": " + *$5); 
        delete $1; delete $3; delete $5;
    }
    ;

classdef
    : 'class' NAME ':' suite {
        $$ = new std::string("class " + *$2 + " {\n" + *$4 + "}"); 
        delete $2; delete $4;
    }
    | 'class' NAME '(' arglist ')' ':' suite {
        $$ = new std::string("class " + *$2 + " extends " + *$4 + " {\n" + *$7 + "}"); 
        delete $2; delete $4; delete $7;
    }
    ;

argument
    : test { $$ = $1; }
    | test '=' test { 
        $$ = new std::string(*$1 + " = " + *$3); 
        delete $1; delete $3;
    }
    ;

arglist
    : /* vacío */ { $$ = new std::string(""); }
    | expr { $$ = $1; }
    | arglist COMMA expr { 
        $$ = new std::string(*$1 + ", " + *$3); 
        delete $1; delete $3;
    }
    ;


/* CODIGO OBSOLETO 
statement
  : conditional {$$ = new std::string(*$1); delete $1;}
  | DEDENT conditional statement DEDENT DEDENT { $$ = new std::string("} " + *$2 + "\n" + *$3 + "}\n}\n"); delete $2; delete $3; }
  | DEDENT conditional statement DEDENT { $$ = new std::string("} " + *$2 + "\n" + *$3 + "}\n"); delete $2; delete $3; }
  | DEDENT { $$ = new std::string("}\n"); }
  | INDENT statement {$$ = new std::string("\t" + *$2); delete $2; }
  /*| INDENT statement INDENT statement { std::cerr << "Error:"<< "Indentation error"<< std::endl; exit(1); delete $2; delete $4; }
  | INDENT flowcontrol NEWLINE DEDENT DEDENT{ $$ = new std::string("break; \n}\n}\n"); delete $2; }
  | IDENTIFIER EQUALS expression NEWLINE {
        //std::cerr << "Entro a ID EQUALS statement \n";
        // Si no existe el id, se genera una declaracion
        if (symbol_table.find(*$1) == symbol_table.end()) {
            // Determina el tipo del identificador
            std::string type;
            if (tipo_actual == 1 | tipo_actual == 6 ) type = "int";
            else if (tipo_actual == 2) type = "float";
            else if (tipo_actual == 3) type = "bool";
            else if (tipo_actual == 4) type = "char";
            else if (tipo_actual == 5) type = "lista";
            else if (tipo_actual == 7) type = "double";
            else {
                std::cerr << "Error: Tipo no reconocido para el identificador '" << *$1 << "'. En linea: " << yylineno << std::endl;
                exit(1);
            }
            // Agrega el identificador a la tabla de símbolos con su tipo
            symbol_table[*$1] = type;
            // Construye la cadena de asignación para el output.c
            std::stringstream ss;
            if (type == "char"){ // Es una cadena char str[] = "GeeksforGeeks";
                ss << type << " " << *$1 << "[] = " << *$3 << ";\n";
                $$ = new std::string(ss.str());
            }else if(type == "lista" && tipo_actual2 == 1){ // ES UN ARRAY INT
                ss << "int " << *$1 << "[] = " << *$3 << ";\n";
                $$ = new std::string(ss.str());
            }else if(type == "lista" && tipo_actual2 == 2){ // ES UN ARRAY FLOAT
                ss << "float " << *$1 << "[] = " << *$3 << ";\n";
                $$ = new std::string(ss.str());
            }
            else if(type == "lista" && tipo_actual2 == 3){ // ES UN CHARACTER ARRAY
                ss << "char " << *$1 << "[] = " << *$3 << ";\n";
                $$ = new std::string(ss.str());
            }
            else{
                ss << type << " " << *$1 << " = " << *$3 << ";\n";
                $$ = new std::string(ss.str());
            }

        } else { 
          // MANEJO DE ASIGNACIONES A VARIABLES DE DISTINTOS TIPOS

          // SI EL ID ES UN INT o UN FLOAT o un BOOL o un DOUBLE
          if(symbol_table[*$1] == "int" | symbol_table[*$1] == "float" | symbol_table[*$1] == "bool" | symbol_table[*$1] == "double" ){

              // Si la asignacion es a un INT, FLOAT, DOUBLE, BOOL (TRUE OR FALSE) --> la realizo sin prob
              if(tipo_actual == 1 | tipo_actual == 2 | tipo_actual == 7 | tipo_actual == 3){
                  $$ = new std::string(*$1 + " = " + *$3 + ";\n"); 
              }else if(tipo_actual == 6 && tipo_actual3 == 0){ // Si la asignacion es a otro IDENTIFIER
                  // Si la asignacion es a un INT, FLOAT, DOUBLE, BOOL (TRUE OR FALSE) --> la realizo sin prob
                  if(symbol_table[*$3] == "int" | symbol_table[*$3] == "float"| symbol_table[*$3] == "double"| symbol_table[*$3] == "bool"){
                    $$ = new std::string(*$1 + " = " + *$3 + ";\n"); }
                  else{
                    std::cerr << "WARNING: No se puede realizar la traduccion de esta asignacion en C"<< std::endl;
                    $$ = new std::string("// " + *$1 + " = " + *$3 + "; // Asignacion no valida en C, revisar si afecta el flujo \n");
                }
              }else if(tipo_actual3 == 1 && tipo_actual != 4 && tipo_actual != 9){ // asignaciones a operaciones de suma resta etc
                  $$ = new std::string(*$1 + " = " + *$3 + ";\n"); 
                  tipo_actual3 = 0;
              }
              else{ 
                  std::cerr << "WARNING: No se puede realizar la traduccion de esta asignacion en C"<< std::endl;
                  $$ = new std::string("// " + *$1 + " = " + *$3 + "; // Asignacion no valida en C, revisar si afecta el flujo \n");
              }

          }else{
              std::cerr << "WARNING: No se puede realizar la traduccion de esta asignacion en C"<< std::endl;
              $$ = new std::string("// " + *$1 + " = " + *$3 + "; // Asignacion no valida en C, revisar si afecta el flujo \n");
          }
        }
        tipo_actual = 0;
        tipo_actual2 = 0;
        // Limpia la memoria de los punteros utilizados
        delete $1; delete $3;
    }
    | CONSTANT EQUALS expression NEWLINE {
        // Si no existe el id, se genera una declaracion
        if (symbol_table.find(*$1) == symbol_table.end()) {
            // Determina el tipo de la constante
            std::string type;
            std::stringstream ss;
            if(tipo_actual2 == 1){ 
                type = "const int";
                ss << "const int " << *$1 << " = " << *$3 << ";\n";
                $$ = new std::string(ss.str());
                // Agrega el identificador a la tabla de símbolos con su tipo
                symbol_table[*$1] = type;
            }else if(tipo_actual2 == 2){ 
                type = "const float";
                ss << "const float " << *$1 << " = " << *$3 << ";\n";
                $$ = new std::string(ss.str());
                // Agrega el identificador a la tabla de símbolos con su tipo
                symbol_table[*$1] = type;
            }
            else if(tipo_actual2 == 3){ 
                type = "const char";
                ss << "const char " << *$1 << " = " << *$3 << ";\n";
                $$ = new std::string(ss.str());
                // Agrega el identificador a la tabla de símbolos con su tipo
                symbol_table[*$1] = type;
            }
            else{
              std::cerr << "Error: Asignacion no valida a constante " << *$1 << ". En linea: " << yylineno << std::endl;
            }
            delete $1; delete $3;
        }else{
          // Si existe no se puede modificar
          $$ = new std::string("// " + *$1 + " = " + *$3 + "; // Asignacion no valida en C, revisar si afecta el flujo \n");
          std::cerr << "Error: Modificacion no valida a constante " << *$1 << ". En linea: " << yylineno << std::endl;
          delete $1; delete $3;
        }
        tipo_actual = 0;
        tipo_actual2 = 0;
        // Limpia la memoria de los punteros utilizados
        
    }
    | FOR IDENTIFIER IN RANGE LPAREN expression_for RPAREN COLON NEWLINE{
      // realizar verificacion, si es_id == 1, entonces verificar que su tipo sea int en la tabla de simbolos, sino error
      // verificar si ya se declaro o no la variable
        $$ = new std::string("for (int " + *$2 + " = 0; " + *$2 + " <  " + *$6 + "; " + *$2 + "++) {\n"); 
        delete $2; delete $6;
        //std::cerr << "Entro a FIR statement \n";
    }
    | DEF IDENTIFIER LPAREN parameter_list RPAREN COLON NEWLINE {
      std::string funcName = *$2;
      //std::cerr << "Entro a DEF procedure \n";
      // Verificar si la función ya existe en la tabla de símbolos
      if (symbol_table.find(funcName) != symbol_table.end()) {
          std::cerr << "Error: La función '" << funcName << "' ya ha sido declarada. Línea: " << @2.first_line << std::endl;
          //YYERROR;
      } else {
          std::string funcDecl = "void " + funcName + "(" + *$4 + ");\n";
          
          // Guardar la función en la tabla de símbolos
          symbol_table[funcName] = "function";

          if (functionDeclarationsStr == nullptr) {
              functionDeclarationsStr = new std::string(funcDecl);
          } else {
              *functionDeclarationsStr += funcDecl;
          }
          $$ = new std::string("// Se deberia trasladar esta declaracion fuera del main \nvoid " + funcName + "(" + *$4 + ") {\n");
      }
      delete $2; delete $4;
    }
    | IDENTIFIER LPAREN argument_list RPAREN NEWLINE{
      std::string funcName = *$1;
      //std::cerr << "Entro a llamada Proc \n";
      //std::cerr << "argument list: " << *$3 << " \n";
      if (symbol_table.find(funcName) == symbol_table.end()) {
        std::cerr << "Error: La función '" << funcName << "' no ha sido declarada. Línea: " << @1.first_line << std::endl;
        YYERROR;
      } else {
        //std::cerr << "Entro a la escritura de la llamada \n";
        $$ = new std::string(*$1 + "(" + *$3 + ");\n");
      }
      delete $1; delete $3;
    }
    | PRINT LPAREN expression RPAREN NEWLINE{
        //std::cerr << "Entro a PRINT \n";      
        std::string printFormat;
        std::string expressionStr = *$3;
            
        if (tipo_actual == 4) { // Es un STRING
            printFormat = "printf(" + expressionStr + ");\n";
            //std::cerr << "Entro a es un string\n";   
        } else if (tipo_actual == 6) { // Es un IDENTIFIER
              //std::cerr << "Entro a es un ID \n";           
            if (symbol_table.find(expressionStr) != symbol_table.end()) {
                std::string type = symbol_table[expressionStr];
                if (type == "int" || type == "const int") {
                    printFormat = "printf(\"%d\", " + expressionStr + ");\n";
                } else if (type == "float") {
                    printFormat = "printf(\"%f\", " + expressionStr + ");\n";
                } else if (type == "double") {
                    printFormat = "printf(\"%lf\", " + expressionStr + ");\n";
                }else{
                  std::cerr << "WARNING: No se puede imprimir la variable \"" << expressionStr << "\"." << ". En linea: " << yylineno << std::endl;
                  printFormat = "// printf(\"%?\", " + expressionStr + "); // Print no valido en C, revisar si afecta el flujo \n";
                }
            } else {
                std::cerr << "WARNING: Variable " << expressionStr << " no encontrada en la tabla de símbolos." << ". En linea: " << yylineno << std::endl;
                printFormat = "// printf(\"%?\", " + expressionStr + "); // Print no valido en C, revisar si afecta el flujo \n";
            }
        } else {
                  std::cerr << "WARNING: No se puede imprimir la variable \"" << expressionStr << "\"." << ". En linea: " << yylineno << std::endl;
                  printFormat = "// printf(\"%?\", " + expressionStr + "); // Print no valido en C, revisar si afecta el flujo \n";
          }
        tipo_actual = 0;
        tipo_actual2 = 0;
        tipo_actual3 = 0;
        $$ = new std::string(printFormat);
        delete $3;
    }
    | UNKNOWN NEWLINE{
      std::cerr << "Error: Simbolo desconocido: " << $1 << ". En linea: " << yylineno << std::endl;
      std::cerr << "No se traslado a la traduccion " << std::endl;
    }
    | error NEWLINE
    {
      std::cerr << "Error de sintaxis en la línea " << ". En linea: " << yylineno << std::endl;
    }
  ;
  ;
 parameter_list
  : /* empty  { $$ = new std::string(""); }
  | IDENTIFIER { $$ = new std::string("int " + *$1); delete $1; }
  | parameter_list COMMA IDENTIFIER {
      $$ = new std::string(*$1 + ", int " + *$3);
      delete $1; delete $3;
    }
  ;
argument_list
  : /* empty 
    { $$ = new std::string(""); }
  | argument
    { $$ = $1; }
  | argument_list COMMA argument
    {
      $$ = new std::string(*$1 + ", " + *$3);
      delete $1; delete $3;
    }
  ;
argument:
    INTEGER { $$ = $1; }
  | FLOAT { $$ = $1; }
  | DOUBLE {  $$ = $1; }
  | TBOOLEAN { $$ = $1; }
  | FBOOLEAN { $$ = $1; }
  | IDENTIFIER
    {
      if (symbol_table.find(*$1) == symbol_table.end()) {
        std::cerr << "Error: La variable '" << *$1 << "' no ha sido declarada. Línea: " << @1.first_line << std::endl;
        YYERROR;
      } else {
        $$ = $1;
      }
    }
  ;
expression
  : INTEGER { tipo_actual = 1; tipo_actual2 = 1; $$ = $1; }
  | FLOAT { tipo_actual = 2; tipo_actual2 = 2; $$ = $1; }
  | DOUBLE { tipo_actual = 7; $$ = $1; }
  | TBOOLEAN { tipo_actual = 3; $$ = $1; }
  | FBOOLEAN { tipo_actual = 3; $$ = $1; }
  | IDENTIFIER {tipo_actual = 6;$$ = $1; }
  | CONSTANT {tipo_actual = 8;$$ = $1; }
  | STRING {  tipo_actual = 4; $$ = $1; }
  | CHAR {  tipo_actual = 9; tipo_actual2 = 3; $$ = $1; }
  | LPAREN expression RPAREN {  $$ = new std::string("(" + *$2 + ")"); delete $2;}
  | expression PLUS expression { tipo_actual3 = 1;$$ =  new std::string(*$1 + " + " + *$3); delete $1; delete $3;} 
  | expression MINUS expression { tipo_actual3 = 1;$$ =  new std::string(*$1 + " - " + *$3); delete $1; delete $3;} 
  | expression TIMES expression { tipo_actual3 = 1;$$ =  new std::string(*$1 + " * " + *$3); delete $1; delete $3;} 
  | expression DIVIDEDBY expression { tipo_actual3 = 1;$$ =  new std::string(*$1 + " / " + *$3); delete $1; delete $3;}  
  | list { tipo_actual = 5; $$ = $1; }                              
  ;
expression_for
  : INTEGER { $$ = $1; }
  | IDENTIFIER {es_id = 1; $$ = $1; }
  ;
list
  : LBRACK RBRACK { $$ = new std::string("[]"); }
  | LBRACK elements RBRACK { $$ = new std::string("{" + *$2 + "}"); delete $2; }
  ;
elements
  : expression { $$ = new std::string(*$1); delete $1; }
  | elements COMMA expression { $$ = new std::string(*$1 + ", " + *$3); delete $1; delete $3; }
  ;
conditionalExpr
  : IDENTIFIER { $$ = $1; }
  | INTEGER { $$ = $1; }
  | FLOAT { $$ = $1; }
  | TBOOLEAN { $$ = $1; }
  | FBOOLEAN { $$ = $1; }
  | STRING { $$ = $1; }
  | conditionalExpr LT conditionalExpr { $$ = new std::string(*$1 + " < " + *$3);  delete $1; delete $3;}
  | conditionalExpr GT conditionalExpr { 
                                        $$ = new std::string(*$1 + " > " + *$3);
                                        delete $1; delete $3;
                                      }
  | conditionalExpr LTE conditionalExpr {  $$ = new std::string(*$1 + " <= " + *$3); delete $1; delete $3;}
  | conditionalExpr GTE conditionalExpr {  $$ = new std::string(*$1 + " >= " + *$3); delete $1; delete $3;}
  | conditionalExpr NEQ conditionalExpr {  $$ = new std::string(*$1 + " != " + *$3); delete $1; delete $3;}
  | conditionalExpr EQ conditionalExpr {  $$ = new std::string(*$1 + " == " + *$3); delete $1; delete $3;}
  | AND conditionalExpr {  $$ = new std::string(" && " + *$2 ); delete $2;}
  ;

conditional
  : ifelse
  | WHILE conditionalExpr COLON NEWLINE { $$ = new std::string("while (" + *$2 + ") {\n"); delete $2;}
  ;

ifelse
  : IF conditionalExpr COLON NEWLINE {  $$ = new std::string("if(" + *$2 + ") {\n"); delete $2;}
  | ELSE COLON NEWLINE { $$ = new std::string("else {\n");};
  | ELIF conditionalExpr COLON NEWLINE {  $$ = new std::string("else if(" + *$2 + ") {"); delete $2;}
  ;

flowcontrol
  : BREAK { $$ = new std::string("break"); }
  ;
*/
%%

void yyerror(YYLTYPE* loc, const char* err) {
  std::cerr << "Error de sintaxis en la línea "  << yylineno << std::endl;
  //exit(1);
}
