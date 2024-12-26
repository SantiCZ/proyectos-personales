def ceasar_cifrado_encriptado(s, shift):
    # Inicializa la variable para almacenar el resultado
    result = ""
    # Recorre cada caracter en la cadena de entrada
    for char in s:
        # Verifica si el caracter es una letra mayuscula
        if char.isupper():
            # Aplica el cifrado para letras mayusculas y anade al resultado
            result += chr((ord(char) + shift - 65) % 26 + 65)
        # Verifica si el caracter es una letra minuscula
        elif char.islower():
            # Aplica el cifrado para letras minusculas y anade al resultado
            result += chr((ord(char) + shift - 97) % 26 + 97)
        else:
            # Si el caracter no es una letra, lo anade al resultado sin cambios
            result += char
    # Retorna el resultado cifrado
    return result
def ceasar_cifrado_decodificado(s, shift):
    # Inicializa la variable para almacenar el resultado
    result = ""
    # Recorre cada caracter en la cadena de entrada
    for char in s:
        # Verifica si el caracter es una letra mayuscula
        if char.isupper():
            # Aplica el descifrado para letras mayusculas y anade al resultado
            result += chr((ord(char) - shift - 65) % 26 + 65)
        # Verifica si el caracter es una letra minuscula
        elif char.islower():
            # Aplica el descifrado para letras minusculas y anade al resultado
            result += chr((ord(char) - shift - 97) % 26 + 97)
        else:
            # Si el caracter no es una letra, lo anade al resultado sin cambios
            result += char
    # Retorna el resultado descifrado
    return result
# Si el script se esta ejecutando directamente
if __name__ == "__main__":
    # Solicita al usuario que ingrese el mensaje a cifrar
    text = input("Ingrese el mensaje a cifrar: ")
    # Solicita al usuario que ingrese el valor de desplazamiento
    shift = int(input("Ingrese el valor de desplazamiento: "))
    # Llama a la funcion de cifrado y almacena el texto cifrado
    encriptado = ceasar_cifrado_encriptado(text, shift)
    # Imprime el texto cifrado
    print("Texto cifrado: ", encriptado)
    # Llama a la funcion de descifrado y almacena el texto descifrado
    decodificado = ceasar_cifrado_decodificado(encriptado, shift)
    # Imprime el texto descifrado
    print("Texto descifrado: ", decodificado)
#para decodificar, se debe conocer el valor de desplazamiento, y usar su opuesto, ej: si el valor de desplazamiento es 3, se debe usar -3 para decodificar