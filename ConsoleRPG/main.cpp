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
            0
        };

        Personaje PArisu =
        {
            "Arisu",
            1,
            100,
            {
                {
                    "Ataque1",
                    10,
                    true
                },
                {
                    "Ataque1",
                    10,
                    true
                },
                {
                    "Ataque1",
                    10,
                    true
                },
                {
                    "Ataque1",
                    10,
                    true
                },
            },
            100
        };

        Personaje PHideaki =
        {
            "Hideaki",
            1,
            100,
            {
                {
                    "Ataque1",
                    10,
                    true
                },
                {
                    "Ataque1",
                    10,
                    true
                },
                {
                    "Ataque1",
                    10,
                    true
                },
                {
                    "Ataque1",
                    10,
                    true
                }
            },
            100

        };

        Personaje PTakesi =
        {
            "Takeshi",
            1,
            100,
            {
                {
                    "Ataque1",
                    10,
                    true
                },
                {
                    "Ataque1",
                    10,
                    true
                },
                {
                    "Ataque1",
                    10,
                    true
                },
                {
                    "Ataque1",
                    10,
                    true
                }
            },
            100
        };
        partida(jugador, PArisu, PHideaki, PTakesi);
    }
    if (opcion == 'C')
    {
        // Se cargaría la partida, se cambiarían los datos globales de los jugadores y se ejecutaria partida()
    }
    return 0;
}
