import qrcode

# Datos para el código QR (inicio de Google)
data = "https://www.google.com"

# Crear el código QR
qr = qrcode.QRCode(
    version=1,  # Controla el tamaño del QR (1 es el más pequeño)
    error_correction=qrcode.constants.ERROR_CORRECT_L,  # Nivel de corrección de errores
    box_size=10,  # Tamaño de cada cuadro en el QR
    border=4,  # Bordes alrededor del QR
)

# Añadir datos al QR
qr.add_data(data)
qr.make(fit=True)

# Crear imagen del QR
img = qr.make_image(fill_color="black", back_color="white")

# Guardar la imagen
img.save("codigo_qr_google.png")

print("Código QR generado y guardado como 'codigo_qr_google.png'")
