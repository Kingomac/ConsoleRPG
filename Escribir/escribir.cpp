#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include "escribir.h"
#define TIEMPO_CARACTER 50
#define TIEMPO_LINEA 100

using namespace std;

void consolaColor(unsigned char c)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, c);
}

void escribir(string mensaje, unsigned char color, int esperarChar, int esperarLinea)
{
    if (color != 7)
        consolaColor(color);
    for (char &c : mensaje)
    {
        cout << c;
        Sleep(esperarChar);
    }
    consolaColor(7);
    Sleep(esperarLinea);
}

void escribirArchivo(string archivo, unsigned char color, int esperarChar, int esperarLinea)
{
    ifstream ifs(archivo);
    if (ifs.fail())
    {
        escribir("Error leyendo el archivo " + archivo + "\n");
        exit(1);
    }
    string a;
    while (!ifs.eof())
    {
        getline(ifs, a, '\n');
        escribir(a + "\n", color, esperarChar, esperarLinea);
    }
    ifs.close();
}

void listaColores()
{
    for (int i = 1; i < 255; i++)
    {
        consolaColor(i);
        cout << i << " - Prueba de colores" << endl;
    }
    consolaColor(7);
}
