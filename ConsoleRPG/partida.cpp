#include <iostream>
#include <stdlib.h>
#include "estructuras.h"
#include <windows.h>

using namespace std;

char menuMapa(int const turno, Posicion const pos);
void moverJugador(Jugador &jugador, Posicion pos);

void partida(Jugador &jugador, Personaje &arisu, Personaje &hideaki, Personaje &takesi)
{
    char opcion;
    do
    {
        system("cls");
        opcion = menuMapa(jugador.turnos, jugador.pos);
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
        jugador.turnos++;
        Sleep(500);
    }
    while(opcion != 'T');
}
