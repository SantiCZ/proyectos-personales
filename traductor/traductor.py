from tkinter import *
import tkinter as tk
from tkinter import messagebox
from tkinter import ttk
from googletrans import Translator

root=tk.Tk()
root.title("Traductor")
root.geometry("530x330")
root.maxsize(530,330)
root.minsize(530,330)

# Define elegir_lenguaje
elegir_lenguaje = ttk.Combobox(root, values=["es", "en", "fr", "de"])
elegir_lenguaje.place(x=350, y=20)
elegir_lenguaje.current(0)

def traducir():
    lenguaje_1=tk.get("1.0", "end-1c")
    tk=elegir_lenguaje.get()
    if lenguaje_1 =='':
        messagebox.showerror("Error","Por favor, introduzca algo en el cuadro de texto")
    else: 
        tk.delete(1.0, END)
        traductor=traductor()
        output=traductor.translate(lenguaje_1, dest=tk)
        tk.insert(END, output.text)
def clear():
    tk.delete(1.0, END)
    tk.delete(1.0, END)
auto_detect_lenguaje=tk.StringVar()
auto_detect=ttk.Combobox(root,
                          width=20, 
                          textvariable=auto_detect_lenguaje,
                            state="readonly")
auto_detect['values']=('Auto Detectar',)
auto_detect.place(x=30, y=70)
auto_detect.current(0)
lenguaje_elegido=tk.StringVar()
elegir_lenguaje= ttk.Combobox(root, 
                              width=20, 
                              textvariable=lenguaje_elegido, 
                              state="readonly")
elegir_lenguaje['values']=('es', 'en', 'fr', 'de','it','pt','ru','ja','ko','zh-cn','ar','tr','pl','nl','sv','da',
                           'fi','id','ms','no','vi','th','cs','el','hu','ro','sk','uk','bg','hr','sr','sl','ca',)
elegir_lenguaje.place(x=298, y=70)
elegir_lenguaje.current(0)
t1=Text(root, width=30, height=10, font=("Arial", 16))
t1.place(x=10, y=100)
t2=Text(root, width=30, height=10, font=("Arial", 16))
t2.place(x=260, y=100)
boton=Button(root, 
             text="Traducir", 
             font=("Arial", 16), 
             command=traducir)
boton.place(x=150, y=280)
boton_clear=Button(root, 
                   text="Limpiar", 
                   font=("Arial", 16), 
                   command=clear)
boton_clear.place(x=280, y=200)
root.mainloop()