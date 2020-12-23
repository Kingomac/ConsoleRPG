#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED
#include <string>

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
 * Información de un ataque
**/
struct Ataque
{
    string nombre;
    int fuerza;
    bool fisico; // Físico true || Mágico false
    int usosTotales, usos;
};

/**
 * Información de un personaje
 * Se usa para enemigos y aliados
*/
struct Personaje
{
    string nombre;
    int nivel;
    int salud;
    int saludTotal;
    Ataque ataques[4];
    int velocidad;
    int ataqueF = 0, defensaF = 0, ataqueM = 0, defensaM = 0;
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
