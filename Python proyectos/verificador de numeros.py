import phonenumbers as ph

def validacion_de_telefono(telefono, region="AR"):
    try:
        # Parsear el numero
        parsed_number = ph.parse(telefono, region)
        # Validar el numero
        if ph.is_valid_number(parsed_number):
            # Formatear el numero en formato internacional
            return f"Valid: {ph.format_number(parsed_number, ph.PhoneNumberFormat.E164)}"
        else:
            return "Numero invalido"
    except ph.NumberParseException as e:
        return f"Error al procesar el numero: {str(e)}"

