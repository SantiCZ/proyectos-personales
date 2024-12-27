#include <iostream>
#include <vector>
using namespace std;
// Funcion para mostrar los elementos del vector
void mostrarElementos(const vector<int>& v) {
    cout << "Los elementos del vector: ";
    // Bucle para iterar sobre cada elemento del vector
    for (const int& i : v) {
        cout << i << " "; // Muestra cada elemento
    }
    cout << endl; // Salto de linea al final
}
// Funci�n para agregar un nuevo elemento al vector
void agregarElemento(vector<int>& v) {
    int nuevoElemento;
    cout << "Introduce un nuevo elemento: ";
    cin >> nuevoElemento; // Lee el nuevo elemento del usuario
    v.push_back(nuevoElemento); // Agrega el elemento al final del vector
    cout << "Elemento agregado." << endl; // Mensaje de confirmacion
}
// Funcion para eliminar un elemento del vector
void eliminarElemento(vector<int>& v) {
    int indice;
    cout << "Introduce el indice del elemento a eliminar (0 a " << v.size() - 1 << "): ";
    cin >> indice; // Lee el indice del elemento a eliminar
    // Verifica que el indice sea valido
    if (indice >= 0 && indice < v.size()) {
        v.erase(v.begin() + indice); // Elimina el elemento en el �ndice especificado
        cout << "Elemento eliminado." << endl; // Mensaje de confirmaci�n
    }
    else {
        cout << "Indice invalido." << endl; // Mensaje de error si el �ndice no es v�lido
    }
}
int main() {
    // Inicializa el vector con algunos elementos
    vector<int> v = { 1, 2, 3, 4, 5 };
    int opcion;
    // Bucle para mostrar el men� hasta que el usuario elija salir
    do {
        cout << "\nMenu:\n";
        cout << "1. Mostrar elementos del vector\n";
        cout << "2. Agregar elemento al vector\n";
        cout << "3. Eliminar elemento del vector\n";
        cout << "4. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion; // Lee la opci�n elegida por el usuario
        // Procesa la opci�n elegida
        switch (opcion) {
        case 1:
            mostrarElementos(v); // Muestra los elementos
            break;
        case 2:
            agregarElemento(v); // Agrega un nuevo elemento
            break;
        case 3:
            eliminarElemento(v); // Elimina un elemento
            break;
        case 4:
            cout << "Saliendo del programa." << endl; // Mensaje de salida
            break;
        default:
            cout << "Opci�n invalida. Int�ntalo de nuevo." << endl; // Mensaje de error para opci�n invalida
            break;
        }
    } while (opcion != 4); // Continua el bucle hasta que el usuario elija salir
    return 0; // Fin del programa
}