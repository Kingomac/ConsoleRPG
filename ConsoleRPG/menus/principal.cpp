#include <iostream>
#include "utilidades.h"

using namespace std;

char menuPrincipal()
{
    char opcion;
    do
        opcion = leerChar("Nueva partida (N) | Cargar partida (C) | Salir (S)\n");
    while (opcion != 'N' && opcion != 'C' && opcion != 'S');
    return opcion;
}
