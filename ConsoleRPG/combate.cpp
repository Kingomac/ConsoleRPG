#include "estructuras.h"
#include <stdlib.h>
#include <time.h>
#include <string>
#include <math.h>
#include "utilidades.h"
#include "escribir.h"
#include "textos.h"
#include "enemigos.h"
#include "personajes.h"

using namespace std;

extern int nAliados;

int dano(Ataque ataque, Personaje atacante, Personaje objetivo) // Sería daño
{
    if (objetivo.velocidad > atacante.velocidad && rand() % 100 < 16)
        return 0;
    else
    {
        int restarSalud = sqrt(2 * ataque.fuerza) + log(atacante.nivel + 1);
        if (ataque.fisico)
        {
            restarSalud += sqrt(atacante.ataqueF) + log(atacante.nivel + 1);
            restarSalud -= sqrt(objetivo.defensaF) + log(objetivo.nivel + 1);
        }
        else
        {
            restarSalud += sqrt(atacante.ataqueM) + log(atacante.nivel + 1);
            restarSalud -= sqrt(objetivo.defensaM) + log(objetivo.nivel + 1);
        }
        return restarSalud > 0 ? restarSalud * 1.5 : 1;
    }
}

void combate(Personaje aliados[], int camino)
{
    // Definir número de enemigos según el tipo de camino
    int numEnemigos;
    switch (camino)
    {
    case 1:
        numEnemigos = rand() % 2 + 1;
        break;
    case 2:
        numEnemigos = rand() % 3 + 1;
        break;
    case 3:
        numEnemigos = rand() % 3 + 1 + rand() % 3;
        break;
    case 6:
        numEnemigos = contarLineas(R_EN_4);
    }

    if (numEnemigos == -1)
    {
        escribir(T_ERR_FIC + R_EN_4 + " \n", 79);
        exit(1);
    }

    Personaje *enemigos = NULL;
    if ((enemigos = new Personaje[numEnemigos]) == NULL)
        escribir(T_ERR_MEM, 79);
    else
    {
        if (camino != 6)
            for (int i = 0; i < numEnemigos; i++)
                enemigos[i] = enemigoAleatorio(camino);
        else
            cargarPersonajes(enemigos, numEnemigos, R_EN_4);

        //Identificar a los combatientes
        PCombatiente *total = NULL;
        if ((total = new PCombatiente[nVivos(nAliados, aliados) + numEnemigos]) == NULL)
            escribir(T_ERR_MEM, 79);
        else
        {

            // Definir aliados combatientes
            int resta = 0;
            for (int i = 0; i < nAliados; i++)
            {
                if (aliados[i].salud > 0)
                    total[i - resta] = {&aliados[i], enemigos, true, 0};
                else
                    resta = i == 0 ? 1 : i;
            }
            // Definir enemigos combatientes
            for (int i = nVivos(nAliados, aliados); i < nVivos(nAliados, aliados) + numEnemigos; i++)
                total[i] = {&enemigos[i - nVivos(nAliados, aliados)], &aliados[personajeAleatorioVivo(nAliados, aliados)], false};

            //Establecer orden de ataque
            for (int i = 0; i < (nVivos(nAliados, aliados) + numEnemigos - 1); i++)
                if (total[i].p->velocidad < total[i + 1].p->velocidad)
                    swap(total[i], total[i + 1]);

            escribir(T_EN_APARECE);
            int aliadosVivosIniciales = nVivos(nAliados, aliados);
            do
            {
                //Mostrar enemigos
                for (int i = 0; i < numEnemigos; i++)
                    escribir("  " + to_string(i + 1) + " - " + enemigos[i].nombre + " - " + (enemigos[i].salud <= 0 ? T_EN_MUERTO : "Salud: " + to_string(enemigos[i].salud) + "/" + to_string(enemigos[i].saludTotal) + " · Nivel: " + to_string(enemigos[i].nivel)) + " \n", 79, 0, 25);

                escribir("\n");

                //Menú de ataque del jugador
                for (int i = 0; i < nVivos(nAliados, aliados) + numEnemigos; i++)
                {
                    if (!total[i].jugador || total[i].p->salud <= 0)
                        continue;
                    escribir(" Turno de " + total[i].p->nombre + " \n", 240, 25, 0);
                    escribir(" Salud: " + to_string(total[i].p->salud) + "/" + to_string(total[i].p->saludTotal) + " · Nivel: " + to_string(total[i].p->nivel) + " \n", 240, 25, 0);
                    for (int j = 0; j < 4; j++)
                        escribir("  " + to_string(j + 1) + " - " + total[i].p->ataques[j].nombre + "\t" + to_string(total[i].p->ataques[j].usos) + "/" + to_string(total[i].p->ataques[j].usosTotales) + "\n", 31, 10, 0);

                    // Seleccionar el ataque
                    int opcion;
                    do
                        opcion = leerEntero(" Selecciona un ataque 1 - 4\n");
                    while (opcion < 1 || opcion > 4);
                    total[i].ataque = opcion - 1;

                    // Mostrar enemigos y seleccionar el objetivo
                    if (total[i].p->ataques[total[i].ataque].fuerza < 0)
                        continue;
                    escribir(" Enemigos:\n");
                    for (int j = 0; j < numEnemigos; j++)
                        escribir("  " + to_string(j + 1) + " - " + enemigos[j].nombre + " - " + (enemigos[j].salud <= 0 ? T_EN_MUERTO : "Salud: " + to_string(enemigos[j].salud) + "/" + to_string(enemigos[j].saludTotal) + " · Nivel: " + to_string(enemigos[j].nivel)) + " \n", 79, 10, 0);
                    do
                        opcion = leerEntero(T_SEL_EN);
                    while (opcion < 1 || opcion > numEnemigos);
                    total[i].objetivo = &enemigos[opcion - 1];
                }
                //Hacer daños
                for (int i = 0; i < numEnemigos + aliadosVivosIniciales; i++)
                {
                    int danoTurno = 0;
                    if (total[i].p->salud <= 0)
                        continue;
                    if (total[i].jugador)
                    {
                        if (total[i].p->ataques[total[i].ataque].fuerza > 0)
                        {
                            danoTurno = dano(total[i].p->ataques[total[i].ataque], *(total[i].p), *(total[i].objetivo));
                            if (total[i].objetivo->salud > 0 && total[i].objetivo->salud - danoTurno <= 0)
                            {
                                total[i].p->nivel++;
                                escribir(" " + total[i].p->nombre + " ha subido a nivel " + to_string(total[i].p->nivel) + "\n", 13);
                                total[i].p->salud += total[i].p->nivel / total[i].p->saludTotal + 1;
                                total[i].p->saludTotal += total[i].p->nivel / total[i].p->saludTotal + 1;
                                escribir(" " + total[i].p->nombre + " ha recuperado " + to_string(int(total[i].p->saludTotal * 0.15)) + " puntos de salud\n", 13);
                            }
                        }
                        else
                        {
                            danoTurno = total[i].p->ataques[total[i].ataque].fuerza;
                        }
                    }
                    else
                    {
                        if (total[i].objetivo->salud <= 0)
                            total[i].objetivo = &aliados[personajeAleatorioVivo(nAliados, aliados)];
                        // Se deciden los ataques en función de la dificultad del camino
                        if (camino == 1)                  // Dificultad más baja
                            total[i].ataque = rand() % 4; // Se selecciona un ataque aleatorio
                        else if (camino == 2)             // Dificultad media
                        {
                            total[i].ataque = 0;
                            if (total[i].p->salud < total[i].p->saludTotal / 2) // En caso de que su salud esté por debajo de la mitad se cura si puede
                            {
                                for (int j = 0; j < 4; j++)
                                {
                                    if (total[i].p->ataques[j].fuerza < 0 && total[i].p->ataques[j].usos > 0)
                                    {
                                        total[i].ataque = j;
                                        break;
                                    }
                                }
                            }
                            if (total[i].ataque == 0 && total[i].p->salud > total[i].p->saludTotal / 2) // Si no se curó
                                for (int j = 0; j < 4; j++)
                                    if (total[i].p->ataques[j].usos > 0 && total[i].p->ataques[j].fuerza > total[i].p->ataques[total[i].ataque].fuerza)
                                        total[i].ataque = j;
                        }
                        else // Dificultad alta (camino 3) y combate contra el boss (camino 6)
                        {
                            total[i].ataque = 0;
                            if (total[i].p->salud < total[i].p->saludTotal)
                            {
                                // Se cura si su salud está debajo de la mitad
                                for (int j = 0; j < 4; j++)
                                    if (total[i].p->ataques[j].fuerza < 0 && total[i].p->ataques[total[i].ataque].fuerza > total[i].p->ataques[j].fuerza && total[i].p->ataques[j].usos > 0)
                                        total[i].ataque = j;
                            }
                            else
                                for (int j = 0; j < 4; j++)
                                    if (total[i].p->ataques[j].usos > 0 && dano(total[i].p->ataques[j], *(total[i].p), *(total[i].objetivo)) > dano(total[i].p->ataques[total[i].ataque], *(total[i].p), *(total[i].objetivo)))
                                        total[i].ataque = j;
                        }
                        if (total[i].p->ataques[total[i].ataque].fuerza > 0)
                            danoTurno = dano(total[i].p->ataques[total[i].ataque], *(total[i].p), *(total[i].objetivo));
                        else
                            danoTurno = total[i].p->ataques[total[i].ataque].fuerza;
                    }
                    if (total[i].p->ataques[total[i].ataque].usos <= 0)
                        escribir(" " + total[i].p->ataques[total[i].ataque].nombre + " de " + total[i].p->nombre + " ha fallado\n", total[i].jugador ? 10 : 12);
                    else
                    {

                        if (danoTurno == 0 && total[i].objetivo->salud > 0 && total[i].p->velocidad < total[i].objetivo->velocidad)
                            escribir(" ¡" + total[i].objetivo->nombre + " ha esquivado el " + total[i].p->ataques[total[i].ataque].nombre + " de " + total[i].p->nombre + "!\n", total[i].jugador ? 12 : 10);
                        else if (danoTurno < 0)
                            escribir(" ¡" + total[i].p->nombre + " ha usado " + total[i].p->ataques[total[i].ataque].nombre + " y ha recuperado " + to_string(total[i].p->ataques[total[i].ataque].fuerza * -1) + "!\n", total[i].jugador ? 13 : 11);
                        else if (danoTurno == 0)
                            escribir(" " + total[i].p->ataques[total[i].ataque].nombre + " de " + total[i].p->nombre + " ha fallado\n", total[i].jugador ? 12 : 10);
                        else if (danoTurno > 0 && total[i].objetivo->salud <= 0)
                            escribir(" ¡" + total[i].p->nombre + " ha usado " + total[i].p->ataques[total[i].ataque].nombre + " sobre el cadáver de " + total[i].objetivo->nombre + "! \n");
                        else
                            escribir(" " + total[i].p->nombre + " ha usado " + total[i].p->ataques[total[i].ataque].nombre + " y " + total[i].objetivo->nombre + " ha recibido " + to_string(danoTurno) + " de daño\n", 15);
                        if (total[i].objetivo->salud - danoTurno <= 0 && total[i].objetivo->salud > 0)
                            escribir(" " + total[i].objetivo->nombre + " ha muerto\n", total[i].jugador ? 10 : 4);
                        danoTurno > 0 ? total[i].objetivo->salud -= danoTurno : (total[i].p->salud = (total[i].p->salud - danoTurno > total[i].p->saludTotal ? total[i].p->saludTotal : total[i].p->salud - danoTurno));
                        total[i].p->ataques[total[i].ataque].usos--;
                    }
                }
                escribir("\n");
            } while (nVivos(numEnemigos, enemigos) > 0 && nVivos(nAliados, aliados) > 0);
            if (camino == 6 && nVivos(nAliados, aliados) > 0)
                escribirArchivo(R_T_FIN, 7, 10, 0);
            delete[] enemigos;
            delete[] total;
        }
    }
}
