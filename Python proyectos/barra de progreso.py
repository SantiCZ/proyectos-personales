import tkinter as tk  # Importa el modulo tkinter para crear interfaces graficas
from tkinter import ttk  # Importa el submodulo ttk de tkinter para estilos avanzados de widgets
from tkinter.messagebox import showinfo  # Importa la funcion showinfo para mostrar mensajes emergentes
# Crea una ventana principal
root = tk.Tk()
root.geometry('300x120')  # Establece el tamano de la ventana
root.title('barra de progreso')  # Establece el titulo de la ventana
# Funcion para actualizar la etiqueta del progreso
def update_progress_label():
    return f"progreso actual: {pb['value']}%"
# Funcion para incrementar el progreso
def progreso():
    if pb['value'] < 100:
        pb['value'] += 10  # Incrementa el valor de la barra de progreso
        valor_label['text'] = update_progress_label()  # Actualiza el texto de la etiqueta
    else:
        showinfo('Progreso', 'Proceso completado')  # Muestra un mensaje cuando se completa el progreso
# Funcion para detener el progreso
def parar():
    pb.stop()  # Detiene la barra de progreso
    valor_label['text'] = 'Proceso detenido'  # Actualiza el texto de la etiqueta
# Configura la barra de progreso
pb = ttk.Progressbar(
    root,
    orient='horizontal',  # Establece la orientacion de la barra
    mode='determinate',  # Modo determinado para mostrar el progreso
    length=280  # Longitud de la barra de progreso
)
pb.grid(column=0, row=0, columnspan=2, padx=10, pady=10)  # Ubica la barra de progreso en la ventana
# Configura la etiqueta que muestra el progreso
valor_label = ttk.Label(root, text=update_progress_label())
valor_label.grid(column=0, row=1, columnspan=2)  # Ubica la etiqueta en la ventana
# Configura el boton para iniciar el progreso
start_button = ttk.Button(
    root, text='Iniciar',
    command=progreso  # Asocia la funcion progreso al boton
)
start_button.grid(column=0, row=2, padx=10, pady=10, sticky=tk.E)  # Ubica el boton en la ventana
# Configura el boton para detener el progreso
stop_button = ttk.Button(
    root, text='Parar',
    command=parar  # Asocia la funcion parar al boton
) 
stop_button.grid(column=1, row=2, padx=10, pady=10, sticky=tk.W)  # Ubica el boton en la ventana
root.mainloop()  # Inicia el bucle principal de la aplicacion
