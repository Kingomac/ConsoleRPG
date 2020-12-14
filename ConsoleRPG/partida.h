#ifndef PARTIDA_H_INCLUDED
#define PARTIDA_H_INCLUDED
#include "estructuras.h"

/**
 * Comprueba seg�n la casilla del mapa qu� modificadores se deben aplicar, si
 * se debe hacer un combate o restablecer la salud de los personajes
**/
void accionCasilla(Jugador &jugador, int camino, Personaje aliados[], int &opcion);

/**
 * Muestra el men� del mapa y gestiona la elecci�n del jugador de moverse o cerrar el juego
**/
int partida(Jugador &jugador, Personaje aliados[]);

#endif // PARTIDA_H_INCLUDED
