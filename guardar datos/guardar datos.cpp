#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// Estructura para almacenar la información de una persona
struct Persona {
    string nombre;
    string telefono;
};
// Función para guardar datos de personas en un archivo
void guardarPersonas(const string& nombreArchivo) {
    const int numPersonas = 5;  // Número de personas a registrar
    Persona personas[numPersonas];
    // Obtener datos de las personas del usuario
    for (int i = 0; i < numPersonas; ++i) {
        cout << "Ingrese el nombre de la persona " << i + 1 << ": ";
        getline(cin, personas[i].nombre);
        cout << "Ingrese el teléfono de la persona " << i + 1 << ": ";
        getline(cin, personas[i].telefono);
    }
    // Abrir el archivo en modo de escritura
    ofstream archivo(nombreArchivo);
    if (archivo) {
        // Escribir los datos de las personas en el archivo
        for (int i = 0; i < numPersonas; ++i) {
            archivo << personas[i].nombre << endl;
            archivo << personas[i].telefono << endl;
        }
        archivo.close();
        cout << "Datos guardados exitosamente en " << nombreArchivo << "." << endl;
    }
    else {
        cout << "Error: No se pudo abrir el archivo para escribir." << endl;
    }
}
int main() {
    const string nombreArchivo = "personas.txt";
    // Guardar los datos de las personas en el archivo
    guardarPersonas(nombreArchivo);
    return 0;  // Salir con éxito
}
