#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED
#include <string>
#include "personajes.h"
using namespace std;

/**
 * Posición del jugador en el mapa
**/
struct Posicion
{
    int fila;
    int columna;
};

/**
    Información relacionada al jugador en el mapa
*/
struct Jugador
{
    Posicion pos;
    int turnos;
};

/**
 * Información relativa a un personaje que está combatiendo
**/
struct PCombatiente
{
    Personaje *p;
    Personaje *objetivo;
    bool jugador = false;
    int ataque = -1;
};

#endif // ESTRUCTURAS_H_INCLUDED
