#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// Funcion para generar una contrasena aleatoria segun los criterios especificados
string generarContrasena(int longitud, bool incluirMayusculas, bool incluirMinusculas, bool incluirNumeros, bool incluirSimbolos) {
    // Definicion de los caracteres disponibles
    string mayusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string minusculas = "abcdefghijklmnopqrstuvwxyz";
    string numeros = "0123456789";
    string simbolos = "!@#$%^&*()-_=+[]{}|;:'\",.<>?/";
    string caracteresPermitidos;
    // Agregar los tipos de caracteres seleccionados por el usuario
    if (incluirMayusculas) caracteresPermitidos += mayusculas;
    if (incluirMinusculas) caracteresPermitidos += minusculas;
    if (incluirNumeros) caracteresPermitidos += numeros;
    if (incluirSimbolos) caracteresPermitidos += simbolos;
    // Verificar que al menos un tipo de caracter haya sido seleccionado
    if (caracteresPermitidos.empty()) {
        return "Error: Debes seleccionar al menos un tipo de caracter.";
    }
    string contrasena;
    srand(time(nullptr)); // Inicializar la semilla del generador de numeros aleatorios
    // Generar la contrasena seleccionando caracteres aleatorios
    for (int i = 0; i < longitud; ++i) {
        contrasena += caracteresPermitidos[rand() % caracteresPermitidos.length()];
    }
    return contrasena;
}
int main() { 
    int longitud; 
    bool incluirMayusculas, incluirMinusculas, incluirNumeros, incluirSimbolos; 
    // Solicitar al usuario la configuracion de la contrasena
    cout << "Ingrese la longitud de la contrasena: ";
    cin >> longitud; 
    cout << "Incluir mayusculas? (1 = Si, 0 = No): ";
    cin >> incluirMayusculas;
    cout << "Incluir minusculas? (1 = Si, 0 = No): ";
    cin >> incluirMinusculas;
    cout << "Incluir numeros? (1 = Si, 0 = No): ";
    cin >> incluirNumeros;
    cout << "Incluir simbolos? (1 = Si, 0 = No): ";
    cin >> incluirSimbolos;
    // Generar y mostrar la contrasena resultante
    string contrasena = generarContrasena(longitud, incluirMayusculas, incluirMinusculas, incluirNumeros, incluirSimbolos);
    cout << "Contrasena generada: " << contrasena << endl;
    return 0;
}