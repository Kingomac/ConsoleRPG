#include <iostream>
#include "../estructuras.h"
#include "utilidades.h"
#include "escribir.h"
#include "../mapa.h"

using namespace std;

extern int mapa[FILAS_MAPA][COLUMNAS_MAPA];

void mostrarMapa(Posicion pos)
{
    escribir("\n");
    for (int i = 0; i < FILAS_MAPA; i++)
    {
        escribir("  ", 0, 1);
        for (int j = 0; j < COLUMNAS_MAPA; j++)
        {
            if (pos.fila == i && pos.columna == j)
            {
                escribir(" J ", 47, 0, 1);
            }
            else
            {
                switch (mapa[i][j])
                {
                case 0:
                    escribir("   ", 102, 0, 1);
                    break;
                case 1:
                    escribir("   ", 34, 0, 1);
                    break;
                case 2:
                    escribir("   ", 34, 0, 1);
                    break;
                case 3:
                    escribir("   ", 34, 0, 1);
                    break;
                case 4:
                    escribir(" C ", 95, 0, 1);
                    break;
                case 5:
                    escribir(" I ", 95, 0, 1);
                    break;
                case 6:
                    escribir(" M ", 64, 0, 1);
                    break;
                case 7:
                    escribir("   ", 153, 0, 1);
                }
            }
        }
        escribir("\n");
    }
    escribir("\n");
}

int menuMapa(int const turno, Posicion const pos)
{
    int opcion;
    escribir("\n Turno: " + to_string(turno) + "\n");
    mostrarMapa(pos);
    escribir(" Movimiento (W - Norte | S - Sur | A - Oeste | D - Este)\nC - Cargar partida\nG - Guardar partida\nT - Terminar partida\n");
    do
        opcion = leerChar("-> ");
    while (opcion != 'W' &&
           opcion != 'S' &&
           opcion != 'A' &&
           opcion != 'D' &&
           opcion != 'C' &&
           opcion != 'G' &&
           opcion != 'T');
    return opcion;
}