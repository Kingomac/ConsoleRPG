#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "estructuras.h"
#include "escribir.h"
#include "textos.h"
#include "enemigos.h"
#include "utilidades.h"
#include "cargarPersonajes.h"

using namespace std;

/**
 * Variables globales que guardan el número de enemigos
 * y los enemigos cargados previamente de archivos
**/
Personaje *enemigos1 = NULL;
int nEnemigos1;
Personaje *enemigos2 = NULL;
int nEnemigos2;
Personaje *enemigos3 = NULL;
int nEnemigos3;

Personaje enemigoAleatorio(int camino)
{
    Personaje enemigo;
    if (camino == 1 && enemigos1 == NULL)
    {
        nEnemigos1 = contarLineas(R_EN_1);
        if (nEnemigos1 == -1)
        {
            escribir(T_ERR_FIC + R_EN_1 + " \n", 79);
            exit(1);
        }
        if ((enemigos1 = new Personaje[nEnemigos1]) == NULL)
        {
            escribir(T_ERR_MEM, 79);
            exit(1);
        }
        cargarPersonajes(enemigos1, nEnemigos1, R_EN_1);
    }
    else if (camino == 2 && enemigos2 == NULL)
    {
        nEnemigos2 = contarLineas(R_EN_2);
        if (nEnemigos2 == -1)
        {
            escribir(T_ERR_FIC + R_EN_2 + " \n", 79);
            exit(1);
        }
        if ((enemigos3 = new Personaje[nEnemigos2]) == NULL)
        {
            escribir(T_ERR_MEM, 79);
            exit(1);
        }
        cargarPersonajes(enemigos2, nEnemigos2, R_EN_2);
    }
    else
    {
        nEnemigos3 = contarLineas(R_EN_3);
        if (nEnemigos3 == -1)
        {
            escribir(T_ERR_FIC + R_EN_3 + " \n", 79);
            exit(1);
        }
        if ((enemigos3 = new Personaje[nEnemigos3]) == NULL)
        {
            escribir(T_ERR_MEM, 79);
            exit(1);
        }
        cargarPersonajes(enemigos3, nEnemigos3, R_EN_3);
    }

    if (camino == 1)
        enemigo = enemigos1[rand() % nEnemigos1];
    else if (camino == 2)
        enemigo = enemigos2[rand() % nEnemigos2];
    else
        enemigo = enemigos3[rand() % nEnemigos3];
    enemigo.ataqueF += rand() % 20 - 10;
    enemigo.ataqueM += rand() % 20 - 10;
    enemigo.defensaF += rand() % 20 - 10;
    enemigo.defensaM += rand() % 20 - 10;
    enemigo.saludTotal += rand() % 20 - 10;
    enemigo.salud = enemigo.saludTotal;
    enemigo.velocidad += rand() % 20 - 10;
    enemigo.nivel += rand() % 4;
    return enemigo;
}

void liberarMemEnemigos()
{
    if (enemigos1 != NULL)
        delete[] enemigos1;
    if (enemigos2 != NULL)
        delete[] enemigos2;
    if (enemigos3 != NULL)
        delete[] enemigos3;
}
