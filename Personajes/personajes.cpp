#include <fstream>
#include <string>
#include "personajes.h"
#include "escribir.h"

using namespace std;


int nVivos(int n, Personaje p[])
{
    int suma = 0;
    for (int i = 0; i < n; i++)
        if (p[i].salud > 0)
            suma++;
    return suma;
}

int personajeAleatorioVivo(int n, Personaje p[])
{
    for (int i = 0; i < 2 * n; i++)
    {
        int a = rand() % n;
        if (p[a].salud > 0)
            return a;
    }
    return rand() % n;
}
void restablecerSalud(int n, Personaje p[])
{
    for (int i = 0; i < n; i++)
    {
        if (p[i].salud > 0)
        {
            p[i].salud = p[i].saludTotal;
            for (int j = 0; j < 4; j++)
                p[i].ataques[j].usos = p[i].ataques[j].usosTotales;
        }
    }
}

void mostrarEstadisticas(int n, Personaje p[])
{
    for (int i = 0; i < n; i++)
    {
        escribir("\n " + p[i].nombre + " | Salud: " + to_string(p[i].salud < 0 ? 0 : p[i].salud) + "/" + to_string(p[i].saludTotal) + " | Nivel: " + to_string(p[i].nivel) + " | Velocidad: " + to_string(p[i].velocidad) + " \n", 243 + i);
        escribir(" Ataque físico: " + to_string(p[i].ataqueF) + " | Defensa física: " + to_string(p[i].defensaF) + " \n", 243 + i);
        escribir(" Ataque mágico: " + to_string(p[i].ataqueM) + " | Defensa mágica: " + to_string(p[i].defensaM) + " \n", 243 + i);
        escribir(" Ataques: \n", 243 + i);
        for (int j = 0; j < 4; j++)
        {
            escribir("  " + to_string(j + 1) + " - " + p[i].ataques[j].nombre + " | " + to_string(p[i].ataques[j].usos) + "/" + to_string(p[i].ataques[j].usosTotales) + " | " + (p[i].ataques[j].fisico ? "Físico" : "Mágico") + " | Fuerza: " + to_string(p[i].ataques[j].fuerza) + " \n", 243 + i);
        }
    }
}

void cargarPersonajes(Personaje p[], int lineas, string archivo)
{
    ifstream ifs;
    ifs.open(archivo);
    if (ifs.fail())
    {
        escribir("Error con el archivo " + archivo + "\n", 79);
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
                p[linea].ataques[0].fisico = dato[0] == 't';
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
}
