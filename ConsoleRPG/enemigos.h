#ifndef ENEMIGOS_H_INCLUDED
#define ENEMIGOS_H_INCLUDED
#include "estructuras.h"

/**
 * Devuelve un enemigo aleatorio que pueda salir en un camino concreto
 * Si la funci�n se ejecuta por primera vez se lee el archivo con las estructuras
 * y se carga en un array din�mico para que las ejecuciones posteriores tarden menos
**/
Personaje enemigoAleatorio(int camino);

/**
 * Libera la memoria usada por los arrays din�micos cargados por enemigoAleatorio()
**/
void liberarMemEnemigos();

#endif // ENEMIGOS_H_INCLUDED
