import requests
from bs4 import BeautifulSoup

# URL del sitio web de noticias (puedes cambiarla por la de tu preferencia), se debe installar Beautifulsoup y requests previamente
url = "https://www.bbc.com"  # Reemplazalo por el sitio web de tu eleccion

# Realizamos la solicitud HTTP para obtener el contenido de la pagina
response = requests.get(url)

# Verificamos que la solicitud fue exitosa (codigo 200)
if response.status_code == 200:
    # Parseamos el contenido HTML con BeautifulSoup
    soup = BeautifulSoup(response.text, 'html.parser')

    # Ejemplo de como extraer los titulares de noticias
    # Esto depende de la estructura HTML del sitio web
    # En este caso, estamos buscando todos los enlaces dentro de las etiquetas 'a' de la clase 'gs-c-promo-heading'
    noticias = soup.find_all('a', class_='gs-c-promo-heading')  # Ajusta esta clase segun el sitio web

    # Si quieres filtrar por categorias, puedes buscar enlaces o secciones especificas
    categorias = ['deportes', 'tecnologia']  # Categorias que te interesan

    for noticia in noticias:
        titulo = noticia.get_text()  # Extraemos el texto del titular
        enlace = noticia.get('href')  # Extraemos el enlace a la noticia

        # Filtramos las noticias segun las categorias
        if any(categoria in enlace.lower() for categoria in categorias):
            print(f"Titulo: {titulo}")
            print(f"Enlace: {url}{enlace}")  # Concatenamos el enlace completo
            print("-" * 80)

else:
    print("Error al acceder al sitio web:", response.status_code)
