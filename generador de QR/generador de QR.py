import pyqrcode
def generar_qr(link,path):
    try:    
        codigo_qr=pyqrcode.create(link)
        codigo_qr.png(path,scale=10)
        print("QR generado con éxito: {path}")
        return path
    except Exception as e:
        print(f"Error al generar el QR: {e}")
        return None
link= "https://www.google.com"
path= "./qr_google.png"
generar_qr(link,path)