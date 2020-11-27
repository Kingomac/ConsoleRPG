#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED
#include <string>

using namespace std;

struct Posicion
{
    char fila;
    char columna;
};

/**
    Informaci�n relacionada al jugador en el mapa
*/
struct Jugador
{
    Posicion pos;
    int turnos;
};
struct Ataque
{
    string nombre;
    short int fuerza;
    bool fisico; // F�sico true || M�gico false
    short int usosTotales;
    short int usos = usosTotales;
};
/**
    Informaci�n de un personaje en combate
    Se usar� tambi�n para los enemigos
*/
struct Personaje
{
    string nombre;
    short int nivel;
    short int salud;
    Ataque ataques[4];
    short int velocidad;
    short int ataqueF = 0, defensaF = 0, ataqueM = 0, defensaM = 0;
};

struct PCombatiente
{
    Personaje *p;
    short int orden;
    Personaje *objetivo;
    bool jugador = false;
    short int ataque = -1;
};

#endif // ESTRUCTURAS_H_INCLUDED
