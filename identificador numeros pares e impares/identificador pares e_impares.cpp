#include <iostream>
using namespace std;
int main() {
    const int size = 10;// Tamaño 
    int numeros[size];// almacena números
    int* ptr = numeros;// Puntero apunta al inicio del vector( o array )
    // Cargar el array con numeros ingresados por el usuario
    cout << "Ingrese 10 numeros enteros:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Numero " << (i + 1) << ": ";
        cin >> *(ptr + i); // Almacena el numero en la posición correspondiente del array
    }
    // Verificar qué números son pares y mostrar su posición en memoria
    cout << "Numeros pares y sus posiciones en memoria:" << endl;
    for (int i = 0; i < size; i++) {
        if (*(ptr + i) % 2 == 0) { // Verifica si el número es par
            cout << "Numero: " << *(ptr + i) << ", Posicion en memoria: " << (ptr + i) << endl;
        }
    }
    return 0;