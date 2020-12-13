#ifndef PARTIDA_H_INCLUDED
#define PARTIDA_H_INCLUDED
#include "estructuras.h"

void generarCombate(Jugador &jugador, int camino, Personaje aliados[], int &opcion);
int partida(Jugador &jugador, Personaje aliados[]);

#endif // PARTIDA_H_INCLUDED
