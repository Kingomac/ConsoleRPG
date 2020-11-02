#include <iostream>
#include "estructuras.h"
#include "constantes.h"

using namespace std;

char mapa[FILAS_MAPA][COLUMNAS_MAPA] =
{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,3,3,3,3,3,0,3,0,4,0},
    {0,6,0,0,0,3,0,0,0,3,0,3,0,3,0},
    {0,4,3,3,3,3,0,0,0,3,0,3,0,2,0},
    {0,0,0,0,0,0,0,0,0,3,4,3,0,2,0},
    {0,2,2,2,3,3,3,3,3,3,0,3,0,2,0},
    {0,0,0,2,0,0,0,0,0,0,0,3,0,2,0},
    {0,0,0,2,2,2,2,2,2,2,2,2,2,2,0},
    {0,0,0,3,0,0,0,0,0,0,0,0,0,2,0},
    {0,5,0,0,1,1,1,0,0,0,0,4,0,2,0},
    {0,1,1,1,1,1,1,0,0,0,0,4,0,2,0},
    {0,1,1,1,0,0,1,0,0,0,0,2,0,2,0},
    {0,1,1,1,0,0,2,2,2,2,2,2,0,2,0},
    {0,1,1,1,0,0,2,2,2,2,2,2,2,2,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

void moverJugador(Jugador &jugador, Posicion pos)
{

    if(mapa[pos.fila][pos.columna] == 0)
    {
        cout << "El camino está bloqueado" << endl;
    }
    else
    {
        jugador.pos = pos;
        switch(mapa[pos.fila][pos.columna])
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        }
    }
}
