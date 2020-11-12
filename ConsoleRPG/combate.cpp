#include <iostream>
#include "estructuras.h"
#include <stdlib.h>
#include <time.h>
//#define numEnemigos 2

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

int dano(Ataque ataque, Personaje atacante, Personaje objetivo)   // Sería daño
{
    if (objetivo.velocidad > atacante.velocidad && rand()%100 < 50) {
        cout << "¡Ataque esquivado!" << endl;
        return 0;
    }
    else
    {
        short int restarSalud = ataque.fuerza;
        if (ataque.fisico) {
            restarSalud += atacante.ataqueF;
            restarSalud -= objetivo.defensaF;
        }
        else{
            restarSalud += atacante.ataqueM;
            restarSalud -= objetivo.defensaM;
        }
        cout << atacante.nombre << " HACE " << restarSalud << " DE DAÑO A " << objetivo.nombre << endl; // MENSAJE DE PRUEBAS
        return restarSalud > 0 ? restarSalud : 0;
    }
}

struct PCombatiente
{
    Personaje p;
    short int orden;
    Personaje *objetivo;
    bool jugador = false;
    short int ataque = -1;
};

void combate(Personaje aliados[3], char camino)
{
    // Generar enemigos aleatorios
    bool jugadoresVivos = true;
    bool enemigosVivos = true;
    // Definir número de enemigos según el tipo de camino
    const short int numEnemigos = camino <= 2 ? rand() % 3 + 1 : rand() % 6 + 1;

    Personaje enemigos[numEnemigos];
    for (Personaje &e : enemigos)
    {
        e = enemigoAleatorio(camino);
        cout << "ENEMIGO CREADO: " << e.nombre << endl;  // MENSAJE DE PRUEBAS
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
                }
                while (o > numEnemigos || o < 1);
                objetivos[i] = o - 1;
            }
            while (ataques[i] < 0 || ataques[i] > 4);
        }
        cout << "AGRUPAR ALIADOS Y ENEMIGOS" << endl;  // MENSAJE DE PRUEBAS
        //Identificar a los combatientes
        PCombatiente total[3 + numEnemigos];
        for (short int i = 0; i < 3; i++)
        {
            total[i] = {aliados[i], i, &enemigos[objetivos[i]], true, ataques[i]};
        }
        for (short int i = 3; i < numEnemigos + 3; i++)
        {
            total[i] = {enemigos[i - 3], i, &aliados[i - 3], false};
        }
        //Establecer orden de ataque
        cout << "ORDENAR ENEMIGOS" << endl;   // MENSAJE DE PRUEBAS
        for (int i = 0; i < numEnemigos + 2; i++)
        {
            if (total[i].p.velocidad < total[i + 1].p.velocidad)
                swap(total[i], total[i + 1]);
        }
        //Hacer daños
        cout << "DAÑOS:" << endl;
        for (PCombatiente &p : total)
        {
            if (p.jugador)
                p.objetivo->salud -= dano(p.p.ataques[p.ataque], p.p, *(p.objetivo));
            else
            {
                cout << "SOY UNA IA TONTA SORRY" << endl;
            }
        }
        enemigosVivos = false;
        jugadoresVivos = false;
        for (int i = 0; i < numEnemigos + 3; i++)
        {
            if (total[i].jugador && total[i].p.salud >= 0)
                jugadoresVivos = true;
            if (!total[i].jugador && total[i].p.salud >= 0)
                enemigosVivos = true;
            cout << total[i].p.nombre << "  " << total[i].p.salud << endl;
        }
    }
    while (enemigosVivos && jugadoresVivos);
}
