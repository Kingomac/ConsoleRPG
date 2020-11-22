#include <iostream>
#include "estructuras.h"
#include "constantes.h"
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
using namespace std;

char menuPrincipal();
void partida(Jugador &jugador, Personaje personajes[4]);

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    srand(time(NULL));
    cout << "Titulo provisional" << endl;
    char opcion = menuPrincipal();
    if (opcion == 'N')
    {
        // Se define un nuevo jugador y se inicia la partida
        Jugador jugador =
            {
                {F_INICIAL,
                 C_INICIAL},
                0};

        Personaje personajes[] =

            {
                {

                    "Arisu",
                    1,
                    100,
                    {
                        {"Ataque1",
                         40,
                         true},
                        {"Ataque1",
                         40,
                         true},
                        {"Ataque1",
                         40,
                         true},
                        {"Ataque1",
                         40,
                         true},
                    },
                    100},
                {"Hideaki",
                 1,
                 100,
                 {{"Ataque1",
                   40,
                   true},
                  {"Ataque1",
                   40,
                   true},
                  {"Ataque1",
                   40,
                   true},
                  {"Ataque1",
                   40,
                   true}},
                 100

                },
                {"Takeshi",
                 1,
                 100,
                 {{"Ataque1",
                   40,
                   true},
                  {"Ataque1",
                   40,
                   true},
                  {"Ataque1",
                   40,
                   true},
                  {"Ataque1",
                   40,
                   true}},
                 100}};
        partida(jugador, personajes);
    }
    if (opcion == 'C')
    {
        // Se cargar�a la partida, se cambiar�an los datos globales de los jugadores y se ejecutaria partida()
    }
    return 0;
}
