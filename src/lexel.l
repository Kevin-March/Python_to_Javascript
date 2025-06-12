%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    /*
    FALSE, CLASS, FINALLY, IS, RETURN, NONE, FOR, LAMBDA, TRY, TRUE,
    DEF, FROM, NONLOCAL, WHILE, AND, DEL, GLOBAL, NOT, WITH, AS, ELIF,
    IF, OR, YIELD, ASSERT, ELSE, IMPORT, PASS, BREAK, EXCEPT, IN, RAISE,
    NEWLINE, INDENT, DEDENT
    */

    #define INDENT_STACK_SIZE 100
    #define STRBUF_SIZE 4096

    int indent_stack[INDENT_STACK_SIZE];
    int indent_top = 0;
    int at_line_start = 1;
    char strbuf[STRBUF_SIZE];

    /* Funcion para calcular el nivel de indentacion */
    int compute_indent_level(const char *s) {
        int col = 0;
        for(; *s; ++s) {
            if(*s == ' ')                       // Espacios suman 1 a la indentacion
                col += 1;
            else if (*s == '\t')                // Las tabulaciones suman de 1 a 8 de modo que la suma sea multiplo de 8
                col += 8 - (col%8);
            else break;
        }
        return col;
    }

    /* Funcion que evalua si se crea una aumenta o disminuye una indentacion */
    void emit_indent_dedent(int new_indent) {
        int current_indent = indent_stack[indent_top];

        if(new_indent > current_indent) {
            indent_stack[++indent_top] = new_indent;
            printf("INDENT\n");
        } else if (new_indent < current_indent) {
            while (indent_top > 0 && new_indent < indent_stack[indent_top]) {
                indent_top--;
                printf("DEDENT\n");
            }
            if (new_indent != indent_stack[indent_top]) {
                fprintf(stderr, "Error on line %d: unexpected indent level %d\n", yylineno, new_indent);
                exit(1);
            }
        }
    }

    void strbuf_init(){
        strbuf[0]='\0';
    }

    void strbuf_append(const char *s){
        if(strlen(strbuf)+strlen(s)>=STRBUF_SIZE) {
            fprintf(stderr, "Error on line %d: string literal exceeds maximum allowed size (max %d bytes)\n", yylineno, STRBUF_SIZE);
        }

        strcat(strbuf, s);
    }
%}

%option noyywrap
%x STRING

/* Definiciones Regulares */

%%


^[ \t]* {                                                       /* Manejo de espacios y tabulaciones */
    if(at_line_start) {                                         /* Indentación al comienzo de la linea */
        int level = compute_indent_level(yytext);
        emit_indent_dedent(level);
        at_line_start = 0;   
    }                                                           /* Caso contrario se ignoran los espacios */ 
}

\\\n    ;                                                       /* El uso de \ en Python significa la union explicita de lineas,
                                                                entonces se ignora el salto de linea que le sigue*/
        

\"      { strbuf_init(); BEGIN(STRING);}                        /* Manejo de cadenas encerradas en "" */

<STRING>[^\"\\\n]+  { strbuf_append(yytext);}                   /* Cualquier símbolo menos ", \ y \n */
<STRING>\\.         { strbuf_append(yytext);}                   /* Manejo de caracteres de escape en la cadena(\n, \t, etc) */
<STRING>\\\n        ;                                          /* Uso de \ para la union explicita de lineas */
<STRING>\"          { printf("%s\n", strbuf); BEGIN(INITIAL);}  /* Final de una cadena */
<STRING>\n          { printf("Error: unterminated string\n");}  /*Cadena mal terminada (sin comilla al final) */

\#.*                ;                                           /* Manejo de comentarios */
\r\n|\n|\r          { at_line_start = 1; printf("NEWLINE\n");}  /* Salto de linea */

%%