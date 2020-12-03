#include <iostream>
#include "estructuras.h"
#include "constantes.h"
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string>
#define RAIZ "C:/Users/kingo/Desktop/ConsoleRPG/Juego/"  //CAMIBIAR EN LA VERSIÓN DEFINITIVA POR UNA RUTA RELATIVA

using namespace std;

char menuPrincipal();
void partida(Jugador &jugador, Personaje personajes[4]);
void cargarPersonajes(Personaje p[], int &linea, string archivo);

int nAliados = 0;

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
            {
                F_INICIAL,
                C_INICIAL
            },
            0
        };

        Personaje personajes[];
        cargarPersonajes(personajes, nAliados, string(RAIZ) + string("aliados/iniciales.csv"));
        partida(jugador, personajes);
    }
    if (opcion == 'C')
    {
        // Se cargar�a la partida, se cambiar�an los datos globales de los jugadores y se ejecutaria partida()
    }
    return 0;
}
