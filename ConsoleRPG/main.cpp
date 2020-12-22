#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string>
#include "estructuras.h"
#include "utilidades.h"
#include "escribir.h"
#include "textos.h"
#include "aliados.h"
#include "guardarCargarPartida.h"
#include "enemigos.h"
#include "cargarPersonajes.h"
#include "mapa.h"
#include "./menus/menus.h"
#include "partida.h"

using namespace std;

extern int nAliados;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    srand(time(NULL));
    //listaColores();
    escribir("\n\n");
    escribirArchivo(R_T_TITULO, 15, 0, 100); // Mostrar título del juego
    escribir("\n\n", 7, 0, 0);
    int opcion = menuPrincipal();
    if (opcion == 'N')
    {
        // Se define un nuevo jugador y se inicia la partida
        Jugador jugador =
            {
                {F_INICIAL,
                 C_INICIAL},
                0};

        nAliados = contarLineas(R_ALI_INI);
        if (nAliados == -1)
        {
            escribir(T_ERR_FIC + R_ALI_INI + " \n", 79);
            exit(1);
        }
        Personaje *aliados = NULL;

        if ((aliados = new Personaje[nAliados]) == NULL)
        {
            escribir(T_ERR_MEM, 79);
            exit(1);
        }
        cargarPersonajes(aliados, nAliados, R_ALI_INI);
        escribirArchivo(R_T_T_INTRO, 7, 0, 1);
        escribirArchivo(R_T_INTRO, 7);
        opcion = partida(jugador, aliados);

        delete[] aliados;
    }
    while (opcion == 'C')
    {
        Jugador jugador;
        Personaje *aliados = NULL;
        string o = seleccionarPartida();
        nAliados = contarLineas(R_PARTIDAS + o + ".csv") - 1;
        if (nAliados == -2)
        {
            escribir(T_ERR_GUARD + o + " \n");
            exit(1);
        }
        if ((aliados = new Personaje[nAliados]) == NULL)
        {
            escribir(T_ERR_MEM, 79);
            exit(1);
        }
        if (leerPartida(&jugador, aliados, nAliados, o))
            opcion = partida(jugador, aliados);
        else
            escribir(T_SEL_VAC);
        delete[] aliados;
    }
    liberarMemEnemigos();
    return 0;
}
