#include <iostream>
using namespace std;
int main() {
    const int maxSize = 10; // sino es muy grande en mi opinion
    char str[maxSize]{};//almacena la cadena
    char* ptr = str;// Puntero que apunta al inicio de la cadena
    // Solicitar al usuario que ingrese una cadena
    cout << "Ingrese una cadena: ";
    cin.getline(str, maxSize); // Lee la linea completa
    cout << "Vocales en la cadena: ";
    // Recorre la cadena y muestra las vocales
    while (*ptr != '\0') { // Mientras no se llegue al final de la cadena
        // Verifica si el caracter actual es una vocal (tanto mayusculas y/o minúsculas)
        if (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' ||
            *ptr == 'o' || *ptr == 'u' ||
            *ptr == 'A' || *ptr == 'E' || *ptr == 'I' ||
            *ptr == 'O' || *ptr == 'U') {
            cout << *ptr << " "; // Imprime la vocal
        }
        ptr++; // Avanza al siguiente carácter
    }
    cout << endl; // Salto de línea al final porque asi queda mejor
    return 0;