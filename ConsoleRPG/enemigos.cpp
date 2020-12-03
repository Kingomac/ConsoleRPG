#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "estructuras.h"
#define RAIZ "C:/Users/kingo/Desktop/ConsoleRPG/Juego/"  //CAMIBIAR EN LA VERSIÓN DEFINITIVA POR UNA RUTA RELATIVA

using namespace std;

short int aleatorio_10a10()
{
    const short int a = rand() % 20 - 10;
    return a;
}

Personaje *enemigos1;
int nenemigos1 = 0;
Personaje *enemigos2;
int nenemigos2 = 0;
Personaje *enemigos3;
int nenemigos3 = 0;

Personaje enemigoAleatorio(char camino)
{
    Personaje enemigo;
    if(camino == 1 && enemigos1 == NULL)
        cargarPersonajes(enemigos1, nenemigos1, string(RAIZ) + string("enemigos/1.csv"));
    else if(camino == 2 && enemigos2 == NULL)
        cargarPersonajes(enemigos2, nenemigos2, string(RAIZ) + string("enemigos/2.csv"));
    else
        cargarPersonajes(enemigos3, nenemigos3, string(RAIZ) + string("enemigos/3.csv"));

    if(camino == 1)
        enemigo = enemigos1[rand()%nenemigos1];
    else if(camino == 2)
        enemigo = enemigos2[rand()%nenemigos2];
    else
        enemigo = enemigos3[rand()%nenemigos3];
    enemigo.ataqueF += aleatorio_10a10();
    enemigo.ataqueM += aleatorio_10a10();
    enemigo.defensaF += aleatorio_10a10();
    enemigo.defensaM += aleatorio_10a10();
    enemigo.saludTotal += aleatorio_10a10();
    enemigo.salud = enemigo.saludTotal;
    enemigo.velocidad += aleatorio_10a10();
    enemigo.nivel += aleatorio_10a10() / 3;
    return enemigo;
}
