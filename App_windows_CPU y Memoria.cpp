#include "framework.h" // Incluye el marco de trabajo de Windows
#include "appwindowspqsi.h" // Incluye el archivo de encabezado especifico de la aplicacion
#include <windows.h> // Incluye las definiciones principales de la API de Windows
#include <pdh.h> // Incluye las funciones para el monitor de rendimiento
#include <pdhmsg.h> // Incluye mensajes de error para PDH

#pragma comment(lib, "pdh.lib") // Vincula automaticamente la biblioteca PDH

#define MAX_LOADSTRING 100 // Define el tamano maximo de las cadenas de texto

// Variables globales:
HINSTANCE hInst; // Maneja la instancia actual de la aplicacion
WCHAR szTitle[MAX_LOADSTRING]; // Almacena el texto de la barra de titulo
WCHAR szWindowClass[MAX_LOADSTRING]; // Nombre de la clase de la ventana principal

// Declaraciones de funciones adelantadas incluidas en este modulo de codigo:
ATOM                MyRegisterClass(HINSTANCE hInstance); // Registra la clase de ventana
BOOL                InitInstance(HINSTANCE, int); // Inicializa una instancia de ventana
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM); // Procedimiento de la ventana principal
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM); // Procedimiento del cuadro "Acerca de"

// Variables para monitor de recursos
PDH_HQUERY cpuQuery; // Consulta para el uso de la CPU
PDH_HCOUNTER cpuTotal; // Contador para el total de uso de CPU
MEMORYSTATUSEX memInfo; // Estructura para obtener el estado de la memoria
ULONGLONG totalPhysMem; // Memoria fisica total disponible

void InitResourceMonitor() {
    PdhOpenQuery(NULL, 0, &cpuQuery); // Abre una consulta de PDH
    PdhAddCounter(cpuQuery, L"\\Processor(_Total)\\% Processor Time", 0, &cpuTotal); // Agrega un contador de uso de CPU
    memInfo.dwLength = sizeof(MEMORYSTATUSEX); // Define el tamano de la estructura
    GlobalMemoryStatusEx(&memInfo); // Obtiene informacion sobre la memoria
    totalPhysMem = memInfo.ullTotalPhys; // Almacena la memoria fisica total
}

void GetResourceUsage(double& cpuUsage, double& memoryUsage) {
    PDH_FMT_COUNTERVALUE counterVal; // Almacena el valor formateado del contador
    PdhCollectQueryData(cpuQuery); // Recoge datos de la consulta
    PdhGetFormattedCounterValue(cpuTotal, PDH_FMT_DOUBLE, NULL, &counterVal); // Obtiene el valor de la CPU
    cpuUsage = counterVal.doubleValue; // Asigna el uso de CPU

    GlobalMemoryStatusEx(&memInfo); // Actualiza la informacion de la memoria
    memoryUsage = ((double)(memInfo.ullTotalPhys - memInfo.ullAvailPhys) / totalPhysMem) * 100.0; // Calcula el uso de memoria
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance); // No se utiliza hPrevInstance
    UNREFERENCED_PARAMETER(lpCmdLine); // No se utiliza lpCmdLine

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING); // Carga el titulo de la aplicacion
    LoadStringW(hInstance, IDC_APPWINDOWSPQSI, szWindowClass, MAX_LOADSTRING); // Carga el nombre de la clase de ventana
    MyRegisterClass(hInstance); // Registra la clase de ventana

    if (!InitInstance(hInstance, nCmdShow)) { // Inicializa la ventana principal
        return FALSE; // Si falla, retorna falso
    }

    InitResourceMonitor(); // Inicializa el monitor de recursos

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_APPWINDOWSPQSI)); // Carga los aceleradores
    MSG msg; // Estructura para mensajes

    while (GetMessage(&msg, nullptr, 0, 0)) { // Bucle principal de mensajes
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) { // Traduce aceleradores
            TranslateMessage(&msg); // Traduce el mensaje
            DispatchMessage(&msg); // Despacha el mensaje
        }
    }

    PdhCloseQuery(cpuQuery); // Cierra la consulta PDH
    return (int)msg.wParam; // Retorna el codigo de salida
}

ATOM MyRegisterClass(HINSTANCE hInstance) {
    WNDCLASSEXW wcex; // Estructura para registrar la clase de ventana

    wcex.cbSize = sizeof(WNDCLASSEX); // Tamano de la estructura
    wcex.style = CS_HREDRAW | CS_VREDRAW; // Estilo de redibujado
    wcex.lpfnWndProc = WndProc; // Procedimiento de la ventana
    wcex.cbClsExtra = 0; // Memoria extra para la clase
    wcex.cbWndExtra = 0; // Memoria extra para la ventana
    wcex.hInstance = hInstance; // Instancia de la aplicacion
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPWINDOWSPQSI)); // Icono grande
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW); // Cursor predeterminado
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // Color de fondo
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_APPWINDOWSPQSI); // Menu asociado
    wcex.lpszClassName = szWindowClass; // Nombre de la clase
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL)); // Icono pequeno

    return RegisterClassExW(&wcex); // Registra la clase de ventana
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) {
    hInst = hInstance; // Almacena la instancia

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, // Crea la ventana principal
        CW_USEDEFAULT, 0, 800, 600, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd) { // Verifica si la ventana fue creada
        return FALSE; // Si falla, retorna falso
    }

    ShowWindow(hWnd, nCmdShow); // Muestra la ventana
    UpdateWindow(hWnd); // Actualiza la ventana

    return TRUE; // Retorna verdadero si se inicializo correctamente
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    static double cpuUsage = 0.0; // Almacena el uso de CPU
    static double memoryUsage = 0.0; // Almacena el uso de memoria

    switch (message) {
    case WM_COMMAND: { // Maneja comandos del menu o controles
        int wmId = LOWORD(wParam); // Identifica el comando
        switch (wmId) {
        case IDM_ABOUT: // Caso para "Acerca de"
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About); // Muestra el cuadro de dialogo "Acerca de"
            break;
        case IDM_EXIT: // Caso para salir
            DestroyWindow(hWnd); // Cierra la ventana
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam); // Procesa otros comandos
        }
    } break;

    case WM_PAINT: { // Maneja el evento de repintado
        PAINTSTRUCT ps; // Estructura de pintura
        HDC hdc = BeginPaint(hWnd, &ps); // Comienza la pintura

        GetResourceUsage(cpuUsage, memoryUsage); // Obtiene el uso de recursos

        wchar_t buffer[256]; // Almacena el texto a mostrar
        swprintf_s(buffer, L"CPU Usage: %.2f%%", cpuUsage);
        TextOut(hdc, 10, 10, buffer, (int)wcslen(buffer)); // Dibuja el texto de CPU

        swprintf_s(buffer, L"Memory Usage: %.2f%%", memoryUsage);
        TextOut(hdc, 10, 30, buffer, (int)wcslen(buffer)); // Dibuja el texto de memoria en un renglon diferente

        EndPaint(hWnd, &ps); // Finaliza la pintura
    } break;

    case WM_DESTROY: // Maneja el evento de destruccion de ventana 
        PostQuitMessage(0); // Envia un mensaje de salida  
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam); // Procesa otros mensajes 
    }
    return 0;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
    UNREFERENCED_PARAMETER(lParam); // No se utiliza lParam 
    switch (message) {
    case WM_INITDIALOG:  // Inicializa el cuadro de dialogo
        return (INT_PTR)TRUE;

    case WM_COMMAND:  // Maneja comandos en el cuadro de dialogo
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) { // Si se presiona Aceptar o Cancelar 
            EndDialog(hDlg, LOWORD(wParam)); // Cierra el cuadro de dialogo 
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
