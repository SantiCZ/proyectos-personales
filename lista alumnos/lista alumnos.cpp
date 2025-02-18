#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
int menu() {
    int x;
    system("cls");
    cout << "-----Bienvenidos----" << endl;
    cout << "1.Agregar" << endl;
    cout << "2.Leer" << endl;
    cout << "3.Buscar" << endl;
    cout << "4.Modificar" << endl;
    cout << "5.Salir" << endl;
    cout << "Ingrese la opcion: " << endl;
    cin >> x;
    return x;
}
bool verifica(string leg) {
    ifstream leer("ListaAlumnos.txt", ios::in);
    string Nom;
    string Leg;
    string Ape;
    leer >> Nom;
    while (!leer.eof()) {
        leer >> Ape;
        leer >> Leg;
        if (Leg == leg) {
            leer.close();
            return false;
        }
        leer >> Nom; //para q el archivo avance
    } 
    leer.close();
    return true; //esta permitido agregar en el archivo
}
void agregar(ofstream& alumno) {
    system("cls");
    string Nom;
    string Leg;
    string Ape;
    alumno.open("ListaAlumnos.txt", ios::out | ios::app);
    cout << "Nombre: ";
    cin >> Nom;
    cout << "Apellido: ";
    cin >> Ape;
    cout << "Legajo: ";
    cin >> Leg;
    if (verifica(Leg)) {
        alumno << Nom << " " << Ape << " " << Leg << "\n";
    }
    alumno.close();
}
void verRegistro(ifstream& lee) {
    system("cls");
    string nom;
    string leg;
    string ape;
    lee.open("ListaAlumnos.txt", ios::in);
    if (lee.is_open()) {
        cout << "---Lista de Alumnos---" << endl;
        lee >> nom;
        while (!lee.eof()) {
            lee >> ape;
            lee >> leg;
            cout << "Nombre---" << nom << endl;
            cout << "Apellido---" << ape << endl;
            cout << "Legajo---" << leg << endl;
            cout << "-----------" << endl;
            lee >> nom;
        }
        lee.close();
    }
    else {
        cout << "Error al abrir el archivo";
    }
    system("pause");
}
void buscar(ifstream& lee) {
    system("cls");
    lee.open("ListaAlumnos.txt", ios::in);
    string nom, ape, leg, legaux;
    bool encontrado = false;
    cout << "Ingrese el legajo: ";
    cin >> legaux;
    lee >> nom;
    while (!lee.eof() && !encontrado) {
        lee >> ape;
        lee >> leg;
        if (leg == legaux) {
            cout << "Nombre: " << nom << endl;
            cout << "Apellido: " << ape << endl;
            cout << "Legajo: " << leg << endl;
            cout << "-------------------" << endl;
            encontrado = true;
        }
        lee >> nom;
    }
    lee.close();
    if (!encontrado) {
        cout << "Dato no encontrado" << endl;
    }
    system("pause");
}
void modificar(ifstream& lee) {
    system("cls");
    string nom;
    string leg;
    string ape;
    string legaux;
    string nomaux; //modifica solo nombre
    lee.open("ListaAlumnos.txt", ios::in);
    ofstream aux("auxiliar.txt", ios::out);
    if (lee.is_open()) {
        cout << "Legajo: ";
        cin >> legaux;
        lee >> nom;
        while (!lee.eof()) {
            lee >> ape;
            cin >> leg;
            if (leg == legaux) {
                cout << "ingrese nuevo nombre:";
                cin >> nomaux;
                aux << nomaux << " " << ape << " " << " " << leg << "\n";
            }
            else {
                aux << nom << " " << ape << " " << " " << leg << "\n";
            }
            lee >> nom;
        }
        lee.close();
        aux.close();
    }
    else
        cout << "Error" << endl;
    remove("ListaAlumnos.txt");
    rename("auxiliar.txt", "ListaAlumnos.txt");
}
int main() {
    ofstream alumno;
    ifstream lee;
    int op;
    do {
        system("cls");
        op = menu();
        switch (op) {
        case 1:
            agregar(alumno);
            break;
        case 2:
            verRegistro(lee);
            break;
        case 3:
            buscar(lee);
            break;
        case 4:
            modificar(lee);
            break;
        }
    } while (op != 5);
    return 0;
}
