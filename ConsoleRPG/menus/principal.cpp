#include <iostream>
#include "utilidades.h"
#include "escribir.h"

using namespace std;

char menuPrincipal()
{
    char opcion;
    escribir(" Nueva partida (N) | Cargar partida (C) | Salir (S)\n");
    do
        opcion = leerChar("-> ");
    while (opcion != 'N' && opcion != 'C' && opcion != 'S');
    return opcion;
}
