#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <thread>
using namespace std;
void displayTime() {
    while (true) {
        // Obtener el tiempo actual del sistema
        auto now = chrono::system_clock::now();
        time_t currentTime = chrono::system_clock::to_time_t(now);
        tm localTime{}; // Estructura para almacenar la hora local
        // Usar localtime_s para convertir el tiempo a la hora local
        localtime_s(&localTime, &currentTime);
        // Limpiar la consola (en Windows usa "cls", en Linux/Mac usa "clear")
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        // Dibujar el marco del reloj
        cout << "=========================" << endl;
        cout << "|    Reloj Digital      |" << endl;
        cout << "=========================" << endl;
        // Mostrar la hora en formato HH:MM:SS
        cout << "|     "
            << setw(2) << setfill('0') << localTime.tm_hour << ":" // Mostrar horas
            << setw(2) << setfill('0') << localTime.tm_min << ":"  // Mostrar minutos
            << setw(2) << setfill('0') << localTime.tm_sec         // Mostrar segundos
            << "      |" << endl;
        cout << "=========================" << endl;
        // Esperar un segundo antes de actualizar el reloj
        this_thread::sleep_for(chrono::seconds(1));
    }
}
int main() {
    displayTime(); // Llamar a la funcion para mostrar el reloj
    return 0;
}
