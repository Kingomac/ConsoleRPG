#include <iostream>
#include <fstream>
#include <string>
#include "estructuras.h"

using namespace std;

void cargarPersonajes(Personaje p[], int lineas, string archivo)
{
    ifstream ifs;
    ifs.open(archivo);
    if (ifs.fail())
    {
        cout << "Error con el archivo " << archivo << endl;
        exit(1);
    }
    char dato[100];
    for (int linea = 0; linea < lineas; linea++)
    {
        for (int columna = 1; columna < 25; columna++)
        {
            if (columna < 24)
                ifs.getline(dato, 100, ';');
            else
                ifs.getline(dato, 100, '\n');
            switch (columna)
            {
            case 1:
                p[linea].nombre = dato;
                break;
            case 2:
                p[linea].nivel = atoi(dato);
                break;
            case 3:
                p[linea].salud = atoi(dato);
                p[linea].saludTotal = atoi(dato);
                break;
            case 4:
                p[linea].ataques[0].nombre = dato;
                break;
            case 5:
                p[linea].ataques[0].fuerza = atoi(dato);
                break;
            case 6:
                p[linea].ataques[0].fisico = dato[0] == 't' ? true : false;
                break;
            case 7:
                p[linea].ataques[0].usos = atoi(dato);
                p[linea].ataques[0].usosTotales = atoi(dato);
                break;
            case 8:
                p[linea].ataques[1].nombre = dato;
                break;
            case 9:
                p[linea].ataques[1].fuerza = atoi(dato);
                break;
            case 10:
                p[linea].ataques[1].fisico = dato[0] == 't' ? true : false;
                break;
            case 11:
                p[linea].ataques[1].usos = atoi(dato);
                p[linea].ataques[1].usosTotales = atoi(dato);
                break;
            case 12:
                p[linea].ataques[2].nombre = dato;
                break;
            case 13:
                p[linea].ataques[2].fuerza = atoi(dato);
                break;
            case 14:
                p[linea].ataques[2].fisico = dato[0] == 't' ? true : false;
                break;
            case 15:
                p[linea].ataques[2].usos = atoi(dato);
                p[linea].ataques[2].usosTotales = atoi(dato);
                break;
            case 16:
                p[linea].ataques[3].nombre = dato;
                break;
            case 17:
                p[linea].ataques[3].fuerza = atoi(dato);
                break;
            case 18:
                p[linea].ataques[3].fisico = dato[0] == 't' ? true : false;
                break;
            case 19:
                p[linea].ataques[3].usos = atoi(dato);
                p[linea].ataques[3].usosTotales = atoi(dato);
                break;
            case 20:
                p[linea].velocidad = atoi(dato);
                break;
            case 21:
                p[linea].ataqueF = atoi(dato);
                break;
            case 22:
                p[linea].defensaF = atoi(dato);
                break;
            case 23:
                p[linea].ataqueM = atoi(dato);
                break;
            case 24:
                p[linea].defensaM = atoi(dato);
            }
        }
    }
    ifs.close();
    cout << "El archivo " << archivo << " se ha cargado" << endl;
}
