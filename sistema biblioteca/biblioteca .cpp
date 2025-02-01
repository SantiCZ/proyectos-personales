#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Definicion de la estructura para un libro
struct Libro {
    string titulo;
    string autor;
    int id;
    bool disponible;
};
// Clase para la gestion de la biblioteca
class Biblioteca {
private:
    vector<Libro> catalogo;
public:
    // Metodo para agregar un libro al catalogo
    void agregarLibro(string titulo, string autor, int id) {
        Libro nuevoLibro = { titulo, autor, id, true };
        catalogo.push_back(nuevoLibro);
        cout << "Libro agregado con exito." << endl;
    }
    // Metodo para mostrar todos los libros en el catalogo 
    void mostrarLibros() {
        for (const auto& libro : catalogo) {
            cout << "ID: " << libro.id << " | Titulo: " << libro.titulo << " | Autor: " << libro.autor << " | Disponible: " << (libro.disponible ? "Si" : "No") << endl;
        }
    }
    // Metodo para prestar un libro
    void prestarLibro(int id) {
        for (auto& libro : catalogo) {
            if (libro.id == id) {
                if (libro.disponible) {
                    libro.disponible = false;
                    cout << "Libro prestado con exito." << endl;
                }
                else {
                    cout << "El libro ya esta prestado." << endl;
                }
                return;
            }
        }
        cout << "Libro no encontrado." << endl;
    }

    // Metodo para devolver un libro
    void devolverLibro(int id) {
        for (auto& libro : catalogo) {
            if (libro.id == id) {
                if (!libro.disponible) {
                    libro.disponible = true;
                    cout << "Libro devuelto con exito." << endl;
                }
                else {
                    cout << "El libro ya estaba disponible." << endl;
                }
                return;
            }
        }
        cout << "Libro no encontrado." << endl;
    }
};
int main() {
    Biblioteca miBiblioteca;
    int opcion, id;
    string titulo, autor;
    do {
        // Menu de opciones
        cout << "\nSistema de Gestion de Biblioteca" << endl;
        cout << "1. Agregar libro" << endl;
        cout << "2. Mostrar libros" << endl;
        cout << "3. Prestar libro" << endl;
        cout << "4. Devolver libro" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion) {
        case 1:
            cout << "Ingrese el titulo del libro: ";
            cin.ignore(); // Limpiar buffer
            getline(cin, titulo);
            cout << "Ingrese el autor del libro: ";
            getline(cin, autor);
            cout << "Ingrese el ID del libro: ";
            cin >> id;
            miBiblioteca.agregarLibro(titulo, autor, id);
            break;
        case 2:
            miBiblioteca.mostrarLibros();
            break;
        case 3:
            cout << "Ingrese el ID del libro a prestar: ";
            cin >> id;
            miBiblioteca.prestarLibro(id);
            break;
        case 4:
            cout << "Ingrese el ID del libro a devolver: ";
            cin >> id;
            miBiblioteca.devolverLibro(id);
            break;
        case 5:
            cout << "Saliendo del sistema..." << endl;
            break;
        default:
            cout << "Opcion no valida, intente de nuevo." << endl;
        }
    } while (opcion != 5);
    return 0;
}
