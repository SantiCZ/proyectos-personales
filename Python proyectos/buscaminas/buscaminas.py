import tkinter as tk #pip install tkinter (en consola)
import random #pip install random(en consola)

# Dimensiones del tablero de juego
ROW = 5
COL = 5
MINES = 5

class Minesweeper:
    def __init__(self, master):
        self.master = master
        self.master.title("Minesweeper")
        self.refresh_button = None  # El boton de reinicio se creara mas tarde
        self.new_game()

    def new_game(self):
        # Inicializar un nuevo juego
        self.board = self.initialize_board()
        self.buttons = {}
        self.revealed = [[False for _ in range(COL)] for _ in range(ROW)]  # Celdas reveladas
        self.game_over = False

        self.create_buttons()  # Crear los botones para el tablero
        self.place_mines()  # Colocar las minas en el tablero
        self.calculate_numbers()  # Calcular el numero de minas adyacentes

        # Si hay un boton de reinicio, eliminarlo antes de iniciar un nuevo juego
        if self.refresh_button:
            self.refresh_button.grid_forget()

    # Inicializar el tablero con celdas vacias
    def initialize_board(self):
        return [[" " for _ in range(COL)] for _ in range(ROW)]

    # Colocar minas de forma aleatoria en el tablero
    def place_mines(self):
        mines_placed = 0
        while mines_placed < MINES:
            row = random.randint(0, ROW - 1)
            col = random.randint(0, COL - 1)
            if self.board[row][col] == " ":
                self.board[row][col] = "*"
                mines_placed += 1

    # Calcular el numero de minas adyacentes para cada celda
    def calculate_numbers(self):
        for row in range(ROW):
            for col in range(COL):
                if self.board[row][col] == "*":
                    continue
                mine_count = 0
                for r in range(row - 1, row + 2):
                    for c in range(col - 1, col + 2):
                        if 0 <= r < ROW and 0 <= c < COL and self.board[r][c] == "*":
                            mine_count += 1
                if mine_count > 0:
                    self.board[row][col] = str(mine_count)

    # Crear los botones para la interfaz grafica
    def create_buttons(self):
        for row in range(ROW):
            for col in range(COL):
                button = tk.Button(self.master, text=" ", width=4, height=2,
                                   command=lambda r=row, c=col: self.reveal_cell(r, c))
                button.grid(row=row, column=col)
                self.buttons[(row, col)] = button

    # Revelar una celda cuando se hace clic
    def reveal_cell(self, row, col):
        if self.game_over or self.revealed[row][col]:
            return
        self.revealed[row][col] = True
        self.buttons[(row, col)].config(text=self.board[row][col], bg="lightgray")

        if self.board[row][col] == "*":
            # Si se hace clic en una mina, termina el juego
            self.buttons[(row, col)].config(bg="red")
            self.game_over = True
            self.show_game_over_message("Perdiste!")
            self.show_refresh_button()
            return

        if self.board[row][col] == " ":
            # Revelar celdas adyacentes si no hay minas alrededor
            for r in range(row - 1, row + 2):
                for c in range(col - 1, col + 2):
                    if 0 <= r < ROW and 0 <= c < COL and not self.revealed[r][c]:
                        self.reveal_cell(r, c)

        if self.check_win():
            # Si se cumplen las condiciones para ganar, mostrar mensaje
            self.game_over = True
            self.show_game_over_message("Felicidades! Ganaste!")
            self.show_refresh_button()

    # Mostrar un mensaje cuando termina el juego
    def show_game_over_message(self, message):
        message_label = tk.Label(self.master, text=message, font=("Arial", 16))
        message_label.grid(row=ROW, column=0, columnspan=COL)

    # Verificar si el jugador ha ganado
    def check_win(self):
        for row in range(ROW):
            for col in range(COL):
                if self.board[row][col] != "*" and not self.revealed[row][col]:
                    return False
        return True

    # Mostrar el boton de reinicio al terminar el juego
    def show_refresh_button(self):
        self.refresh_button = tk.Button(self.master, text="Nuevo Juego", command=self.new_game, width=15, height=2)
        self.refresh_button.grid(row=ROW + 1, column=0, columnspan=COL)

# Crear la ventana principal e iniciar el juego
if __name__ == "__main__":
    root = tk.Tk()
    game = Minesweeper(root)
    root.mainloop()
