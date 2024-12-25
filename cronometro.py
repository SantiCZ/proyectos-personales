import time

def cronometro():
    # Mensaje para iniciar el cronometro
    print("Presiona Enter para iniciar el cronometro.")
    # Espera a que el usuario presione Enter
    input()
    # Registra el tiempo de inicio
    inicio = time.time()
    # Mensaje para detener el cronometro
    print("Cronometro iniciado. Presiona Enter para detenerlo.")
    # Espera a que el usuario presione Enter nuevamente
    input()
    # Registra el tiempo de fin
    fin = time.time()
    # Calcula el tiempo transcurrido
    tiempo_transcurrido = fin - inicio
    # Muestra el tiempo transcurrido en segundos
    print(f"Tiempo transcurrido: {tiempo_transcurrido:.2f} segundos.")

# Llama a la funcion del cronometro
cronometro()
