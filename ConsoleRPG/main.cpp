#include <iostream>
#include "estructuras.h"
#include "constantes.h"

using namespace std;

char menuPrincipal();
void partida(Jugador &jugador, Personaje &arisu, Personaje &hideaki, Personaje &takesi);

int main()
{
    cout << "Titulo provisional" << endl;
    char opcion = menuPrincipal();
    if (opcion == 'N')
    {
        // Se define un nuevo jugador y se inicia la partida
        Jugador jugador =
        {
            {
                F_INICIAL,
                C_INICIAL
            },
            0,
            1.0
        };

        Personaje PArisu =
        {
            "Arisu",
            100,
            1,
            1,
            1,
            1,
            1
        };

        Personaje PHideaki =
        {
            "Hideaki",
            100,
            1,
            1,
            1,
            1,
            1
        };

        Personaje PTakesi =
        {
            "Takeshi",
            100,
            1,
            1,
            1,
            1,
            1
        };
        partida(jugador, PArisu, PHideaki, PTakesi);
    }
    if (opcion == 'C')
    {
        // Se cargaría la partida, se cambiarían los datos globales de los jugadores y se ejecutaria partida()
    }
    return 0;
}
