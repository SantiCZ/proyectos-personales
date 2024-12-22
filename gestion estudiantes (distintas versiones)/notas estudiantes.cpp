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
        for (Estudiante& estudiante : estudiantes) {
            estudiante.mostrarReporte();
            cout << "---------------------------------" << endl;
        }
    }
};

int main() {
    SistemaGestionEstudiantes sistema;
    string nombreEstudiante;
    int cantidadEstudiantes;

    // Pedir la cantidad de estudiantes
    cout << "Ingrese el numero de estudiantes: ";
    cin >> cantidadEstudiantes;

    // Agregar estudiantes
    for (int i = 0; i < cantidadEstudiantes; ++i) {
        cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
        cin.ignore();  // Limpiar el buffer de entrada
        getline(cin, nombreEstudiante); // Leer el nombre del estudiante
        sistema.agregarEstudiante(nombreEstudiante);
    }

    // Agregar calificaciones para cada estudiante
    for (int i = 0; i < cantidadEstudiantes; ++i) {
        sistema.agregarCalificacionesAEstudiante(nombreEstudiante);
    }

    // Mostrar los reportes de todos los estudiantes
    sistema.mostrarReportes();

    return 0;
}
