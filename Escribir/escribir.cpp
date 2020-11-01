#include <Windows.h>
#include <iostream>
#include <string>
#include "escribir.h"
#define TIEMPO_CARACTER 50
#define TIEMPO_LINEA 100

using namespace std;

void esperar(int tiempo)
{
    Sleep(tiempo);
}

void escribir(string mensaje)
{
    for (char &c : mensaje)
    {
        cout << c;
        esperar(TIEMPO_CARACTER);
    }
    cout << endl;
    esperar(TIEMPO_LINEA);
}

void color(int c) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, c);
}

void listaColores() {
    for(int i = 1; i < 255; i++)
    {
        color(i);
        cout << (i) << " - Prueba de colores" << endl;
    }
    color(colores::blancoMate);
}
