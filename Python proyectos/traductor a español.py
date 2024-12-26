# Importamos la biblioteca para traduccion
import langdetect #pip install langdetect
import deep_translator #pip install deep-translator
from deep_translator import GoogleTranslator
from langdetect import detect, LangDetectException
def traducir_a_espanol(texto):
    try:
        # Detectamos el idioma del texto original
        idioma_detectado = detect(texto)
        # Creamos el traductor
        traductor = GoogleTranslator(source=idioma_detectado, target='es')
        # Realizamos la traduccion
        traduccion = traductor.translate(texto)
        # Devolvemos los resultados
        return {
            'texto_original': texto,
            'idioma_original': idioma_detectado,
            'traduccion': traduccion
        }
    except LangDetectException:
        return "Error: No se pudo detectar el idioma del texto"
    except Exception as e:
        return f"Error durante la traduccion: {str(e)}"
def main():
    """
    Funcion principal que maneja la interfaz de usuario del programa.
    Permite al usuario introducir texto continuamente hasta que decide salir.
    """
    # Mostramos mensaje de bienvenida e instrucciones
    print("Bienvenido al traductor a espanol")
    print("Ingrese el texto que desea traducir (o 'salir' para terminar):")
    # Bucle principal del programa
    while True:
        # Solicitamos texto al usuario
        texto_usuario = input("\nTexto a traducir: ")
        # Verificamos si el usuario quiere salir
        if texto_usuario.lower() == 'salir':
            print("Hasta luego!")
            break
        # Verificamos que el texto no este vacio
        if not texto_usuario.strip():
            print("Error: Por favor ingrese algun texto")
            continue   
        # Realizamos la traduccion
        resultado = traducir_a_espanol(texto_usuario)
        # Mostramos los resultados
        if isinstance(resultado, dict):
            # Si la traduccion fue exitosa, mostramos la informacion
            print("\nResultados de la traduccion:")
            print(f"Texto original ({resultado['idioma_original']}): {resultado['texto_original']}")
            print(f"Traduccion (es): {resultado['traduccion']}")
        else:
            # Si hubo un error, mostramos el mensaje de error
            print(resultado)
# Punto de entrada del programa
if __name__ == "__main__":
    main()
"""
    Traduce el texto dado a espanol usando la biblioteca deep_translator.
    
    Args:
        texto (str): El texto a traducir en cualquier idioma
        
    Returns:
        dict: Diccionario con el texto original, traduccion e idioma detectado
        str: Mensaje de error si algo falla durante la traduccion
    """