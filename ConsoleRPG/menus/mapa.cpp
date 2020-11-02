#include <iostream>

using namespace std;

char menuMapa()
{
    char opcion;
    do
    {
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
