#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED
#include <string>

using namespace std;

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
struct Ataque
{
    string nombre;
    int fuerza;
    bool fisico; // Físico true || Mágico false
    int usosTotales, usos;
};
/**
    Información de un personaje en combate
    Se usará también para los enemigos
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

struct PCombatiente
{
    Personaje *p;
    int orden;
    Personaje *objetivo;
    bool jugador = false;
    int ataque = -1;
};

#endif // ESTRUCTURAS_H_INCLUDED
