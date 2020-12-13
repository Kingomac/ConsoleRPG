#include <iostream>
#include "estructuras.h"
#include "constantes.h"
#include "escribir.h"
#include "textos.h"

using namespace std;

int mapa[FILAS_MAPA][COLUMNAS_MAPA] =
{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 0, 3, 0, 4, 0},
    {0, 6, 0, 0, 0, 3, 0, 0, 0, 3, 0, 3, 0, 3, 0},
    {0, 4, 3, 3, 3, 3, 0, 0, 0, 3, 0, 3, 0, 2, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3, 0, 2, 0},
    {7, 2, 2, 2, 3, 3, 3, 3, 3, 3, 0, 3, 0, 2, 0},
    {7, 7, 7, 2, 0, 0, 0, 0, 0, 0, 0, 3, 0, 2, 0},
    {7, 7, 7, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 7},
    {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 2, 7},
    {7, 5, 7, 7, 1, 1, 1, 0, 0, 0, 0, 4, 0, 2, 7},
    {0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 2, 0},
    {0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 2, 0, 2, 0},
    {0, 1, 1, 1, 0, 0, 2, 2, 2, 2, 2, 2, 0, 2, 0},
    {0, 1, 1, 1, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

/**
    Mueve el jugador en el mapa y determina si hay combate y que tipo de combate
    Devuelve la dificultad del combate o 0 si no hay ning�n combate
*/
int moverJugador(Jugador &jugador, Posicion pos)
{

    if (mapa[pos.fila][pos.columna] == 0)
        escribir(T_OBST_M);
    else if (mapa[pos.fila][pos.columna] == 7)
        escribir(T_OBST_A);
    else
        jugador.pos = pos;
    return mapa[pos.fila][pos.columna];
}

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
