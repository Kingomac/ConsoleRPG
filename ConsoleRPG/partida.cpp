#include <iostream>
#include <stdlib.h>
#include "estructuras.h"

using namespace std;

char menuMapa();
void moverJugador(Jugador &jugador, Posicion pos);

void partida(Jugador &jugador, Personaje &arisu, Personaje &hideaki, Personaje &takesi)
{
    char opcion;
    do
    {
        opcion = menuMapa();
        switch(opcion)
        {
        case 'W':
            moverJugador(jugador, { jugador.pos.fila - 1, jugador.pos.columna });
            break;
        case 'S':
            moverJugador(jugador, { jugador.pos.fila + 1, jugador.pos.columna });
            break;
        case 'A':
            moverJugador(jugador, { jugador.pos.fila, jugador.pos.columna - 1 });
            break;
        case 'D':
            moverJugador(jugador, { jugador.pos.fila, jugador.pos.columna + 1 });
            break;
        case 'C':
            break;
        case 'G':
            break;
        }
    }
    while(opcion != 'T');
}
