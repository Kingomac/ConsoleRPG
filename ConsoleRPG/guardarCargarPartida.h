#ifndef GUARDARCARGARPARTIDA_H_INCLUDED
#define GUARDARCARGARPARTIDA_H_INCLUDED
#include <string>
#include "estructuras.h"

using namespace std;
/**
 * Guarda los datos de los par�metros en un archivo seleccionado por el usuario
**/
void guardarPartida(Jugador *jugador, Personaje a[]);

/**
 * Intenta leer una partida guardada y cargar los datos en jugador y aliados[]
 * Lee el archivo de guardado pasado por el par�metro n (ser�a un n�mero en formato string)
 * Si la partida se carg� correctamente devuelve true, si hubo alg�n error o no existe devuelve false
**/
bool leerPartida(Jugador *jugador, Personaje aliados[], string n);

/**
 * Muestra un men� con informaci�n sobre las partidas guardadas y permite al usuario seleccionar uno de los cinco archivos
 * Devuelve el n�mero de partida seleccionada como string (para concatenarlo f�cilmente)
**/
string seleccionarPartida();

#endif // GUARDARCARGARPARTIDA_H_INCLUDED
