#include "utilidades.h"
#include "escribir.h"

using namespace std;

int menuPrincipal()
{
    int opcion;
    escribir(" Nueva partida (N) | Cargar partida (C) | Salir (S)\n");
    do
    {
        opcion = leerChar("-> ");
    }
    while (opcion != 'N' && opcion != 'C' && opcion != 'S');
    return opcion;
}
