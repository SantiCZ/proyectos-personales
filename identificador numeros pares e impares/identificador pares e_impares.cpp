#include <iostream>
using namespace std;
int main() {
    const int size = 10;// Tama�o 
    int numeros[size];// almacena n�meros
    int* ptr = numeros;// Puntero apunta al inicio del vector( o array )
    // Cargar el array con numeros ingresados por el usuario
    cout << "Ingrese 10 numeros enteros:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Numero " << (i + 1) << ": ";
        cin >> *(ptr + i); // Almacena el numero en la posici�n correspondiente del array
    }
    // Verificar qu� n�meros son pares y mostrar su posici�n en memoria
    cout << "Numeros pares y sus posiciones en memoria:" << endl;
    for (int i = 0; i < size; i++) {
        if (*(ptr + i) % 2 == 0) { // Verifica si el n�mero es par
            cout << "Numero: " << *(ptr + i) << ", Posicion en memoria: " << (ptr + i) << endl;
        }
    }
    return 0;