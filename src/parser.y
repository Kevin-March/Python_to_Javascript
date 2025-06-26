%{
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "symbol_table.hpp"

// Variables globales
SymbolTable symTable;
TypeChecker typeChecker(symTable);
int currentScope = 0;
std::stringstream jsCode;  // Acumula el código JavaScript generado

// Prototipos
void yyerror(const char *s);
std::string translateExpression(const std::string& pyExpr);
%}

%union {
    std::string* str;
    int int_val;
    double float_val;
    bool bool_val;
}

%token INDENT DEDENT NEWLINE
%token IF ELIF ELSE FOR WHILE BREAK CONTINUE
%token DEF RETURN PRINT
%token AND OR NOT
%token EQ NEQ LT GT LTE GTE
%token PLUS MINUS MULT DIV MOD
%token LBRACK RBRACK LPAREN RPAREN COMMA COLON
%token INTEGER FLOAT STRING BOOLEAN IDENTIFIER
%token VAR CONST TYPE_INT TYPE_FLOAT TYPE_STR TYPE_BOOL TYPE_ARRAY

%type <str> expression term factor comparison logical_expr
%type <str> var_declaration function_call array_literal
%type <str> if_statement for_loop while_loop function_def

%start program

%%

program:
    /* vacío */
    | program statement
    ;

statement:
      var_declaration
    | function_def
    | if_statement
    | for_loop
    | while_loop
    | expression NEWLINE { jsCode << $1 << ";\n"; }
    | RETURN expression NEWLINE { jsCode << "return " << $2 << ";\n"; }
    ;

var_declaration:
    IDENTIFIER '=' expression NEWLINE {
        if (!symTable.exists(*$1)) {
            symTable.addSymbol(*$1, "auto");
        }
        jsCode << "let " << *$1 << " = " << $3 << ";\n";
    }
    ;

function_def:
    DEF IDENTIFIER '(' params ')' ':' NEWLINE INDENT function_body DEDENT {
        jsCode << "function " << *$2 << "(" << $4 << ") {\n" << $8 << "}\n";
    }
    ;

params:
    /* vacío */ { $$ = ""; }
    | IDENTIFIER { $$ = *$1; symTable.addSymbol(*$1, "param"); }
    | params COMMA IDENTIFIER { $$ = $1 + ", " + *$3; symTable.addSymbol(*$3, "param"); }
    ;

function_body:
    statement
    | function_body statement
    ;

if_statement:
    IF expression ':' NEWLINE INDENT block DEDENT {
        jsCode << "if (" << $2 << ") {\n" << $6 << "}\n";
    }
    | IF expression ':' NEWLINE INDENT block DEDENT else_clause {
        jsCode << "if (" << $2 << ") {\n" << $6 << "} " << $8 << "\n";
    }
    ;

else_clause:
    ELSE ':' NEWLINE INDENT block DEDENT {
        $$ = "else {\n" + $5 + "}";
    }
    | ELIF expression ':' NEWLINE INDENT block DEDENT else_clause {
        $$ = "else if (" + $2 + ") {\n" + $6 + "} " + $8;
    }
    ;

for_loop:
    FOR IDENTIFIER IN IDENTIFIER ':' NEWLINE INDENT block DEDENT {
        jsCode << "for (let " << *$2 << " of " << *$4 << ") {\n" << $8 << "}\n";
    }
    | FOR IDENTIFIER IN RANGE '(' INTEGER ')' ':' NEWLINE INDENT block DEDENT {
        jsCode << "for (let " << *$2 << " = 0; " << *$2 << " < " << $6 << "; " 
               << *$2 << "++) {\n" << $11 << "}\n";
    }
    ;

while_loop:
    WHILE expression ':' NEWLINE INDENT block DEDENT {
        jsCode << "while (" << $2 << ") {\n" << $6 << "}\n";
    }
    ;

block:
    statement
    | block statement
    ;

expression:
    term { $$ = $1; }
    | expression PLUS term { $$ = $1 + " + " + $3; }
    | expression MINUS term { $$ = $1 + " - " + $3; }
    ;

term:
    factor { $$ = $1; }
    | term MULT factor { $$ = $1 + " * " + $3; }
    | term DIV factor { $$ = $1 + " / " + $3; }
    | term MOD factor { $$ = $1 + " % " + $3; }
    ;

factor:
    INTEGER { $$ = std::to_string($1); }
    | FLOAT { $$ = std::to_string($1); }
    | STRING { $$ = *$1; }
    | BOOLEAN { $$ = (*$1 == "True") ? "true" : "false"; }
    | IDENTIFIER { $$ = *$1; }
    | array_literal
    | function_call
    | '(' expression ')' { $$ = "(" + $2 + ")"; }
    ;

array_literal:
    LBRACK elements RBRACK { $$ = "[" + $2 + "]"; }
    ;

elements:
    /* vacío */ { $$ = ""; }
    | expression { $$ = $1; }
    | elements COMMA expression { $$ = $1 + ", " + $3; }
    ;

function_call:
    IDENTIFIER '(' arguments ')' { $$ = *$1 + "(" + $3 + ")"; }
    | PRINT '(' arguments ')' { $$ = "console.log(" + $3 + ")"; }
    ;

arguments:
    /* vacío */ { $$ = ""; }
    | expression { $$ = $1; }
    | arguments COMMA expression { $$ = $1 + ", " + $3; }
    ;

comparison:
    expression EQ expression { $$ = $1 + " === " + $3; }
    | expression NEQ expression { $$ = $1 + " !== " + $3; }
    | expression LT expression { $$ = $1 + " < " + $3; }
    | expression GT expression { $$ = $1 + " > " + $3; }
    | expression LTE expression { $$ = $1 + " <= " + $3; }
    | expression GTE expression { $$ = $1 + " >= " + $3; }
    ;

logical_expr:
    comparison { $$ = $1; }
    | logical_expr AND logical_expr { $$ = $1 + " && " + $3; }
    | logical_expr OR logical_expr { $$ = $1 + " || " + $3; }
    | NOT logical_expr { $$ = "!" + $2; }
    ;

%%

void yyerror(const char *s) {
    std::cerr << "Error de sintaxis: " << s << " en la línea " << yylineno << std::endl;
}

std::string translateExpression(const std::string& pyExpr) {
    // Conversiones específicas Python→JS
    if (pyExpr == "True") return "true";
    if (pyExpr == "False") return "false";
    if (pyExpr == "None") return "null";
    return pyExpr;
}

int main() {
    yyparse();
    std::cout << "// Código generado:\n";
    std::cout << jsCode.str();
    return 0;
}