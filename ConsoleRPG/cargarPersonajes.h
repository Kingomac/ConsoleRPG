#ifndef CARGARPERSONAJES_H_INCLUDED
#define CARGARPERSONAJES_H_INCLUDED
#include <string>
#include "estructuras.h"

using namespace std;

/**
 * Carga personajes iniciales de un archivo CSV
 * Estos continen �nicamente la informaci�n necesaria para crear un personaje de 0
**/
void cargarPersonajes(Personaje p[], int lineas, string archivo);

#endif // CARGARPERSONAJES_H_INCLUDED
