#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string>
#include "estructuras.h"
#include "constantes.h"
#include "utilidades.h"
#include "escribir.h"
#include "textos.h"

using namespace std;

int menuPrincipal();
int partida(Jugador &jugador, Personaje personajes[4]);
void cargarPersonajes(Personaje p[], int lineas, string archivo);
void liberarMemEnemigos();
string seleccionarPartida();
bool leerPartida(Jugador *jugador, Personaje aliados[3], string n);

Personaje *personajes = NULL;
int nAliados = 3;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    srand(time(NULL));
    //listaColores();
    escribir("\n\n");
    escribirArchivo(R_T_TITULO, 15, 0, 100);
    escribir("\n\n", 7, 0, 0);
    int opcion = menuPrincipal();
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

        nAliados = contarLineas(R_ALI_INI);
        if ((personajes = new Personaje[nAliados]) == NULL)
        {
            escribir(T_ERR_MEM, 79);
            exit(1);
        }
        cargarPersonajes(personajes, nAliados, R_ALI_INI);
        escribirArchivo(R_T_T_INTRO, 7, 0, 1);
        escribirArchivo(R_T_INTRO);
        opcion = partida(jugador, personajes);

        delete personajes;
    }
    if (opcion == 'C')
    {
        Jugador jugador;
        Personaje aliados[3];
        string o = seleccionarPartida();
        if (leerPartida(&jugador, aliados, o))
        {
            for (int i = 0; i < 3; i++)
                cout << aliados[i].nombre << " " << aliados[i].salud << "/" << aliados[i].saludTotal << endl;
            partida(jugador, aliados);
        }
        else
            escribir(T_SEL_VAC);
    }
    liberarMemEnemigos();
    return 0;
}
