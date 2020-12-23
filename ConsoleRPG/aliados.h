#ifndef nAliados_H_INCLUDED
#define nAliados_H_INCLUDED
#include "estructuras.h"

using namespace std;

/**
 * Restablece la salud y usos disponibles de cada ataque de personajes
**/
void restablecerSalud(int n, Personaje p[]);

/**
 * Imprime todas las estadísticas de los personajes
**/
void mostrarEstadisticas(int n, Personaje p[]);

#endif // nAliados_H_INCLUDED
