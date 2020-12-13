#ifndef GUARDARCARGARPARTIDA_H_INCLUDED
#define GUARDARCARGARPARTIDA_H_INCLUDED
#include <string>
#include "estructuras.h"

using namespace std;

void guardarPartida(Jugador *jugador, Personaje a[]);
bool leerPartida(Jugador *jugador, Personaje aliados[], string n);
string seleccionarPartida();

#endif // GUARDARCARGARPARTIDA_H_INCLUDED
