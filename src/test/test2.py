# Estructura anidada

# Inicialización de variables
contador_externo = 0
limite_externo = 4
limite_interno = 6
acumulador = 0.0
estado = True

# Bucle while externo
while contador_externo < limite_externo:
    # Condición if dentro del while
    if estado:    
        # Condición if dentro del if
        if acumulador == 0.0:
            for indice_interno in range(limite_interno):
                acumulador = 1.5 + acumulador 
            # dedentación
            estado = False
            mensaje = "El acumulador ha sido actualizado"
        # dedentación
    # Incrementar la variable del bucle while
    contador_externo = 1 + acumulador 
# Resultado final almacenado en una variable
resultado_final = acumulador
