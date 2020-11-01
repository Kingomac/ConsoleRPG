#include <iostream>

using namespace std;


char menuPrincipal();

int main()
{
    cout << "Titulo provisional" << endl;
    char opcion = menuPrincipal();
    if (opcion == 'N') {
        //Hacer una nueva partida
    }
    if (opcion == 'C') {
        // Cargar partida
    }
    return 0;
}
