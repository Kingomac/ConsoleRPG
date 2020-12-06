#include <iostream>
#include <stdlib.h>
#include "estructuras.h"
#include <windows.h>
#include <fstream>
#include <string>
#include "utilidades.h"
#define ALIADOS 3
#define RAIZ "C:/Users/Mario/Desktop/ConsoleRPG/Juego/" //CAMIBIAR EN LA VERSIÓN DEFINITIVA POR UNA RUTA RELATIVA

using namespace std;

char menuMapa(int const turno, Posicion const pos);
char moverJugador(Jugador &jugador, Posicion pos);
void combate(Personaje aliados[], char camino);
char nVivos(char n, Personaje p[]);
void restablecerSalud(Personaje aliados[]);

void generarCombate(Jugador &jugador, char camino, Personaje aliados[ALIADOS], char &opcion)
{
    if (nVivos(ALIADOS, aliados) > 0)
    {
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
        if ((camino > 0 && camino < 4) || camino == 6)
        {
            if (rand() % 100 < 66)
                combate(aliados, camino);
        }
        else if (camino == 4)
        {
            restablecerSalud(aliados);
        }
        else
        {
            cout << "No es momento de volver aquí, tenemos que derrotar al Rey Demonio" << endl;
        }
        jugador.turnos++;
    }
    else
    {
        cout << "Todos los personajes han muerto" << endl;
        opcion = 'T';
    }
}

void leerPartida(Jugador *jugador, Personaje aliados[ALIADOS], string n)
{
    ifstream ifs(string(RAIZ) + string("partidas/") + n + string(".csv"));
    if (ifs.fail())
    {
        cout << "Vacío" << endl;
    }
    else
    {
        char dato[100];
        ifs.getline(dato, 100, ';');
        jugador->pos.fila = atoi(dato);
        ifs.getline(dato, 100, ';');
        jugador->pos.columna = atoi(dato);
        ifs.getline(dato, 100, '\n');
        jugador->turnos = atoi(dato);
        for (char i = 0; i < ALIADOS; i++)
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
            aliados[i].defensaM = atoi(dato);
            for (char j = 0; j < 4; j++)
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
    }
    ifs.close();
}

string seleccionarPartida()
{
    int n;
    cout << "Partidas guardadas (al guardar sobre una partida existente esta se reemplaza):" << endl;
    for (char i = 1; i < 6; i++)
    {
        cout << "Espacio de guardado " << to_string(i) << ": " << endl;
        Jugador j;
        Personaje aliados[ALIADOS];
        aliados[0].nivel = -1;
        leerPartida(&j, aliados, to_string(i));
        if (aliados[0].nivel != -1)
        {
            cout << "\tTurnos: " << j.turnos;
            for (char j = 0; j < ALIADOS; j++)
                if (aliados[j].salud > 0)
                    cout << " | " << aliados[j].nombre << " (" << aliados[j].nivel << ")";
            cout << endl;
        }
    }
    do
        n = leerEntero("Usar espacio de guardado (0 para salir): ");
    while (n < 0 || n > 6);
    return to_string(n);
}

void guardarPartida(Jugador *jugador, Personaje a[ALIADOS])
{
    ofstream ofs(string(RAIZ) + string("partidas/") + seleccionarPartida() + string(".csv"));
    ofs << to_string(jugador->pos.fila) << ";" << to_string(jugador->pos.columna) << ";" << jugador->turnos << endl;
    for (char i = 0; i < ALIADOS; i++)
    {
        ofs << a[i].nombre << ";" << a[i].nivel << ";" << a[i].salud << ";" << a[i].saludTotal << ";" << a[i].velocidad << ";" << a[i].ataqueF << ";" << a[i].defensaF << ";" << a[i].ataqueM << ";" << a[i].defensaM << ";";
        for (char j = 0; j < 4; j++)
        {
            ofs << a[i].ataques[j].nombre << ";" << a[i].ataques[j].fuerza << ";" << (a[i].ataques[j].fisico ? 't' : 'f') << ";" << a[i].ataques[j].usos << ";" << a[i].ataques[j].usosTotales;
        }
        ofs << endl;
    }
    ofs.close();
}

/**
    Inicia la partida con datos nuevos o guardados y gestiona los turnos en mapa
*/
char partida(Jugador &jugador, Personaje aliados[ALIADOS])
{
    char opcion;
    do
    {
        opcion = menuMapa(jugador.turnos, jugador.pos);
        short int camino = 0;
        switch (opcion)
        {
        case 'W':
            camino = moverJugador(jugador, {char(jugador.pos.fila - 1), jugador.pos.columna});
            generarCombate(jugador, camino, aliados, opcion);
            break;
        case 'S':
            camino = moverJugador(jugador, {char(jugador.pos.fila + 1), jugador.pos.columna});
            generarCombate(jugador, camino, aliados, opcion);
            break;
        case 'A':
            camino = moverJugador(jugador, {jugador.pos.fila, char(jugador.pos.columna - 1)});
            generarCombate(jugador, camino, aliados, opcion);
            break;
        case 'D':
            camino = moverJugador(jugador, {jugador.pos.fila, char(jugador.pos.columna + 1)});
            generarCombate(jugador, camino, aliados, opcion);
            break;
        case 'C':
            return 'C';
        case 'G':
            guardarPartida(&jugador, aliados);
        }
    } while (opcion != 'T');
    return 'T';
}
