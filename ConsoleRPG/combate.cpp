#include <iostream>
#include "estructuras.h"
#include <stdlib.h>
#include <time.h>
#define numEnemigos 2

using namespace std;

Personaje enemigoAleatorio(char camino);

void mostrarAtaques(Ataque ataques[4])
{
    for (int i = 0; i < 4; i++)
    {
        cout << i + 1 << " - " << ataques[i].nombre << endl;
    }
    cout << "Selecciona un ataque 1 - 4" << endl;
}

struct PCombatiente
{
    Personaje p;
    short int orden;
    Personaje objetivo;
    bool jugador = false;
    short int ataque = -1;
};

void combate(Personaje aliados[3], char camino)
{
    // Generar enemigos aleatorios
    srand(time(NULL));
    bool jugadoresVivos = true;
    bool enemigosVivos = true;
    //int numEnemigos;
    //const int numEnemigos = camino > 1 ? rand() % 3 + 1 : rand() % 6 + 1;
    cout << "EMPIEZA EL COMBATE" << endl;
    cout << "numEnemigos: " << numEnemigos << endl;

    Personaje enemigos[numEnemigos];
    for (Personaje &e : enemigos)
    {
        e = enemigoAleatorio(camino);
        cout << "ENEMIGO CREADO: " << e.nombre << endl;
    }
    cout << "Han aparecido: " << endl;
    do
    {
        //Mostrar enemigos
        for (int i = 0; i < numEnemigos; i++)
        {
            cout << i + 1 << " - " << enemigos[i].nombre << " - " << enemigos[i].salud << endl;
        }
        //Menú de ataque del jugador
        short int ataques[3];
        short int objetivos[3];
        short int o;
        for (int i = 0; i < 3; i++)
        {
            do
            {
                cout << "********************" << endl;
                cout << "Turno de " << aliados[i].nombre << endl;
                cout << "Salud: " << aliados[i].salud << endl;
                mostrarAtaques(aliados[i].ataques);
                cin >> o;
                ataques[i] = o - 1;
                do
                {
                    cout << "Objetivo del ataque:" << endl;
                    for (int i = 0; i < numEnemigos; i++)
                    {
                        cout << i + 1 << " - " << enemigos[i].nombre << endl;
                    }
                    cin >> o;
                } while (o > numEnemigos || o < 1);
                objetivos[i] = o - 1;
            } while (ataques[i] < 0 || ataques[i] > 4);
        }
        //Identificar a los combatientes
        PCombatiente total[3 + numEnemigos];
        for (int i = 0; i < 3; i++)
        {
            total[i] = {aliados[i], i, enemigos[objetivos[i]], true, ataques[i]};
        }
        for (int i = 3; i < numEnemigos + 3; i++)
        {
            cout << "Enemigo " << i - 3 << ", " << enemigos[i - 3].nombre << " asignado a " << i << endl;
            total[i] = {enemigos[i - 3], i, aliados[i - 3], false};
        }
        //Establecer orden de ataque
        for (int i = 0; i < numEnemigos + 2; i++)
        {
            if (total[i].p.velocidad < total[i + 1].p.velocidad)
                swap(total[i], total[i + 1]);
        }
        for (const auto &p : total)
        {
            cout << "Combatiente: " << p.p.nombre << endl;
        }
        /*
        //Hacer daños
        for (PCombatiente &p : total)
        {
            cout << "COMBATIENDO: " << p.p.nombre << endl;
            if (p.jugador)
            {
                const Ataque a = p.p.ataques[p.ataque];
                short int restarSalud = a.fuerza + p.p.ataqueF;
                if (a.fisico)
                    restarSalud -= p.objetivo.defensaF;
                else
                    restarSalud -= p.objetivo.defensaM;
                p.objetivo.salud -= restarSalud;
            }
            else
            {
                cout << "SOY UNA IA TONTA SORRY" << endl;
            }
        }
        enemigosVivos = false;
        jugadoresVivos = false;
        for (int i = 0; i < numEnemigos + 3 && (!enemigosVivos || !jugadoresVivos); i++)
        {
            if (total[i].jugador && total[i].p.salud > 0)
                jugadoresVivos = true;
            if (!total[i].jugador && total[i].p.salud > 0)
                enemigosVivos = true;
            cout << total[i].p.nombre << "  " << total[i].p.salud << endl;
        }
        for (const auto &p : total)
        {
            cout << p.p.nombre << ": " << p.p.salud;
        }*/
    } while (enemigosVivos && jugadoresVivos);
}
