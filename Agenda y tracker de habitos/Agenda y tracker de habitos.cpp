#include "framework.h"  // Incluye el archivo de encabezado del framework
#include "Resource.h"  // Incluye el archivo de recursos
#include <vector>  // Incluye la biblioteca de vectores
#include <string>  // Incluye la biblioteca de cadenas
#include <fstream>  // Incluye la biblioteca de manejo de archivos
#include <sstream>  // Incluye la biblioteca de manejo de cadenas de caracteres
#include "archivo encabezado.cpp"  // Incluye el archivo con definiciones de encabezados
#include "app_habitos_origen.cpp"  // Incluye el archivo de origen de la aplicacion de habitos
#include<iostream> 
#define MAX_LOADSTRING 100  // Define el tamano maximo de las cadenas de texto
using namespace std;  // Usa el espacio de nombres estandar
// Variables globales:
HINSTANCE hInst;  // Instancia actual de la aplicacion
WCHAR szTitle[MAX_LOADSTRING];  // Texto de la barra de titulo
WCHAR szWindowClass[MAX_LOADSTRING];  // Nombre de clase de la ventana principal
// Variables globales para eventos y habitos
vector<Evento> eventos;  // Lista de eventos
vector<Habito> habitos;  // Lista de habitos
// Declaraciones de funciones adelantadas:
ATOM MyRegisterClass(HINSTANCE hInstance);  // Declara la funcion para registrar la clase de ventana
BOOL InitInstance(HINSTANCE, int);  // Declara la funcion para inicializar la instancia
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);  // Declara el procedimiento de la ventana
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);  // Declara el dialogo "Acerca de"
INT_PTR CALLBACK InputDialog(HWND, UINT, WPARAM, LPARAM);  // Declara el dialogo de entrada
// Funcion para agregar un nuevo evento
void AgregarEvento(const wstring& descripcion, const SYSTEMTIME& hora) {
    Evento nuevoEvento = { descripcion, hora };  // Crea un nuevo evento con la descripcion y hora proporcionadas
    eventos.push_back(nuevoEvento);  // Agrega el nuevo evento a la lista de eventos
}
// Funcion para agregar un nuevo habito
void AgregarHabito(const wstring& descripcion) {
    Habito nuevoHabito = { descripcion, false };  // Crea un nuevo habito con la descripcion proporcionada y no completado
    habitos.push_back(nuevoHabito);  // Agrega el nuevo habito a la lista de habitos
}
// Funcion para mostrar los eventos en la ventana principal
void MostrarEventos(HWND hWnd) {
    HDC hdc = GetDC(hWnd);  // Obtiene el contexto de dispositivo (DC) para la ventana
    int yPos = 50;  // Posicion inicial en el eje Y para mostrar los eventos
    for (const auto& evento : eventos) {  // Itera sobre la lista de eventos
        wstring texto = L"Evento: " + evento.descripcion;  // Crea la cadena que se mostrara para cada evento
        TextOut(hdc, 10, yPos, texto.c_str(), texto.length());  // Escribe el texto en la ventana en la posicion indicada
        yPos += 20;  // Aumenta la posicion Y para el siguiente evento
    }
    ReleaseDC(hWnd, hdc);  // Libera el contexto de dispositivo (DC)
}
// Funcion para mostrar los habitos en la ventana principal
void MostrarHabitos(HWND hWnd) {
    HDC hdc = GetDC(hWnd);  // Obtiene el contexto de dispositivo (DC) para la ventana
    int yPos = 200;  // Posicion inicial en el eje Y para mostrar los habitos
    for (const auto& habito : habitos) {  // Itera sobre la lista de habitos
        wstring texto = L"Habito: " + habito.descripcion + (habito.completado ? L" (Completado)" : L" (Pendiente)");  // Crea la cadena para mostrar el habito
        TextOut(hdc, 10, yPos, texto.c_str(), texto.length());  // Escribe el texto en la ventana en la posicion indicada
        yPos += 20;  // Aumenta la posicion Y para el siguiente habito
    }
    ReleaseDC(hWnd, hdc);  // Libera el contexto de dispositivo (DC)
}
// Funcion para guardar eventos y habitos en archivos
void GuardarDatos() {
    // Guarda los eventos en "eventos.txt"
    ofstream eventosFile("eventos.txt");
    for (const auto& evento : eventos) {
        eventosFile < evento.descripcion << "\n";
        eventosFile << evento.hora.wYear << " " << evento.hora.wMonth << " " << evento.hora.wDay << " "
            << evento.hora.wHour << " " << evento.hora.wMinute << " " << evento.hora.wSecond << "\n";
    }
    eventosFile.close();
    // Guarda los habitos en "habitos.txt"
    ofstream habitosFile("habitos.txt");
    for (const auto& habito : habitos) {
        habitosFile << habito.descripcion << "\n";
        habitosFile << habito.completado << "\n";
    }
    habitosFile.close();
}
// Funcion para cargar eventos y habitos desde archivos
void CargarDatos() {
    // Carga los eventos desde "eventos.txt"
    ifstream eventosFile("eventos.txt");
    if (eventosFile.is_open()) {
        while (!eventosFile.eof()) {
            wstring descripcion;
            getline(eventosFile, descripcion);
            if (descripcion.empty()) break;

            SYSTEMTIME hora;
            eventosFile >> hora.wYear >> hora.wMonth >> hora.wDay >> hora.wHour >> hora.wMinute >> hora.wSecond;
            eventosFile.ignore();  // Ignora el caracter de nueva linea
            AgregarEvento(descripcion, hora);
        }
        eventosFile.close();
    }
    // Carga los habitos desde "habitos.txt"
    ifstream habitosFile("habitos.txt");
    if (habitosFile.is_open()) {
        while (!habitosFile.eof()) {
            wstring descripcion;
            getline(habitosFile, descripcion);
            if (descripcion.empty()) break;
            bool completado;
            habitosFile >> completado;
            habitosFile.ignore();  // Ignora el caracter de nueva linea
            Habito nuevoHabito = { descripcion, completado };
            habitos.push_back(nuevoHabito);
        }
        habitosFile.close();
    }
}
// Funcion principal de la aplicacion
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR lpCmdLine,
    _In_ int nCmdShow) {
    UNREFERENCED_PARAMETER(hPrevInstance);  // No se utiliza hPrevInstance
    UNREFERENCED_PARAMETER(lpCmdLine);  // No se utiliza lpCmdLine
    // Inicializar cadenas globales con los recursos de la aplicacion
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_AGENDAYTRACKERDEHABITOS, szWindowClass, MAX_LOADSTRING);
    // Registrar la clase de la ventana
    MyRegisterClass(hInstance);
    // Inicializar la instancia de la aplicacion
    if (!InitInstance(hInstance, nCmdShow)) {
        return FALSE;  // Si falla la inicializacion, salir
    }
    // Cargar las tablas de aceleradores para atajos de teclado
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_AGENDAYTRACKERDEHABITOS));
    // Cargar datos desde archivos
    CargarDatos();
    MSG msg;  // Estructura para almacenar mensajes
    // Bucle principal de mensajes
    while (GetMessage(&msg, nullptr, 0, 0)) {
        // Traducir los mensajes de aceleradores (atajos de teclado)
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
            TranslateMessage(&msg);  // Traducir el mensaje a un formato adecuado
            DispatchMessage(&msg);   // Despachar el mensaje para ser procesado por WndProc
        }
    }
    // Guardar datos en archivos antes de salir
    GuardarDatos();
    return (int)msg.wParam;  // Retornar el codigo de salida
}
// Funcion para registrar la clase de la ventana
ATOM MyRegisterClass(HINSTANCE hInstance) {
    WNDCLASSEXW wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);  // Tamano de la estructura
    wcex.style = CS_HREDRAW | CS_VREDRAW;  // Establecer estilos para la clase de la ventana
    wcex.lpfnWndProc = WndProc;  // Funcion de procedimiento de la ventana
    wcex.cbClsExtra = 0;  // No se utilizan datos adicionales para la clase
    wcex.cbWndExtra = 0;  // No se utilizan datos adicionales para la ventana
    wcex.hInstance = hInstance;  // Instancia de la aplicacion
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_AGENDAYTRACKERDEHABITOS));  // Icono de la aplicacion
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);  // Cursor de la aplicacion
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);  // Fondo de la ventana
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_AGENDAYTRACKERDEHABITOS);  // Menu de la aplicacion
    wcex.lpszClassName = szWindowClass;  // Nombre de la clase de la ventana
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));  // Icono pequeño de la aplicacion
    return RegisterClassExW(&wcex);  // Registrar la clase de la ventana y retornar el resultado
}
// Funcion para inicializar la instancia de la aplicacion
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) {
    hInst = hInstance;  // Almacenar la instancia en la variable global
    // Crear la ventana principal
    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
    if (!hWnd) {
        return FALSE;  // Si falla la creacion de la ventana, retornar FALSE
    }
    ShowWindow(hWnd, nCmdShow);  // Mostrar la ventana
    UpdateWindow(hWnd);  // Actualizar la ventana
    return TRUE;  // Retornar TRUE indicando que la inicializacion fue exitosa
}
// Procedimiento de la ventana principal
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_COMMAND:  // Manejar los comandos de menu
    {
        int wmId = LOWORD(wParam);
        switch (wmId) {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:  // Manejar el repintado de la ventana
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: Aqui se deben agregar las instrucciones de dibujo
        MostrarEventos(hWnd);  // Mostrar los eventos en la ventana
        MostrarHabitos(hWnd);  // Mostrar los habitos en la ventana
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:  // Manejar la destruccion de la ventana
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
// Dialogo "Acerca de"
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
    UNREFERENCED_PARAMETER(lParam);
    switch (message) {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
// Dialogo de entrada
INT_PTR CALLBACK InputDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
    UNREFERENCED_PARAMETER(lParam);
    switch (message) {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK) {
            WCHAR inputText[256];
            GetDlgItemText(hDlg, IDC_INPUT_EDIT, inputText, 256);
            wstring descripcion(inputText);
            AgregarHabito(descripcion);  // Agregar un nuevo habito con el texto ingresado
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        else if (LOWORD(wParam) == IDCANCEL) {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}