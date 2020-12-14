#ifndef GUARDARCARGARPARTIDA_H_INCLUDED
#define GUARDARCARGARPARTIDA_H_INCLUDED
#include <string>
#include "estructuras.h"

using namespace std;
/**
 * Guarda los datos de los parámetros en un archivo seleccionado por el usuario
**/
void guardarPartida(Jugador *jugador, Personaje a[]);

/**
 * Intenta leer una partida guardada y cargar los datos en jugador y aliados[]
 * Lee el archivo de guardado pasado por el parámetro n (sería un número en formato string)
 * Si la partida se cargó correctamente devuelve true, si hubo algún error o no existe devuelve false
**/
bool leerPartida(Jugador *jugador, Personaje aliados[], string n);

/**
 * Muestra un menú con información sobre las partidas guardadas y permite al usuario seleccionar uno de los cinco archivos
 * Devuelve el número de partida seleccionada como string (para concatenarlo fácilmente)
**/
string seleccionarPartida();

#endif // GUARDARCARGARPARTIDA_H_INCLUDED
