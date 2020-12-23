#ifndef PARTIDA_H_INCLUDED
#define PARTIDA_H_INCLUDED
#include "estructuras.h"

/**
 * Comprueba según la casilla del mapa qué modificadores se deben aplicar, si
 * se debe hacer un combate o restablecer la salud de los personajes
**/
void accionCasilla(Jugador &jugador, int camino, Personaje aliados[], int &opcion);

/**
 * Muestra el menú del mapa y gestiona la elección del jugador de moverse o cerrar el juego
**/
int partida(Jugador &jugador, int nAliados, Personaje aliados[]);

#endif // PARTIDA_H_INCLUDED
