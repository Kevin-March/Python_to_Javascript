# Transpiler de Python a JavaScript

## Introducción
Este proyecto implementa un transpiler que convierte código Python en JavaScript, usando Flex/Bison para análisis léxico y sintáctico. Permite traducir constructos básicos de Python (declaraciones, expresiones, estructuras de control y funciones) a sintaxis equivalente en JS.

## Uso
1. Generar analizadores:
   ```bash
   bison -d -o parser.cpp parser.y
   flex -o scanner.cpp scanner.l
   ```
2. Compilar el transpiler:
   ```bash
   g++ main.cpp parser.cpp scanner.cpp -o parser
   ```
3. Ejecutar la conversión:
   ```bash
   ./parser < archivo_entrada.py [archivo_salida.js]
   ```
   - Si no se especifica archivo_salida.js, se crea output.js.

## Resultado Esperado
- Un archivo JavaScript (`.js`) con el código convertido de Python.
