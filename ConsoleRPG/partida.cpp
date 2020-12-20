#include <iostream>
#include <stdlib.h>
#include "estructuras.h"
#include <windows.h>
#include <fstream>
#include <string>
#include "utilidades.h"
#include "escribir.h"
#include "textos.h"
#include "aliados.h"
#include "guardarCargarPartida.h"
#include "./menus/menus.h"
#include "combate.h"
#include "mapa.h"
#include "aliados.h"

using namespace std;

extern int nAliados;

void accionCasilla(Jugador &jugador, int camino, Personaje aliados[], int &opcion)
{
    for (int i = 0; i < nAliados; i++) // Penalización si algún aliado ha muerto
    {
        if (aliados[i].salud <= 0)
        {
            for (int j = 0; j < nAliados; j++)
            {
                aliados[j].ataqueF *= 0.95;
                aliados[j].ataqueM *= 0.95;
                aliados[j].defensaF *= 0.95;
                aliados[j].defensaM *= 0.95;
            }
            escribir(" La perdida de " + aliados[i].nombre + " mella la moral del equipo\n", 12);
        }
    }
    if (camino > 0 && camino < 4 && rand() % 100 < 66)
    {
        combate(aliados, camino);
    }
    else if (camino == 4)
    {
        restablecerSalud(aliados);
        escribir(T_ALI_RECUP, 10);
    }
    else if (camino == 5)
    {
        restablecerSalud(aliados);
        escribir(T_VENCER_REY, 11);
    }
    else if (camino == 6)
        combate(aliados, camino);
    jugador.turnos++;
}

int partida(Jugador &jugador, Personaje aliados[])
{
    int opcion;
    do
    {
        opcion = menuMapa(jugador.turnos, jugador.pos);
        int camino = 0;
        switch (opcion)
        {
        case 'W':
            camino = moverJugador(jugador, {jugador.pos.fila - 1, jugador.pos.columna});
            accionCasilla(jugador, camino, aliados, opcion);
            break;
        case 'S':
            camino = moverJugador(jugador, {jugador.pos.fila + 1, jugador.pos.columna});
            accionCasilla(jugador, camino, aliados, opcion);
            break;
        case 'A':
            camino = moverJugador(jugador, {jugador.pos.fila, jugador.pos.columna - 1});
            accionCasilla(jugador, camino, aliados, opcion);
            break;
        case 'D':
            camino = moverJugador(jugador, {jugador.pos.fila, jugador.pos.columna + 1});
            accionCasilla(jugador, camino, aliados, opcion);
            break;
        case 'E':
            mostrarEstadisticas(aliados);
            break;
        case 'C':
            return 'C';
        case 'G':
            guardarPartida(&jugador, aliados);
        }
        if (nVivos(nAliados, aliados) == 0)
        {
            escribirArchivo("./textos/fin_muertos.txt", 7, 1, 0);
            opcion = 'T';
        }
    } while (opcion != 'T');
    return 'T';
}
