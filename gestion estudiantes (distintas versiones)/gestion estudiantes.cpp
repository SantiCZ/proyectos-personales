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
    void agregarCalificacionesAEstudiante(string nombre, vector<float> calificaciones) {
        // Buscar el estudiante por nombre y agregar las calificaciones
        for (Estudiante& estudiante : estudiantes) {
            if (estudiante.getNombre() == nombre) {
                for (float cal : calificaciones) {
                    estudiante.agregarCalificacion(cal);
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
    // Crear una instancia del sistema de gestion
    SistemaGestionEstudiantes sistema;
    // Agregar estudiantes, debe ser con nombre y apellido
    sistema.agregarEstudiante("Juan Perez");
    sistema.agregarEstudiante("Maria Lopez");
    // Agregar calificaciones a los estudiantes
    sistema.agregarCalificacionesAEstudiante("Juan Perez", { 7.5, 8.0, 9.0 });
    sistema.agregarCalificacionesAEstudiante("Maria Lopez", { 6.5, 7.0, 8.5, 9.0 });
    // Mostrar los reportes de los estudiantes
    sistema.mostrarReportes();
    return 0;
}
