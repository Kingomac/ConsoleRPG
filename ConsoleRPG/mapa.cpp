#include <iostream>
#include "estructuras.h"
#include "escribir.h"
#include "textos.h"
#include "mapa.h"

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
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

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
