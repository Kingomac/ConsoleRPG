#include <iostream>
#include <stdlib.h>
#include "estructuras.h"
#include <windows.h>
#include <fstream>
#include <string>
#include "utilidades.h"
#include "escribir.h"
#include "textos.h"
#define ALIADOS 3

using namespace std;

int menuMapa(int const turno, Posicion const pos);
int moverJugador(Jugador &jugador, Posicion pos);
void combate(Personaje aliados[], int camino);
int nVivos(int n, Personaje p[]);
void restablecerSalud(Personaje aliados[]);

void generarCombate(Jugador &jugador, int camino, Personaje aliados[ALIADOS], int &opcion)
{
    if (nVivos(ALIADOS, aliados) > 0)
    {
        for (int i = 0; i < ALIADOS; i++)
        {
            if (aliados[i].salud <= 0)
            {
                for (int j = 0; j < ALIADOS; j++)
                {
                    aliados[j].nivel--;
                    aliados[j].ataqueF -= 20;
                    aliados[j].ataqueM -= 20;
                    aliados[j].defensaF -= 20;
                    aliados[j].defensaM -= 20;
                    aliados[j].salud -= 20;
                }
                escribir("La perdida de " + aliados[i].nombre + " mella la moral del equipo\n", 12);
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
        escribirArchivo("./textos/fin_muertos.txt", 7, 10, 20);
        opcion = 'T';
    }
}

bool leerPartida(Jugador *jugador, Personaje aliados[ALIADOS], string n)
{
    ifstream ifs(R_PARTIDAS + n + ".csv");
    if (ifs.fail())
        return false;
    else
    {
        char dato[100];
        ifs.getline(dato, 100, ';');
        jugador->pos.fila = atoi(dato);
        ifs.getline(dato, 100, ';');
        jugador->pos.columna = atoi(dato);
        ifs.getline(dato, 100, '\n');
        jugador->turnos = atoi(dato);
        for (int i = 0; i < ALIADOS; i++)
        {
            ifs.getline(dato, 100, ';');
            aliados[i].nombre = dato;
            ifs.getline(dato, 100, ';');
            aliados[i].nivel = atoi(dato);
            ifs.getline(dato, 100, ';');
            aliados[i].salud = atoi(dato);
            ifs.getline(dato, 100, ';');
            aliados[i].saludTotal = atoi(dato);
            ifs.getline(dato, 100, ';');
            aliados[i].velocidad = atoi(dato);
            ifs.getline(dato, 100, ';');
            aliados[i].ataqueF = atoi(dato);
            ifs.getline(dato, 100, ';');
            aliados[i].defensaF = atoi(dato);
            ifs.getline(dato, 100, ';');
            aliados[i].ataqueM = atoi(dato);
            ifs.getline(dato, 100, ';');
            aliados[i].defensaM = atoi(dato);
            for (int j = 0; j < 4; j++)
            {
                ifs.getline(dato, 100, ';');
                aliados[i].ataques[j].nombre = dato;
                ifs.getline(dato, 100, ';');
                aliados[i].ataques[j].fuerza = atoi(dato);
                ifs.getline(dato, 100, ';');
                aliados[i].ataques[j].fisico = dato[0] == 't';
                ifs.getline(dato, 100, ';');
                aliados[i].ataques[j].usos = atoi(dato);
                j < 3 ? ifs.getline(dato, 100, ';') : ifs.getline(dato, 100, '\n');
                aliados[i].ataques[j].usosTotales = atoi(dato);
            }
        }
        return true;
    }
    ifs.close();
}

string seleccionarPartida()
{
    int n;
    escribir(T_REEMPL);
    for (int i = 1; i < 6; i++)
    {
        escribir(T_GUARD + to_string(i) + ": " + "\n");
        Jugador j;
        Personaje aliados[ALIADOS];
        if (leerPartida(&j, aliados, to_string(i)))
        {
            escribir("\tTurnos: " + to_string(j.turnos));
            for (int j = 0; j < ALIADOS; j++)
                if (aliados[j].salud > 0)
                    escribir(" | " + aliados[j].nombre + " (" + to_string(aliados[j].nivel) + ")");
        }
        else
            escribir("Vacío\n", 8);
    }
    do
        n = leerEntero(T_SEL_GUARD);
    while (n < 0 || n > 6);
    return to_string(n);
}

void guardarPartida(Jugador *jugador, Personaje a[ALIADOS])
{
    ofstream ofs(R_PARTIDAS + seleccionarPartida() + ".csv");
    ofs << to_string(jugador->pos.fila) << ";" << to_string(jugador->pos.columna) << ";" << jugador->turnos << endl;
    for (int i = 0; i < ALIADOS; i++)
    {
        ofs << a[i].nombre << ";" << a[i].nivel << ";" << a[i].salud << ";" << a[i].saludTotal << ";" << a[i].velocidad << ";" << a[i].ataqueF << ";" << a[i].defensaF << ";" << a[i].ataqueM << ";" << a[i].defensaM;
        for (int j = 0; j < 4; j++)
            ofs << ";" << a[i].ataques[j].nombre << ";" << a[i].ataques[j].fuerza << ";" << (a[i].ataques[j].fisico ? 't' : 'f') << ";" << a[i].ataques[j].usos << ";" << a[i].ataques[j].usosTotales;
        ofs << endl;
    }
    ofs.close();
}

/**
    Inicia la partida con datos nuevos o guardados y gestiona los turnos en mapa
*/
int partida(Jugador &jugador, Personaje aliados[ALIADOS])
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
            generarCombate(jugador, camino, aliados, opcion);
            break;
        case 'S':
            camino = moverJugador(jugador, {jugador.pos.fila + 1, jugador.pos.columna});
            generarCombate(jugador, camino, aliados, opcion);
            break;
        case 'A':
            camino = moverJugador(jugador, {jugador.pos.fila, jugador.pos.columna - 1});
            generarCombate(jugador, camino, aliados, opcion);
            break;
        case 'D':
            camino = moverJugador(jugador, {jugador.pos.fila, jugador.pos.columna + 1});
            generarCombate(jugador, camino, aliados, opcion);
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
