#include <iostream>
#include <stdlib.h>
#include "estructuras.h"
#include <windows.h>

using namespace std;

char menuMapa(int const turno, Posicion const pos);
char moverJugador(Jugador &jugador, Posicion pos);
void combate(Personaje aliados[], short int camino);

/**
    Inicia la partida con datos nuevos o guardados y gestiona los turnos en mapa
*/
void partida(Jugador &jugador, Personaje personajes[3])
{
    char opcion;
    do
    {
        opcion = menuMapa(jugador.turnos, jugador.pos);
        short int dificultadCombate = 0;
        switch(opcion)
        {
        case 'W':
            dificultadCombate = moverJugador(jugador, { jugador.pos.fila - 1, jugador.pos.columna });
            break;
        case 'S':
            dificultadCombate = moverJugador(jugador, { jugador.pos.fila + 1, jugador.pos.columna });
            break;
        case 'A':
            dificultadCombate = moverJugador(jugador, { jugador.pos.fila, jugador.pos.columna - 1 });
            break;
        case 'D':
            dificultadCombate = moverJugador(jugador, { jugador.pos.fila, jugador.pos.columna + 1 });
            break;
        case 'C':
            break;
        case 'G':
            break;
        }
        if(dificultadCombate > 0)
            combate(personajes,dificultadCombate);
        jugador.turnos++;
    }
    while(opcion != 'T');
}
