#include <iostream>
#include <fstream>
#include <map>
#include "parser.hpp"

extern int yylex();
extern FILE* yyin;                         
extern int yyparse();                     
extern std::map<std::string, std::string> symbol_table;
extern std::string* goalStr;
extern std::string* functionDeclarationsStr;

int main(int argc, char const *argv[]) {
    // Verificar argumentos de línea de comandos
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " <archivo_entrada.py> [archivo_salida.js]" << std::endl;
        return 1;
    }

    // Configurar archivo de salida (default: output.js)
    std::string outputFilename = (argc > 2) ? ("output/" + std::string(argv[2])) : "output/output.js";
    std::ofstream output_file(outputFilename);
    
    if (!output_file.is_open()) {
        std::cerr << "Error al abrir el archivo " << outputFilename << std::endl;
        return 1;
    }

    // Configurar archivo de entrada
    FILE* input_file = fopen(argv[1], "r");
    if (!input_file) {
        std::cerr << "Error al abrir el archivo " << argv[1] << std::endl;
        return 1;
    }
    yyin = input_file;

    // Ejecutar el parser
    int result = yyparse();

    // Generar el archivo JavaScript
    output_file << "// Código generado automáticamente de " << argv[1] << "\n";
    output_file << "// Traducción de Python a JavaScript\n\n";

    // Imprimir declaraciones de funciones (van al inicio en JS)
    if (functionDeclarationsStr) {
        output_file << *functionDeclarationsStr << "\n";
        delete functionDeclarationsStr;
    }
    
    // Cuerpo principal del código (sin wrapper main() como en C)
    if (goalStr) {
        output_file << *goalStr << "\n";
        delete goalStr;
    }

    output_file.close();
    fclose(input_file);

    if (result == 0) {
        std::cout << "Traducción completada correctamente en " << outputFilename << std::endl;
    } else {
        std::cerr << "Error durante la traducción" << std::endl;
    }

    return result;
}