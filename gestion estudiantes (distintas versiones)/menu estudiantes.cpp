#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Clase que representa a un estudiante
class Estudiante {
private:
    string nombre; // Nombre del estudiante
    vector<float> calificaciones; // Lista de calificaciones del estudiante

public:
    // Constructor para inicializar el nombre del estudiante
    Estudiante(string nombre) {
        this->nombre = nombre;
    }

    // Metodo para agregar una calificacion a la lista
    void agregarCalificacion(float calificacion) {
        calificaciones.push_back(calificacion);
    }

    // Metodo para obtener el nombre del estudiante
    string getNombre() {
        return nombre;
    }

    // Metodo para calcular el promedio de las calificaciones
    float calcularPromedio() {
        float suma = 0;
        // Sumar todas las calificaciones
        for (float calificacion : calificaciones) {
            suma += calificacion;
        }
        // Si no hay calificaciones, el promedio es 0
        return calificaciones.empty() ? 0 : suma / calificaciones.size();
    }

    // Metodo para mostrar el reporte del estudiante
    void mostrarReporte() {
        cout << "Estudiante: " << nombre << endl;
        cout << "Calificaciones: ";
        // Mostrar todas las calificaciones
        for (float calificacion : calificaciones) {
            cout << calificacion << " ";
        }
        cout << endl;
        // Mostrar el promedio de las calificaciones
        cout << "Promedio: " << calcularPromedio() << endl;
    }
};

// Clase que gestiona a los estudiantes
class SistemaGestionEstudiantes {
private:
    vector<Estudiante> estudiantes; // Lista de estudiantes

public:
    // Metodo para agregar un nuevo estudiante
    void agregarEstudiante(string nombre) {
        estudiantes.push_back(Estudiante(nombre));
    }

    // Metodo para agregar calificaciones a un estudiante
    void agregarCalificacionesAEstudiante(string nombre) {
        // Buscar el estudiante por nombre
        for (Estudiante& estudiante : estudiantes) {
            if (estudiante.getNombre() == nombre) {
                float calificacion;
                cout << "Ingrese las calificaciones para " << nombre << " (ingrese -1 para terminar): " << endl;
                while (true) {
                    cout << "Ingrese calificacion: ";
                    cin >> calificacion;
                    if (calificacion == -1) break; // Termina el ingreso de calificaciones
                    estudiante.agregarCalificacion(calificacion);
                }
                break;
            }
        }
    }

    // Metodo para mostrar los reportes de todos los estudiantes
    void mostrarReportes() {
        // Mostrar el reporte de cada estudiante
        if (estudiantes.empty()) {
            cout << "No hay estudiantes registrados." << endl;
            return;
        }
        for (Estudiante& estudiante : estudiantes) {
            estudiante.mostrarReporte();
            cout << "---------------------------------" << endl;
        }
    }

    // Metodo para mostrar el promedio de un estudiante
    void mostrarPromedioEstudiante() {
        string nombre;
        cout << "Ingrese el nombre del estudiante para ver su promedio: ";
        cin.ignore(); // Limpiar buffer
        getline(cin, nombre);
        for (Estudiante& estudiante : estudiantes) {
            if (estudiante.getNombre() == nombre) {
                cout << "Promedio de " << nombre << ": " << estudiante.calcularPromedio() << endl;
                return;
            }
        }
        cout << "Estudiante no encontrado." << endl;
    }

    // Metodo para verificar si hay estudiantes registrados
    bool tieneEstudiantes() {
        return !estudiantes.empty();
    }
};

// Función para mostrar el menú y capturar la opción seleccionada
int mostrarMenu() {
    int opcion;
    cout << "\nMenu de opciones:\n";
    cout << "1. Agregar estudiante\n";
    cout << "2. Agregar calificaciones a un estudiante\n";
    cout << "3. Mostrar reportes de estudiantes\n";
    cout << "4. Consultar promedio de un estudiante\n";
    cout << "5. Salir\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    return opcion;
}

int main() {
    SistemaGestionEstudiantes sistema;
    string nombreEstudiante;
    int opcion;

    do {
        opcion = mostrarMenu();
        switch (opcion) {
        case 1: {
            cout << "Ingrese el nombre del nuevo estudiante: ";
            cin.ignore();  // Limpiar el buffer de entrada
            getline(cin, nombreEstudiante); // Leer el nombre del estudiante
            sistema.agregarEstudiante(nombreEstudiante);
            cout << "Estudiante agregado exitosamente.\n";
            break;
        }
        case 2: {
            if (sistema.tieneEstudiantes()) {
                cout << "Ingrese el nombre del estudiante para agregar calificaciones: ";
                cin.ignore(); // Limpiar buffer
                getline(cin, nombreEstudiante); // Leer el nombre del estudiante
                sistema.agregarCalificacionesAEstudiante(nombreEstudiante);
            }
            else {
                cout << "No hay estudiantes registrados.\n";
            }
            break;
        }
        case 3: {
            sistema.mostrarReportes();
            break;
        }
        case 4: {
            if (sistema.tieneEstudiantes()) {
                sistema.mostrarPromedioEstudiante();
            }
            else {
                cout << "No hay estudiantes registrados.\n";
            }
            break;
        }
        case 5:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion invalida, por favor intente nuevamente.\n";
        }
    } while (opcion != 5);

    return 0;
}
