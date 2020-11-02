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
    Informaci�n relacionada al jugador en el mapa
*/
struct Jugador
{
    Posicion pos;
    int turnos;
    float modificadores; // Un n�mero entre 0.1 y 1.9 que cambie las estad�sticas de todos los personajes del jugador
};
/**
    Informaci�n de un personaje en combate
*/
struct Personaje
{
    string nombre;
    int salud;
    int ataqueF, defensaF, ataqueM, defensaM;
    int velocidad;
};

#endif // ESTRUCTURAS_H_INCLUDED
