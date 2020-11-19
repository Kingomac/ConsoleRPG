#include <iostream>
#include "../estructuras.h"

using namespace std;

void mostrarMapa(Posicion pos);

char menuMapa(int const turno, Posicion const pos)
{
    char opcion;
    do
    {
        cout << "Turno: " << turno << endl;
        //cout << "Posición: (" << int(pos.fila) << ", " << int(pos.columna) << ")" << endl;
        mostrarMapa(pos);
        cout << "Movimiento (W - Norte | S - Sur | A - Oeste | D - Este)" << endl;
        cout << "C - Cargar partida" << endl;
        cout << "G - Guardar partida" << endl;
        cout << "T - Terminar partida" << endl;
        cin >> opcion;
    }
    while(opcion != 'W' &&
            opcion != 'S' &&
            opcion != 'A' &&
            opcion != 'D' &&
            opcion != 'C' &&
            opcion != 'G' &&
            opcion != 'T');
    return opcion;
}
