

#include <windows.h>
#include <string>
#include <vector>

using namespace std;

struct Evento {
    wstring descripcion;
    SYSTEMTIME hora;
};

struct Habito {
    wstring descripcion;
    bool completado;
};

extern vector<Evento> eventos;
extern vector<Habito> habitos;

void AgregarEvento(const wstring& descripcion, const SYSTEMTIME& hora);
void AgregarHabito(const wstring& descripcion);
void MostrarEventos(HWND hWnd);
void MostrarHabitos(HWND hWnd);
