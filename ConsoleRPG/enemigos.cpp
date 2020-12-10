#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "estructuras.h"

using namespace std;
void cargarPersonajes(Personaje p[], int lineas, string archivo);
int contarLineas(string archivo);

Personaje *enemigos1 = NULL;
int nEnemigos1;
Personaje *enemigos2 = NULL;
int nEnemigos2;
Personaje *enemigos3 = NULL;
int nEnemigos3;

short int aleatorio_10a10()
{
    const short int a = rand() % 20 - 10;
    return a;
}

Personaje enemigoAleatorio(char camino)
{
    Personaje enemigo;
    if (camino == 1 && enemigos1 == NULL)
    {
        nEnemigos1 = contarLineas("./enemigos/1.csv");
        if ((enemigos1 = new Personaje[nEnemigos1]) == NULL)
        {
            cout << "Error de asignación de memoria" << endl;
            exit(1);
        }
        cargarPersonajes(enemigos1, nEnemigos1, "./enemigos/1.csv");
    }
    else if (camino == 2 && enemigos2 == NULL)
    {
        nEnemigos2 = contarLineas("./enemigos/2.csv");
        if ((enemigos3 = new Personaje[nEnemigos2]) == NULL)
        {
            cout << "Error de asignación de memoria" << endl;
            exit(1);
        }
        cargarPersonajes(enemigos2, nEnemigos2, "./enemigos/2.csv");
    }
    else
    {
        nEnemigos3 = contarLineas("./enemigos/3.csv");
        if ((enemigos3 = new Personaje[nEnemigos3]) == NULL)
        {
            cout << "Error de asignación de memoria" << endl;
            exit(1);
        }
        cargarPersonajes(enemigos3, nEnemigos3, "./enemigos/3.csv");
    }

    if (camino == 1)
        enemigo = enemigos1[rand() % nEnemigos1];
    else if (camino == 2)
        enemigo = enemigos2[rand() % nEnemigos2];
    else
        enemigo = enemigos3[rand() % nEnemigos3];
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

void liberarMemEnemigos()
{
    if (enemigos1 != NULL)
        delete[] enemigos1;
    if (enemigos2 != NULL)
        delete[] enemigos2;
    if (enemigos3 != NULL)
        delete[] enemigos3;
}
