#include <iostream>
#include "estructuras.h"
#include <stdlib.h>
#include <time.h>
#include <string>
#define ALIADOS 3

using namespace std;

Personaje enemigoAleatorio(char camino);

void mostrarAtaques(Ataque ataques[4])
{
    for (int i = 0; i < 4; i++)
        cout << i + 1 << " - " << ataques[i].nombre << endl;
    cout << "Selecciona un ataque 1 - 4" << endl;
}

int dano(Ataque ataque, Personaje atacante, Personaje objetivo) // Sería daño
{
    if (objetivo.velocidad > atacante.velocidad && rand() % 100 < 50)
    {
        cout << "¡Ataque esquivado!" << endl;
        return 0;
    }
    else
    {
        short int restarSalud = ataque.fuerza;
        if (ataque.fisico)
        {
            restarSalud += atacante.ataqueF;
            restarSalud -= objetivo.defensaF;
        }
        else
        {
            restarSalud += atacante.ataqueM;
            restarSalud -= objetivo.defensaM;
        }
        cout << atacante.nombre << " HACE " << restarSalud << " DE DAÑO A " << objetivo.nombre << endl; // MENSAJE DE PRUEBAS
        return restarSalud > 0 ? restarSalud : 0;
    }
}

char nVivos(char n, Personaje p[])
{
    char suma = 0;
    for (char i = 0; i < n; i++)
        if (p[i].salud >= 0)
            suma++;
    return suma;
}

char personajeAleatorioVivo(Personaje aliados[])
{
    bool vivos[ALIADOS] = {true};
    for (char i = 0; i < 0; i++)
        if (aliados[i].salud <= 0)
            vivos[i] = false;
    for (char i = 0; i < 2 * ALIADOS; i++)
    {
        char a = rand() % ALIADOS;
        if (aliados[a].salud > 0)
            return a;
    }
    return rand() % ALIADOS;
}

void combate(Personaje aliados[ALIADOS], char camino)
{
    // Definir número de enemigos según el tipo de camino
    const char numEnemigos = camino <= 2 ? rand() % 3 + 1 : rand() % 6 + 1; /// RECUERDA CAMBIAR EL 2 POR UN 1 PARA QUE PUEDA SALIR SOLO 1 ENEMIGO

    Personaje enemigos[numEnemigos];
    for (Personaje &e : enemigos)
        e = enemigoAleatorio(camino);

    cout << "Han aparecido: " << endl;
    do
    {
        //Mostrar enemigos
        for (int i = 0; i < numEnemigos; i++)
            cout << i + 1 << " - " << enemigos[i].nombre << " - " << (enemigos[i].salud <= 0 ? "MUERTO" : to_string(enemigos[i].salud)) << endl;

        //Menú de ataque del jugador
        char ataques[3];
        char objetivos[3];
        short int o;
        for (char i = 0; i < ALIADOS; i++)
        {
            if (aliados[i].salud > 0)
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
                            cout << i + 1 << " - " << (enemigos[i].salud <= 0 ? "MUERTO" : enemigos[i].nombre) << endl;
                        }
                        cin >> o;
                    } while (o > numEnemigos || o < 1);
                    objetivos[i] = o - 1;
                } while (ataques[i] < 0 || ataques[i] > 4);
        }
        //Identificar a los combatientes
        PCombatiente total[ALIADOS + numEnemigos];
        for (short int i = 0; i < nVivos(ALIADOS, aliados); i++)
            total[i] = {&aliados[i], i, &enemigos[objetivos[i]], true, ataques[i]};

        for (short int i = ALIADOS; i < ALIADOS + numEnemigos; i++)
            total[i] = {&enemigos[i - 3], i, &aliados[personajeAleatorioVivo(aliados)], false};

        //Establecer orden de ataque
        for (int i = 0; i < nVivos(numEnemigos, enemigos) + nVivos(numEnemigos, enemigos) - 1; i++)
            if (total[i].p->velocidad < total[i + 1].p->velocidad)
                swap(total[i], total[i + 1]);

        //Hacer daños
        for (int i = 0; i < nVivos(numEnemigos, enemigos) + nVivos(ALIADOS, aliados); i++)
        {
            if (total[i].p->salud > 0)
            {
                if (total[i].jugador)
                    total[i].objetivo->salud -= dano(total[i].p->ataques[total[i].ataque], *(total[i].p), *(total[i].objetivo));
                else
                {
                    if (camino == 1) // Ataque aleatorio
                        total[i].ataque = rand() % 4;
                    else if (camino == 2) // Ataque más fuerte
                    {
                        for (int j = 0; j < 4; j++)
                            if (total[i].p->ataques[j].fuerza > total[i].p->ataques[total[i].ataque].fuerza)
                                total[i].ataque = j;
                    }
                    else
                    {
                        total[i].ataque = 0;
                        for (int j = 0; j < 4; j++) // Ataque más eficiente
                            if (dano(total[i].p->ataques[j], *(total[i].p), *(total[i].objetivo)) > dano(total[i].p->ataques[total[i].ataque], *(total[i].p), *(total[i].objetivo)))
                                total[i].ataque = j;
                    }
                    total[i].objetivo->salud -= dano(total[i].p->ataques[total[i].ataque], *(total[i].p), *(total[i].objetivo));
                }
            }
        }
    } while (nVivos(numEnemigos, enemigos) > 0 && nVivos(ALIADOS, aliados) > 0);
}
