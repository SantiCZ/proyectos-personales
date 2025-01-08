
from PIL import Image

# Funcion para convertir la imagen a arte ASCII 
def imagen_a_ascii(imagen_ruta, ancho=100):
    # Caracter que representa los niveles de intensidad de la imagen (de mas oscuro a mas claro)
    # Los caracteres mas oscuros representan los pixeles mas oscuros, y los mas claros los pixeles mas brillantes
    caracteres_ascii = '@%#*+=-:. '
    
    # Abrir la imagen desde la ruta especificada
    imagen = Image.open(imagen_ruta)
    
    # Calcular la altura proporcionalmente al ancho dado, manteniendo la relacion de aspecto
    aspect_ratio = imagen.height / float(imagen.width)  # Relacion de aspecto de la imagen original
    altura = int(aspect_ratio * ancho)  # Calculamos la altura proporcional
    # Redimensionamos la imagen al nuevo tamano
    imagen = imagen.resize((ancho, altura))
    
    # Convertir la imagen a escala de grises para simplificar la conversion a ASCII
    imagen_gris = imagen.convert('L')  # 'L' es el modo de escala de grises
    
    # Obtener los valores de los pixeles en una lista (cada valor es un numero entre 0 y 255)
    pixeles = imagen_gris.getdata()
    
    # Crear una cadena vacia donde se almacenaran los caracteres ASCII resultantes
    ascii_str = ''
    
    # Convertir cada valor de intensidad de pixel a un caracter ASCII
    for pixel in pixeles:
        # Usamos la division para asignar un caracter en funcion de la intensidad (0-255)
        ascii_str += caracteres_ascii[pixel // 32]  # 255 / 8 = 32, por eso dividimos entre 32
    
    # Dividir la cadena ASCII en lineas de acuerdo con el ancho especificado
    # Esto asegura que cada linea no sea mas larga que el ancho de la imagen original
    ascii_str = '\n'.join([ascii_str[i:i+ancho] for i in range(0, len(ascii_str), ancho)])
    
    return ascii_str

# Funcion principal para mostrar el arte ASCII en la consola
def mostrar_ascii(imagen_ruta, ancho=100):
    # Llamar a la funcion para convertir la imagen en arte ASCII
    ascii_art = imagen_a_ascii(imagen_ruta, ancho)
    print(ascii_art)

# Ruta de la imagen
imagen_ruta = 'ruta_a_tu_imagen.jpg'  # Cambia esto por la ruta de tu imagen
mostrar_ascii(imagen_ruta)
