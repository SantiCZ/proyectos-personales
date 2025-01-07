#include <iostream>  
#include <fstream>   
#include <vector>    
#include <string>    
#include <sstream>   
using namespace std;
// Estructura para almacenar la informacion de un contacto, solo usa 3 datos pero se puede hacer con cualquier numero de datos segun sea necesario
struct Contacto {
    string nombre;
    string telefono;
    string email;
};
// Funcion para guardar los contactos en un archivo
void guardarContactos(const vector<Contacto>& contactos) {
    ofstream archivo("agenda.txt"); // Abre el archivo en modo escritura
    if (archivo.is_open()) {  // Verifica si el archivo se abrio correctamente
        for (const auto& c : contactos) {  // Recorre el vector de contactos
            archivo << c.nombre << "," << c.telefono << "," << c.email << endl; // Escribe cada contacto en el archivo
        }
        archivo.close();  // Cierra el archivo
    }
    else {
        cout << "Error al guardar los contactos." << endl;  // Mensaje de error si no se pudo abrir el archivo
    }
}
// Funcion para cargar los contactos desde un archivo
vector<Contacto> cargarContactos() {
    vector<Contacto> contactos;  // Vector para almacenar los contactos
    ifstream archivo("agenda.txt");  // Abre el archivo en modo lectura
    string linea, nombre, telefono, email;
    if (archivo.is_open()) {  // Verifica si el archivo se abrio correctamente
        while (getline(archivo, linea)) {  // Lee cada linea del archivo
            stringstream ss(linea);  // Convierte la linea en un flujo de datos
            getline(ss, nombre, ',');  // Extrae el nombre
            getline(ss, telefono, ',');  // Extrae el telefono
            getline(ss, email, ',');  // Extrae el email
            contactos.push_back({ nombre, telefono, email });  // Agrega el contacto al vector
        }
        archivo.close();  // Cierra el archivo
    }
    return contactos;  // Retorna el vector con los contactos cargados
}
// Funcion para agregar un nuevo contacto
void agregarContacto(vector<Contacto>& contactos) {
    Contacto nuevo;  // Crea un nuevo contacto
    cout << "Nombre: ";
    cin.ignore();  // Limpia el buffer del teclado
    getline(cin, nuevo.nombre);  // Captura el nombre
    cout << "Telefono: ";
    getline(cin, nuevo.telefono);  // Captura el telefono
    cout << "Email: ";
    getline(cin, nuevo.email);  // Captura el email
    contactos.push_back(nuevo);  // Agrega el nuevo contacto al vector
    guardarContactos(contactos);  // Guarda los contactos en el archivo
    cout << "Contacto agregado con exito!\n";
}
// Funcion para buscar un contacto por nombre
void buscarContacto(const vector<Contacto>& contactos) {
    string nombre;
    cout << "Ingrese el nombre a buscar: ";
    cin.ignore();  // Limpia el buffer del teclado
    getline(cin, nombre);  // Captura el nombre a buscar
    for (const auto& c : contactos) {  // Recorre la lista de contactos
        if (c.nombre == nombre) {  // Si encuentra el contacto
            cout << "📌 Nombre: " << c.nombre << "\n📞 Telefono: " << c.telefono << "\n📧 Email: " << c.email << endl;
            return;  // Termina la busqueda
        }
    }
    cout << "Contacto no encontrado.\n";  // Mensaje si no se encuentra el contacto
}
// Funcion para editar un contacto existente
void editarContacto(vector<Contacto>& contactos) {
    string nombre;
    cout << "Ingrese el nombre del contacto a editar: ";
    cin.ignore();  // Limpia el buffer del teclado
    getline(cin, nombre);  // Captura el nombre a editar
    for (auto& c : contactos) {  // Recorre la lista de contactos
        if (c.nombre == nombre) {  // Si encuentra el contacto
            cout << "Nuevo telefono: ";
            getline(cin, c.telefono);  // Captura el nuevo telefono
            cout << "Nuevo email: ";
            getline(cin, c.email);  // Captura el nuevo email
            guardarContactos(contactos);  // Guarda los cambios en el archivo
            cout << "Contacto actualizado!\n";
            return;
        }
    }
    cout << "Contacto no encontrado.\n";  // Mensaje si no se encuentra el contacto
}
// Funcion para eliminar un contacto
void eliminarContacto(vector<Contacto>& contactos) {
    string nombre;
    cout << "Ingrese el nombre del contacto a eliminar: ";
    cin.ignore();  // Limpia el buffer del teclado
    getline(cin, nombre);  // Captura el nombre del contacto a eliminar
    for (auto it = contactos.begin(); it != contactos.end(); ++it) {  // Recorre la lista de contactos
        if (it->nombre == nombre) {  // Si encuentra el contacto
            contactos.erase(it);  // Elimina el contacto del vector
            guardarContactos(contactos);  // Guarda los cambios en el archivo
            cout << "Contacto eliminado!\n";
            return;
        }
    }
    cout << "Contacto no encontrado.\n";  // Mensaje si no se encuentra el contacto
}
// Funcion para mostrar todos los contactos
void mostrarContactos(const vector<Contacto>& contactos) {
    if (contactos.empty()) {  // Verifica si la lista de contactos esta vacia
        cout << "La agenda esta vacia.\n";
        return;
    }
    cout << "📒 Contactos guardados:\n";
    for (const auto& c : contactos) {  // Recorre la lista de contactos
        cout << "📌 " << c.nombre << " - " << c.telefono << " - " << c.email << endl;
    }
}
// Funcion principal con menu interactivo
int main() {
    vector<Contacto> contactos = cargarContactos();  // Carga los contactos desde el archivo
    int opcion;
    do {
        // Muestra el menu de opciones
        cout << "\n--- 📖 AGENDA DE CONTACTOS ---\n";
        cout << "1. Agregar contacto\n";
        cout << "2. Buscar contacto\n";
        cout << "3. Editar contacto\n";
        cout << "4. Eliminar contacto\n";
        cout << "5. Mostrar todos los contactos\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;  // Captura la opcion del usuario
        switch (opcion) {  // Ejecuta la opcion seleccionada
        case 1: agregarContacto(contactos); break;
        case 2: buscarContacto(contactos); break;
        case 3: editarContacto(contactos); break;
        case 4: eliminarContacto(contactos); break;
        case 5: mostrarContactos(contactos); break;
        case 6: cout << "Saliendo...\n"; break;
        default: cout << "Opcion invalida. Intente de nuevo.\n";  // Manejo de opcion incorrecta
        }
    } while (opcion != 6);  // Repite el menu hasta que el usuario elija salir
    return 0;  // Fin del programa
}
