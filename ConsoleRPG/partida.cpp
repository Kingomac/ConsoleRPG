#include <iostream>
#include <stdlib.h>
#include "estructuras.h"
#include <windows.h>
#define ALIADOS 3

using namespace std;

char menuMapa(int const turno, Posicion const pos);
char moverJugador(Jugador &jugador, Posicion pos);
void combate(Personaje aliados[], char camino);

/**
    Inicia la partida con datos nuevos o guardados y gestiona los turnos en mapa
*/
void partida(Jugador &jugador, Personaje aliados[3])
{
    char opcion;
    do
    {
        opcion = menuMapa(jugador.turnos, jugador.pos);
        short int dificultadCombate = 0;
        switch (opcion)
        {
        case 'W':
            dificultadCombate = moverJugador(jugador, {jugador.pos.fila - 1, jugador.pos.columna});
            break;
        case 'S':
            dificultadCombate = moverJugador(jugador, {jugador.pos.fila + 1, jugador.pos.columna});
            break;
        case 'A':
            dificultadCombate = moverJugador(jugador, {jugador.pos.fila, jugador.pos.columna - 1});
            break;
        case 'D':
            dificultadCombate = moverJugador(jugador, {jugador.pos.fila, jugador.pos.columna + 1});
            break;
        case 'C':
            break;
        case 'G':
            break;
        }
        if (dificultadCombate > 0)
        {
            combate(aliados, dificultadCombate);
            for (char i = 0; i < ALIADOS; i++)
            {
                if (aliados[i].salud <= 0)
                {
                    for (char j = 0; j < ALIADOS; j++)
                    {
                        aliados[j].nivel--;
                        aliados[j].ataqueF -= 20;
                        aliados[j].ataqueM -= 20;
                        aliados[j].defensaF -= 20;
                        aliados[j].defensaM -= 20;
                        aliados[j].salud -= 20;
                    }
                    cout << "La perdida de " << aliados[i].nombre << " mella la moral del equipo" << endl;
                }
            }
        }
        jugador.turnos++;
    } while (opcion != 'T');
}
