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
    {0,1,1,1,1,1,1,0,0,0,0,2,0,2,0},
    {0,1,1,1,0,0,1,0,0,0,0,2,0,2,0},
    {0,1,1,1,0,0,2,2,2,2,2,2,0,2,0},
    {0,1,1,1,0,0,2,2,2,2,2,2,2,2,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

/**
    Mueve el jugador en el mapa y determina si hay combate y que tipo de combate
    Devuelve la dificultad del combate o 0 si no hay ning�n combate
*/
char moverJugador(Jugador &jugador, Posicion pos)
{

    if(mapa[pos.fila][pos.columna] == 0)
    {
        cout << "El camino está bloqueado" << endl;
    }
    else
    {
        jugador.pos = pos;
        int probabilidad = rand()%100;
        if(probabilidad < 50)
            return mapa[pos.fila][pos.columna];
        else
            return 0;
    }
}

void mostrarMapa(Posicion pos)
{
    for(int i = 0; i < FILAS_MAPA; i++)
    {
        for(int j = 0; j < COLUMNAS_MAPA; j++)
        {
            if(pos.fila == i && pos.columna == j)
            {
                cout << "J";
            }
            else
            {
                switch(mapa[i][j])
                {
                case 0:
                    cout << "X";
                    break;
                case 1:
                    cout << " ";
                    break;
                case 2:
                    cout << " ";
                    break;
                case 3:
                    cout << " ";
                    break;
                case 4:
                    cout << "C";
                    break;
                case 5:
                    cout << "I";
                    break;
                case 6:
                    cout << "M";
                }
            }
            cout << " ";
        }
        cout << endl;
    }
}
