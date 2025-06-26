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
%token <token> PRINT UNKNOWN


%type <str> expression statement list elements expression_for parameter_list argument_list argument
%type <str> conditional conditionalExpr ifelse
%type <str> flowcontrol program

%left PLUS MINUS 
%left TIMES DIVIDEDBY

%start goal

%%

goal
  : program { }

program
  : program statement {$$ = new std::string(*$1 + *$2);
                      goalStr = new std::string(*$$);
                      delete $1; delete $2; 
                       }
  | statement { $$ = new std::string(*$1); delete $1; }
  ;

statement
  : conditional {$$ = new std::string(*$1); delete $1;}
  | DEDENT conditional statement DEDENT DEDENT { $$ = new std::string("} " + *$2 + "\n" + *$3 + "}\n}\n"); delete $2; delete $3; }
  | DEDENT conditional statement DEDENT { $$ = new std::string("} " + *$2 + "\n" + *$3 + "}\n"); delete $2; delete $3; }
  | DEDENT { $$ = new std::string("}\n"); }
  | INDENT statement {$$ = new std::string("\t" + *$2); delete $2; }
  /*| INDENT statement INDENT statement { std::cerr << "Error:"<< "Indentation error"<< std::endl; exit(1); delete $2; delete $4; }*/
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
                ss << "let " << *$1 << " = " << *$3 << ";\n";
                $$ = new std::string(ss.str());
            }else if(type == "lista" && tipo_actual2 == 1){ // ES UN ARRAY INT
                ss << "let " << *$1 << " = " << *$3 << ";\n";
                $$ = new std::string(ss.str());
            }else if(type == "lista" && tipo_actual2 == 2){ // ES UN ARRAY FLOAT
                ss << "float " << *$1 << "[] = " << *$3 << ";\n";
                $$ = new std::string(ss.str());
            }
            else if(type == "lista" && tipo_actual2 == 3){ // ES UN CHARACTER ARRAY
                ss << "let " << *$1 << " = " << *$3 << ";\n";
                $$ = new std::string(ss.str());
            }
            else{
                ss << "let " << *$1 << " = " << *$3 << ";\n";
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
                ss << "const " << *$1 << " = " << *$3 << ";\n";
                $$ = new std::string(ss.str());
                // Agrega el identificador a la tabla de símbolos con su tipo
                symbol_table[*$1] = type;
            }else if(tipo_actual2 == 2){ 
                type = "const float";
                ss << "const " << *$1 << " = " << *$3 << ";\n";
                $$ = new std::string(ss.str());
                // Agrega el identificador a la tabla de símbolos con su tipo
                symbol_table[*$1] = type;
            }
            else if(tipo_actual2 == 3){ 
                type = "const char";
                ss << "const " << *$1 << " = " << *$3 << ";\n";
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
        $$ = new std::string("for (let " + *$2 + " = 0; " + *$2 + " < " + *$6 + "; " + *$2 + "++) {\n");
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
            printFormat = "console.log(" + expressionStr + ");\n";
            //std::cerr << "Entro a es un string\n";   
        } else if (tipo_actual == 6) { // Es un IDENTIFIER
              //std::cerr << "Entro a es un ID \n";           
            if (symbol_table.find(expressionStr) != symbol_table.end()) {
                std::string type = symbol_table[expressionStr];
                if (type == "int" || type == "const int") {
                    printFormat = "console.log(\"%d\", " + expressionStr + ");\n";
                } else if (type == "float") {
                    printFormat = "console.log(\"%f\", " + expressionStr + ");\n";
                } else if (type == "double") {
                    printFormat = "console.log(\"%lf\", " + expressionStr + ");\n";
                }else{
                  std::cerr << "WARNING: No se puede imprimir la variable \"" << expressionStr << "\"." << ". En linea: " << yylineno << std::endl;
                  printFormat = "// console.log(\"%?\", " + expressionStr + "); // Print no valido en C, revisar si afecta el flujo \n";
                }
            } else {
                std::cerr << "WARNING: Variable " << expressionStr << " no encontrada en la tabla de símbolos." << ". En linea: " << yylineno << std::endl;
                printFormat = "// console.log(\"%?\", " + expressionStr + "); // Print no valido en C, revisar si afecta el flujo \n";
            }
        } else {
                  std::cerr << "WARNING: No se puede imprimir la variable \"" << expressionStr << "\"." << ". En linea: " << yylineno << std::endl;
                  printFormat = "// console.log(\"%?\", " + expressionStr + "); // Print no valido en C, revisar si afecta el flujo \n";
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
  : /* empty */ { $$ = new std::string(""); }
  | IDENTIFIER { $$ = new std::string("int " + *$1); delete $1; }
  | parameter_list COMMA IDENTIFIER {
      $$ = new std::string(*$1 + ", int " + *$3);
      delete $1; delete $3;
    }
  ;
argument_list
  : /* empty */
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

%%

void yyerror(YYLTYPE* loc, const char* err) {
  std::cerr << "Error de sintaxis en la línea "  << yylineno << std::endl;
  //exit(1);
}