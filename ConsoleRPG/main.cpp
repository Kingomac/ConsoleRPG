#include <iostream>
#include "estructuras.h"
#include "constantes.h"
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string>

#define RAIZ "C:/Users/Mario/Desktop/ConsoleRPG/Juego/" //CAMIBIAR EN LA VERSIÓN DEFINITIVA POR UNA RUTA RELATIVA

using namespace std;

char menuPrincipal();
void partida(Jugador &jugador, Personaje personajes[4]);
void cargarPersonajes(Personaje p[], int lineas, string archivo);
int contarLineas(string archivo);
void liberarMemEnemigos();

Personaje *personajes = NULL;
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
                {F_INICIAL,
                 C_INICIAL},
                0};
        /*cargarPersonajes(personajes, nAliados, string(RAIZ) + string("enemigos/1.csv"));
        for (int i = 0; i < nAliados; i++)
        {
            cout << personajes[i].nombre << " " << personajes[i].velocidad << " cargado" << endl;
        }
        */
        nAliados = contarLineas(string(RAIZ) + string("aliados/iniciales.csv"));
        if ((personajes = new Personaje[nAliados]) == NULL)
        {
            cout << "Error de asignación de memoria" << endl;
            exit(1);
        }
        cargarPersonajes(personajes, nAliados, string(RAIZ) + string("aliados/iniciales.csv"));
        for (int i = 0; i < nAliados; i++)
        {
            cout << personajes[i].nombre << " " << personajes[i].velocidad << " cargado" << endl;
        }
        partida(jugador, personajes);

        delete personajes;
        liberarMemEnemigos();
    }
    if (opcion == 'C')
    {
        // Se cargar�a la partida, se cambiar�an los datos globales de los jugadores y se ejecutaria partida()
    }
    return 0;
}
