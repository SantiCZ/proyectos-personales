#include <iostream>
using namespace std;
int main() {
    const int tamanio = 5;// precios
    float precios[tamanio];// precios originales
    float preciosAumentados[tamanio]; // precios con aumento
    float* ptrPrecios = precios; // Puntero para el array de precios
    float* ptrAumentados = preciosAumentados; // Puntero para el array de precios aumentados
    // Ingresar los precios
    cout << "Ingrese " << tamanio << " precios:" << endl;
    for (int i = 0; i < tamanio; i++) {
        cout << "Precio " << (i + 1) << ": ";
        cin >> *(ptrPrecios + i); // Almacena el precio en el array
    }
    // Calcular el aumento del 10% y almacenarlo en el nuevo array
    for (int i = 0; i < tamanio; i++) {
        *(ptrAumentados + i) = *(ptrPrecios + i) * 1.10; // Aumento del 10%
    }
    // Mostrar los precios originales y los precios aumentados
    cout << "\nPrecios originales y aumentados:" << endl;
    for (int i = 0; i < tamanio; i++) {
        cout << "Precio original: " << *(ptrPrecios + i)
            << ", Precio con aumento: " << *(ptrAumentados + i) << endl;
    }
    return 0;
}