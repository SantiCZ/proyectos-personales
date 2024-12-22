import secrets
import string
def generar_contraseña(length= 12):
    alfabeto= {
        string.ascii_letters +
        string.digits +
        string.punctuation
    }
    return ''.join(secrets.choice(alfabeto)
                   for _ in range(length))
contraseña= generar_contraseña()
print("tu nueva contraseña es:{contraseña}") 