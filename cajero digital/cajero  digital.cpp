#include<iostream>
#include<iomanip>
using namespace std;  
//funciones 
bool autenticar();
void mostrarmenu();
void menu_cuenta_actual();
void ahorros_cuenta(double balance);
void extraer(double& balance, double ammount);
int main() {
	if (autenticar()) {
		mostrarmenu();
	}
	else {
		cout << "autentificacion fallida, saliendo..." << endl;
	}
	return 0;
}
//para autenticar segun la contraseña
bool autenticar() {
	string contraseña;
	cout << "ingrese su contraseña: ";
	cin >> contraseña;
	//simulador de comprobacion de contraseña
	if (contraseña == "12345") {
		cout << "autentificacion exitosa, bienvenido";
		return true;
	}
	else {
		cout << "error, intente de nuevo";
		return false;
	}
}
//mostrar menu
void mostrarmenu() {
	int eleccion;
    double balance = 1000.0; // Balance inicial
		do {
			cout << "\n menu principal \n";
			cout << "1. ver cuenta" << endl; 
			cout << "2. ver ahorros" << endl;
			cout << "3. salir" << endl;
			cout << "ingrese la opcion que desee" << endl;
			cin >> eleccion;
            switch (eleccion) {
            case 1:
                menu_cuenta_actual();
                break;
            case 2:
                ahorros_cuenta(balance);
                break;
            case 3:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida, intente de nuevo." << endl;
            }
        } while (eleccion != 3);
}
// Mostrar informacion de la cuenta actual
void menu_cuenta_actual() {
    cout << "\nInformacion de la cuenta actual:" << endl;
    cout << "Titular: Juan Perez" << endl;
    cout << "Numero de cuenta: 123-456-789" << endl;
    cout << "Balance actual: $1000.00" << endl;
}
// Mostrar informacion de ahorros
void ahorros_cuenta(double balance) {
    cout << "\nInformacion de ahorros:" << endl;
    cout << "Balance actual: $" << fixed << setprecision(2) << balance << endl;
    double cantidad;
    cout << "Ingrese la cantidad que desea extraer: ";
    cin >> cantidad;
    if (cantidad > 0 && cantidad <= balance) {
        extraer(balance, cantidad);
        cout << "Extraccion exitosa. Balance restante: $" << fixed << setprecision(2) << balance << endl;
    }
    else {
        cout << "Cantidad inv\u00e1lida o insuficiente." << endl;
    }
}
// Extraer dinero de la cuenta
void extraer(double& balance, double amount) {
    balance -= amount;
}
