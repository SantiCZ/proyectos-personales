#include <iostream> 
using namespace std; 
char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} }; // Tablero de juego, es una matriz de 3x3 basicamente
char currentMarker; // Almacena el marcador actual (X u O)
int currentPlayer; // Almacena el jugador actual
// Funcion para dibujar el tablero en la consola
void drawBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) { // Recorre filas
        for (int j = 0; j < 3; j++) { // Recorre columnas
            cout << " " << board[i][j] << " "; // Imprime el valor de la casilla
            if (j < 2) cout << "|"; // Agrega separadores verticales
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n"; // Agrega separadores horizontales
    }
    cout << "\n";
}
// Funcion para colocar un marcador en el tablero
bool placeMarker(int slot) {
    int row = (slot - 1) / 3; // Calcula la fila
    int col = (slot - 1) % 3; // Calcula la columna
    if (board[row][col] != 'X' && board[row][col] != 'O') { // Verifica si la casilla esta libre
        board[row][col] = currentMarker; // Coloca el marcador
        return true;
    }
    return false; // Retorna false si la casilla ya esta ocupada
}
// Funcion para verificar si hay un ganador
int winner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return currentPlayer; // Verifica filas
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return currentPlayer; // Verifica columnas
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return currentPlayer; // Verifica diagonal principal
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return currentPlayer; // Verifica diagonal secundaria
    return 0; // Retorna 0 si no hay ganador
}
// Funcion para cambiar de jugador
void swapPlayer() {
    currentMarker = (currentMarker == 'X') ? 'O' : 'X'; // Cambia el marcador
    currentPlayer = (currentPlayer == 1) ? 2 : 1; // Cambia el jugador
}
// Funcion principal del juego
void game() {
    cout << "Jugador 1, elige tu marca (X u O): ";
    cin >> currentMarker; // Jugador 1 elige su marcador
    currentPlayer = 1; // Comienza el jugador 1
    int moves = 0; // Contador de movimientos
    bool gameWon = false; // Bandera para saber si el juego termino
    drawBoard(); // Dibuja el tablero inicial
    while (moves < 9 && !gameWon) { // Ciclo del juego
        int slot;
        cout << "Jugador " << currentPlayer << " (" << currentMarker << "), ingresa un numero de casilla: ";
        cin >> slot; // Jugador ingresa un numero de casilla
        if (slot < 1 || slot > 9 || !placeMarker(slot)) { // Verifica si el movimiento es valido
            cout << "Movimiento invalido. Intenta de nuevo.\n";
            continue;
        }
        drawBoard(); // Redibuja el tablero
        moves++; // Incrementa el contador de movimientos
        if (winner()) { // Verifica si hay un ganador
            cout << "Jugador " << currentPlayer << " gana!\n";
            gameWon = true;
        }
        else if (moves == 9) { // Verifica si hay empate
            cout << "Es un empate!\n";
        }
        else {
            swapPlayer(); // Cambia de jugador
        }
    }
}
// Funcion principal
int main() {
    game(); // Inicia el juego
    return 0; // Termina el programa
}