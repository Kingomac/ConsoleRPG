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
    if (nVivos(nAliados, aliados) > 0)
    {
        for (int i = 0; i < nAliados; i++) // Penalización si algún aliado ha muerto
        {
            if (aliados[i].salud <= 0)
            {
                for (int j = 0; j < nAliados; j++)
                {
                    aliados[j].nivel--;
                    aliados[j].ataqueF -= 20;
                    aliados[j].ataqueM -= 20;
                    aliados[j].defensaF -= 20;
                    aliados[j].defensaM -= 20;
                    aliados[j].salud -= 20;
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
    else
    {
        // No hay aliados vivos y termina el juego
        escribirArchivo("./textos/fin_muertos.txt", 7, 10, 20);
        opcion = 'T';
    }
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
    }
    while (opcion != 'T');
    return 'T';
}
