#include <iostream>
using namespace std;
// Funciones de conversion
float kmToMiles(float km) { return km * 0.621371; }
float milesToKm(float miles) { return miles / 0.621371; }
float celsiusToFahrenheit(float c) { return (c * 9 / 5) + 32; }
float fahrenheitToCelsius(float f) { return (f - 32) * 5 / 9; }
void mostrarMenu() {
    cout << "\nConversor de unidades:" << endl;
    cout << "1. Kilometros a Millas" << endl;
    cout << "2. Millas a Kilometros" << endl;
    cout << "3. Celsius a Fahrenheit" << endl;
    cout << "4. Fahrenheit a Celsius" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: ";
}
int main() {
    int opcion;
    float valor;
    do {
        mostrarMenu();
        cin >> opcion;
        switch (opcion) {
        case 1:
            cout << "Ingrese los kilometros: ";
            cin >> valor;
            cout << valor << " km son " << kmToMiles(valor) << " millas." << endl;
            break;
        case 2:
            cout << "Ingrese las millas: ";
            cin >> valor;
            cout << valor << " millas son " << milesToKm(valor) << " km." << endl;
            break;
        case 3:
            cout << "Ingrese los grados Celsius: ";
            cin >> valor;
            cout << valor << "°C son " << celsiusToFahrenheit(valor) << "°F." << endl;
            break;
        case 4:
            cout << "Ingrese los grados Fahrenheit: ";
            cin >> valor;
            cout << valor << "°F son " << fahrenheitToCelsius(valor) << "°C." << endl;
            break;
        case 5:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);
    return 0;
}