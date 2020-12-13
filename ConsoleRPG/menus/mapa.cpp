#include <iostream>
#include "../estructuras.h"
#include "utilidades.h"
#include "escribir.h"

using namespace std;

void mostrarMapa(Posicion pos);

int menuMapa(int const turno, Posicion const pos)
{
    int opcion;
    escribir("\n Turno: " + to_string(turno) + "\n");
    mostrarMapa(pos);
    escribir(" Movimiento (W - Norte | S - Sur | A - Oeste | D - Este)\nC - Cargar partida\nG - Guardar partida\nT - Terminar partida\n");
    do
        opcion = leerChar("-> ");
    while (opcion != 'W' &&
            opcion != 'S' &&
            opcion != 'A' &&
            opcion != 'D' &&
            opcion != 'C' &&
            opcion != 'G' &&
            opcion != 'T');
    return opcion;
}
