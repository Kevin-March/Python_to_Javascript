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
%token IN RANGE

%token <str> IDENTIFIER STRING
%token <int_val> INTEGER
%token <float_val> FLOAT
%token <bool_val> BOOLEAN
%token VAR CONST TYPE_INT TYPE_FLOAT TYPE_STR TYPE_BOOL TYPE_ARRAY

%type <str> program statement function_body block
%type <str> var_declaration function_def params
%type <str> if_statement else_clause for_loop while_loop
%type <str> expression term factor array_literal elements
%type <str> function_call arguments comparison logical_expr

%start program

%%

program:
    /* vacío */ { $$ = new std::string(""); }
    | program statement { $$ = new std::string(*$1 + *$2); delete $1; delete $2; }
    ;

statement:
      var_declaration { $$ = $1; }
    | function_def { $$ = $1; }
    | if_statement { $$ = $1; }
    | for_loop { $$ = $1; }
    | while_loop { $$ = $1; }
    | expression NEWLINE {
        jsCode << *$1 << ";\n";
        $$ = new std::string(*$1 + ";\n");
        delete $1;
    }
    | RETURN expression NEWLINE {
        jsCode << "return " << *$2 << ";\n";
        $$ = new std::string("return " + *$2 + ";\n");
        delete $2;
    }

var_declaration:
    IDENTIFIER '=' expression NEWLINE {
        if (!symTable.exists(*$1)) {
            symTable.addSymbol(*$1, "auto");
        }
        $$ = new std::string("let " + *$1 + " = " + *$3 + ";\n");
        jsCode << *$$;
        delete $1;
        delete $3;
    }
    ;

function_def:
    DEF IDENTIFIER '(' params ')' ':' NEWLINE INDENT function_body DEDENT {
        $$ = new std::string("function " + *$2 + "(" + *$4 + ") {\n" + *$9 + "}\n");
        jsCode << *$$;
        delete $2;
        delete $4;
        delete $9;
    }


function_body:
    statement { $$ = new std::string(*$1); delete $1; }
    | function_body statement { $$ = new std::string(*$1 + *$2); delete $1; delete $2; }
    ;

params:
    /* vacío */ { $$ = new std::string(""); }
    | IDENTIFIER { 
        $$ = new std::string(*$1);
        symTable.addSymbol(*$1, "param");
        delete $1;
      }
    | params COMMA IDENTIFIER { 
        $$ = new std::string(*$1 + ", " + *$3);
        symTable.addSymbol(*$3, "param");
        delete $1;
        delete $3;
      }
    ;


if_statement:
    IF expression ':' NEWLINE INDENT block DEDENT {
        $$ = new std::string("if (" + *$2 + ") {\n" + *$6 + "}\n");
        jsCode << *$$;
        delete $2;
        delete $6;
    }
    | IF expression ':' NEWLINE INDENT block DEDENT else_clause {
        $$ = new std::string("if (" + *$2 + ") {\n" + *$6 + "} " + *$8 + "\n");
        jsCode << *$$;
        delete $2;
        delete $6;
        delete $8;
    }
    ;

else_clause:
    ELSE ':' NEWLINE INDENT block DEDENT {
        $$ = new std::string("else {\n" + *$5 + "}");
        delete $5;
    }
    | ELIF expression ':' NEWLINE INDENT block DEDENT else_clause {
        $$ = new std::string("else if (" + *$2 + ") {\n" + *$6 + "} " + *$8);
        delete $2;
        delete $6;
        delete $8;
    }
    ;

for_loop:
    FOR IDENTIFIER IN IDENTIFIER ':' NEWLINE INDENT block DEDENT {
        $$ = new std::string("for (let " + *$2 + " of " + *$4 + ") {\n" + *$8 + "}\n");
        jsCode << *$$;
        delete $2;
        delete $4;
        delete $8;
    }
    | FOR IDENTIFIER IN RANGE '(' INTEGER ')' ':' NEWLINE INDENT block DEDENT {
        $$ = new std::string("for (let " + *$2 + " = 0; " + *$2 + " < " + std::to_string($6) + "; " 
               + *$2 + "++) {\n" + *$11 + "}\n");
        jsCode << *$$;
        delete $2;
        delete $11;
    }
    ;

while_loop:
    WHILE expression ':' NEWLINE INDENT block DEDENT {
        $$ = new std::string("while (" + *$2 + ") {\n" + *$6 + "}\n");
        jsCode << *$$;
        delete $2;
        delete $6;
    }
    ;

block:
    statement { $$ = new std::string(*$1); delete $1; }
    | block statement { $$ = new std::string(*$1 + *$2); delete $1; delete $2; }
    ;

expression:
    term { $$ = $1; }
    | expression PLUS term { $$ = new std::string(*$1 + " + " + *$3); delete $1; delete $3; }
    | expression MINUS term { $$ = new std::string(*$1 + " - " + *$3); delete $1; delete $3; }
    ;

term:
    factor { $$ = $1; }
    | term MULT factor { $$ = new std::string(*$1 + " * " + *$3); delete $1; delete $3; }
    | term DIV factor { $$ = new std::string(*$1 + " / " + *$3); delete $1; delete $3; }
    | term MOD factor { $$ = new std::string(*$1 + " % " + *$3); delete $1; delete $3; }
    ;

factor:
    INTEGER { $$ = new std::string(std::to_string($1)); }
    | FLOAT { $$ = new std::string(std::to_string($1)); }
    | STRING { $$ = new std::string(*$1); delete $1; }
    | BOOLEAN { $$ = new std::string((*$1 == "True") ? "true" : "false"); delete $1; }
    | IDENTIFIER { $$ = new std::string(*$1); delete $1; }
    | array_literal { $$ = $1; }
    | function_call { $$ = $1; }
    | '(' expression ')' { $$ = new std::string("(" + *$2 + ")"); delete $2; }
    ;

array_literal:
    LBRACK elements RBRACK { $$ = new std::string("[" + *$2 + "]"); delete $2; }
    ;

elements:
    /* vacío */ { $$ = new std::string(""); }
    | expression { $$ = $1; }
    | elements COMMA expression { $$ = new std::string(*$1 + ", " + *$3); delete $1; delete $3; }
    ;

function_call:
    IDENTIFIER '(' arguments ')' { $$ = new std::string(*$1 + "(" + *$3 + ")"); delete $1; delete $3; }
    | PRINT '(' arguments ')' { $$ = new std::string("console.log(" + *$3 + ")"); delete $3; }
    ;

arguments:
    /* vacío */ { $$ = new std::string(""); }
    | expression { $$ = $1; }
    | arguments COMMA expression { $$ = new std::string(*$1 + ", " + *$3); delete $1; delete $3; }
    ;

comparison:
    expression EQ expression { $$ = new std::string(*$1 + " === " + *$3); delete $1; delete $3; }
    | expression NEQ expression { $$ = new std::string(*$1 + " !== " + *$3); delete $1; delete $3; }
    | expression LT expression { $$ = new std::string(*$1 + " < " + *$3); delete $1; delete $3; }
    | expression GT expression { $$ = new std::string(*$1 + " > " + *$3); delete $1; delete $3; }
    | expression LTE expression { $$ = new std::string(*$1 + " <= " + *$3); delete $1; delete $3; }
    | expression GTE expression { $$ = new std::string(*$1 + " >= " + *$3); delete $1; delete $3; }
    ;

logical_expr:
    comparison { $$ = $1; }
    | logical_expr AND logical_expr { $$ = new std::string(*$1 + " && " + *$3); delete $1; delete $3; }
    | logical_expr OR logical_expr { $$ = new std::string(*$1 + " || " + *$3); delete $1; delete $3; }
    | NOT logical_expr { $$ = new std::string("!" + *$2); delete $2; }
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
