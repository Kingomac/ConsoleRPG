#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED
#include "estructuras.h"

// Constantes que definen la posición inicial y el tamaño del mapa
const int F_INICIAL = 9;
const int C_INICIAL = 1;
const int FILAS_MAPA = 15;
const int COLUMNAS_MAPA = 15;

/**
 * Comprueba si el jugador se puede mover a una posición y muestra mensajes o realiza el movimiento
 * Devuelve el valor del camino que se usa para determinar la dificultad de los combates
**/
int moverJugador(Jugador &jugador, Posicion pos);
#endif // MAPA_H_INCLUDED
