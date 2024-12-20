import math  # Importamos la libreria math para realizar operaciones matematicas avanzadas.

def menu():
    # Muestra el menu principal con las opciones de operaciones
    print("\nCalculadora Cientifica")
    print("Selecciona una opcion:")
    print("1. Sumar")
    print("2. Restar")
    print("3. Multiplicar")
    print("4. Dividir")
    print("5. Raiz cuadrada")
    print("6. Potencia")
    print("7. Logaritmo")
    print("8. Funciones trigonometricas")
    print("9. Salir")

def trigonometrica():
    # Muestra el menu para seleccionar funciones trigonometricas
    print("\nFunciones Trigonometricas:")
    print("1. Seno")
    print("2. Coseno")
    print("3. Tangente")
    print("4. Regresar al menu principal")
    
    # Solicita la opcion de funcion trigonometrica
    opcion = int(input("Elige una opcion: "))
    
    if opcion == 1:
        # Calcula el seno de un angulo (en grados)
        angulo = float(input("Introduce el angulo en grados: "))
        resultado = math.sin(math.radians(angulo))  # Convierte el angulo a radianes y calcula el seno
        print(f"Seno({angulo}°) = {resultado}")
    elif opcion == 2:
        # Calcula el coseno de un angulo (en grados)
        angulo = float(input("Introduce el angulo en grados: "))
        resultado = math.cos(math.radians(angulo))  # Convierte el angulo a radianes y calcula el coseno
        print(f"Coseno({angulo}°) = {resultado}")
    elif opcion == 3:
        # Calcula la tangente de un angulo (en grados)
        angulo = float(input("Introduce el angulo en grados: "))
        resultado = math.tan(math.radians(angulo))  # Convierte el angulo a radianes y calcula la tangente
        print(f"Tangente({angulo}°) = {resultado}")
    elif opcion == 4:
        return  # Regresa al menu principal si se elige esta opcion
    else:
        print("Opcion invalida")  # Si la opcion no es valida, muestra un mensaje de error

def calculadora():
    while True:
        menu()  # Muestra el menu principal
        opcion = int(input("Elige una opcion: "))  # Solicita la opcion al usuario
        
        if opcion == 1:
            # Realiza una suma
            num1 = float(input("Introduce el primer numero: "))
            num2 = float(input("Introduce el segundo numero: "))
            print(f"La suma es: {num1 + num2}")
        
        elif opcion == 2:
            # Realiza una resta
            num1 = float(input("Introduce el primer numero: "))
            num2 = float(input("Introduce el segundo numero: "))
            print(f"La resta es: {num1 - num2}")
        
        elif opcion == 3:
            # Realiza una multiplicacion
            num1 = float(input("Introduce el primer numero: "))
            num2 = float(input("Introduce el segundo numero: "))
            print(f"La multiplicacion es: {num1 * num2}")
        
        elif opcion == 4:
            # Realiza una division
            num1 = float(input("Introduce el primer numero: "))
            num2 = float(input("Introduce el segundo numero: "))
            if num2 != 0:
                print(f"La division es: {num1 / num2}")
            else:
                print("Error: Division por cero.")
        
        elif opcion == 5:
            # Calcula la raiz cuadrada
            num = float(input("Introduce un numero: "))
            if num < 0:
                print("Error: No se puede calcular la raiz cuadrada de un numero negativo.")
            else:
                print(f"La raiz cuadrada de {num} es: {math.sqrt(num)}")
        
        elif opcion == 6:
            # Calcula la potencia
            base = float(input("Introduce la base: "))
            exponente = float(input("Introduce el exponente: "))
            print(f"{base} elevado a {exponente} es: {math.pow(base, exponente)}")
        
        elif opcion == 7:
            # Calcula el logaritmo
            num = float(input("Introduce el numero: "))
            if num <= 0:
                print("Error: El logaritmo no esta definido para numeros menores o iguales a cero.")
            else:
                base = float(input("Introduce la base del logaritmo (por defecto es e): ") or "2.718")
                if base == 2.718:
                    print(f"El logaritmo natural de {num} es: {math.log(num)}")
                else:
                    print(f"El logaritmo en base {base} de {num} es: {math.log(num, base)}")
        
        elif opcion == 8:
            # Llama a la funcion trigonometrica
            trigonometrica()
        
        elif opcion == 9:
            # Sale del programa
            print("¡Hasta luego!")
            break
        
        else:
            print("Opcion no valida, por favor selecciona una opcion valida.")

# Iniciar la calculadora
calculadora()
