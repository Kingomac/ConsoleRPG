#include <iostream>
#include "estructuras.h"
#include "constantes.h"
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string>
#include "utilidades.h"

#define RAIZ "C:/Users/Mario/Desktop/ConsoleRPG/Juego/" //CAMIBIAR EN LA VERSIÓN DEFINITIVA POR UNA RUTA RELATIVA

using namespace std;

char menuPrincipal();
char partida(Jugador &jugador, Personaje personajes[4]);
void cargarPersonajes(Personaje p[], int lineas, string archivo);
void liberarMemEnemigos();
string seleccionarPartida();
void leerPartida(Jugador *jugador, Personaje aliados[3], string n);

Personaje *personajes = NULL;
int nAliados = 3;

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
        opcion = partida(jugador, personajes);

        delete personajes;
    }
    if (opcion == 'C')
    {
        Jugador jugador;
        Personaje aliados[3];
        string o = seleccionarPartida();
        if (o != "0")
        {
            leerPartida(&jugador, aliados, o);
            partida(jugador, aliados);
        }
    }
    liberarMemEnemigos();
    return 0;
}
