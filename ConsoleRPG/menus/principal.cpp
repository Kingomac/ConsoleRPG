#include <iostream>
#include <iomanip>

using namespace std;

char menuPrincipal()
{
    char opcion;
    do
    {
        cout << "Nueva partida (N) | Cargar partida (C) | Salir (S)" << endl;
        cin >> opcion;
    } while (opcion != 'N' && opcion != 'C' && opcion != 'S');
    return opcion;
}
