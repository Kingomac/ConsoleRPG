#include <iostream>
#include "estructuras.h"
#include <stdlib.h>
#include <time.h>
#include <string>
#include <math.h>
#include "utilidades.h"
#define ALIADOS 3

using namespace std;

Personaje enemigoAleatorio(char camino);

int dano(Ataque ataque, Personaje atacante, Personaje objetivo) // Sería daño
{
    if (objetivo.velocidad > atacante.velocidad && rand() % 100 < 50)
    {
        cout << objetivo.nombre << " ha esquivado el ataque de" << atacante.nombre << endl;
        return 0;
    }
    else
    {
        short int restarSalud = ataque.fuerza * log(atacante.nivel + 1);
        if (ataque.fisico)
        {
            restarSalud += atacante.ataqueF * log(atacante.nivel + 1);
            restarSalud -= objetivo.defensaF * log(objetivo.nivel + 1);
        }
        else
        {
            restarSalud += atacante.ataqueM * log(atacante.nivel + 1);
            restarSalud -= objetivo.defensaM * log(objetivo.nivel + 1);
        }
        cout << atacante.nombre << " HACE " << (restarSalud > 0 ? restarSalud : 0) << " DE DA�O A " << objetivo.nombre << endl; // MENSAJE DE PRUEBAS
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

    //Identificar a los combatientes
    PCombatiente total[ALIADOS + numEnemigos];
    for (short int i = 0; i < nVivos(ALIADOS, aliados); i++)
        total[i] = {&aliados[i], i, &enemigos[0], true, 0};

    for (short int i = ALIADOS; i < ALIADOS + numEnemigos; i++)
        total[i] = {&enemigos[i - 3], i, &aliados[personajeAleatorioVivo(aliados)], false};

    //Establecer orden de ataque
    for (int i = 0; i < ALIADOS + numEnemigos - 1; i++)
        if (total[i].p->velocidad < total[i + 1].p->velocidad)
            swap(total[i], total[i + 1]);

    do
    {
        //Mostrar enemigos
        for (int i = 0; i < numEnemigos; i++)
            cout << i + 1 << " - " << enemigos[i].nombre << " - " << (enemigos[i].salud <= 0 ? "MUERTO" : to_string(enemigos[i].salud)) << endl;

        //Menú de ataque del jugador
        char ataques[3];
        char objetivos[3];
        short int o;

        for (char i = 0; i < ALIADOS + numEnemigos; i++)
        {
            if (!total[i].jugador || total[i].p->salud < 0)
                continue;
            cout << "*************************" << endl;
            cout << "Turno de " << total[i].p->nombre << endl;
            cout << "Salud: " << total[i].p->salud << endl;
            for (char j = 0; j < 4; j++)
                cout << j + 1 << " - " << total[i].p->ataques[j].nombre << "\t" << total[i].p->ataques[j].usos << "/" << total[i].p->ataques[j].usosTotales << endl;

            // Seleccionar el ataque
            int opcion;
            do
                opcion = leerEntero("Selecciona un ataque 1 - 4");
            while (opcion < 1 || opcion > 4);
            total[i].ataque = opcion - 1;
            cout << "ATAQUE SELECCIONADO: " << opcion << endl;

            // Mostrar enemigos y seleccionar el objetivo
            cout << "Enemigos:" << endl;
            for (char j = 0; j < numEnemigos; j++)
                cout << int(j) + 1 << " - " << (enemigos[j].salud <= 0 ? "MUERTO" : enemigos[j].nombre) << endl;
            do
                opcion = leerEntero("Selecciona el objetivo");
            while (opcion < 1 || opcion > numEnemigos);
            total[i].objetivo = &enemigos[opcion - 1];
        }
        //Hacer daños
        for (int i = 0; i < numEnemigos + ALIADOS; i++)
        {
            if (total[i].p->salud > 0 && total[i].p->ataques[total[i].ataque].usos > 0)
            {
                if (total[i].jugador)
                {
                    if (total[i].p->ataques[total[i].ataque].fuerza > 0)
                    {
                        int d = dano(total[i].p->ataques[total[i].ataque], *(total[i].p), *(total[i].objetivo));
                        if (total[i].objetivo->salud > 0 && total[i].objetivo->salud - d < 0)
                        {
                            total[i].p->nivel++;
                            cout << total[i].p->nombre << " ha subido a nivel " << total[i].p->nivel << endl;
                        }
                        total[i].objetivo->salud -= d;
                    }
                    else
                    {
                        total[i].p->salud -= total[i].p->ataques[total[i].ataque].fuerza;
                    }
                }
                else
                {
                    if (camino == 1) // Ataque aleatorio
                        total[i].ataque = rand() % 4;
                    else if (camino == 2) // Ataque más fuerte
                    {
                        for (int j = 0; j < 4; j++)
                            if (total[i].p->ataques[j].usos > 0 && total[i].p->ataques[j].fuerza > total[i].p->ataques[total[i].ataque].fuerza)
                                total[i].ataque = j;
                    }
                    else
                    {
                        total[i].ataque = 0;
                        for (int j = 0; j < 4; j++) // Ataque más eficiente
                            if (total[i].p->ataques[j].usos > 0 && dano(total[i].p->ataques[j], *(total[i].p), *(total[i].objetivo)) > dano(total[i].p->ataques[total[i].ataque], *(total[i].p), *(total[i].objetivo)))
                                total[i].ataque = j;
                    }
                    if (total[i].p->ataques[total[i].ataque].fuerza > 0)
                        total[i].objetivo->salud -= dano(total[i].p->ataques[total[i].ataque], *(total[i].p), *(total[i].objetivo));
                    else
                        total[i].p->salud -= total[i].p->ataques[total[i].ataque].fuerza;
                }
            }
            if (total[i].p->ataques[total[i].ataque].usos <= 0)
                cout << "El ataque ha fallado" << endl;
            else
                total[i].p->ataques[total[i].ataque].usos--;
        }
    } while (nVivos(numEnemigos, enemigos) > 0 && nVivos(ALIADOS, aliados) > 0);
}
