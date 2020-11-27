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

void escribir(string mensaje, unsigned char color = 7)
{
    if (color != 7)
        consolaColor(color);
    for (char &c : mensaje)
    {
        cout << c;
        esperar(TIEMPO_CARACTER);
    }
    cout << endl;
    consolaColor(7);
    esperar(TIEMPO_LINEA);
}

void consolaColor(unsigned char c)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, c);
}

void listaColores()
{
    for (unsigned char i = 1; i < 255; i++)
    {
        consolaColor(i);
        cout << int(i) << " - Prueba de colores" << endl;
    }
    consolaColor(7);
}
