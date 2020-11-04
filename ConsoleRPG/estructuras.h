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
    short int fuerza;
    bool fisico; // Físico true || Mágico false
};
/**
    Información de un personaje en combate
    Se usará también para los enemigos
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

#endif // ESTRUCTURAS_H_INCLUDED
