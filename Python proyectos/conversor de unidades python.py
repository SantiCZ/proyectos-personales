def convertir_unidad(valor, unidad_origen, unidad_destino):
    # Conversion de longitudes
    if unidad_origen == 'metros' and unidad_destino == 'kilometros':
        return valor / 1000  # Convertir metros a kilometros
    elif unidad_origen == 'kilometros' and unidad_destino == 'metros':
        return valor * 1000  # Convertir kilometros a metros
    
    # Conversion de temperaturas
    elif unidad_origen == 'Fahrenheit' and unidad_destino == 'Celsius':
        return (valor - 32) * 5/9  # Convertir Fahrenheit a Celsius
    elif unidad_origen == 'Celsius' and unidad_destino == 'Fahrenheit':
        return (valor * 9/5) + 32  # Convertir Celsius a Fahrenheit
    
    # Otras conversiones que puedes agregar
    else:
        return "Conversion no soportada"  # Si la conversion no esta definida

# Ejemplos de uso
print(convertir_unidad(1000, 'metros', 'kilometros'))  # 1.0
print(convertir_unidad(32, 'Fahrenheit', 'Celsius'))  # 0.0
