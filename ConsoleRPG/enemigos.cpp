#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "estructuras.h"

using namespace std;

short int aleatorio_10a10()
{
    const short int a = rand() % 20 - 10;
    return a;
}

Personaje enemigoAleatorio(char camino)
{
    Personaje enemigo;
    if (camino == 1)
    {
        switch (rand() % 2)
        {
        case 0:
            enemigo =
                {
                    "Slime",
                    rand() % 5 + 1,
                    100,
                    {
                        {"Ataque1",
                         10,
                         true,
                         10},
                        {"Ataque1",
                         10,
                         true,
                         10},
                        {"Ataque1",
                         10,
                         true,
                         10},
                        {"Ataque1",
                         10,
                         true,
                         10},
                    },
                    100};
        case 1:
            enemigo =
                {
                    "Goblin",
                    rand() % 5 + 1,
                    100,
                    {
                        {"Ataque1",
                         10,
                         true,
                         10},
                        {"Ataque1",
                         10,
                         true,
                         10},
                        {"Ataque1",
                         10,
                         true,
                         10},
                        {"Ataque1",
                         10,
                         true,
                         10},
                    },
                    100};
            // M�s enemigos
        }
    }
    else if (camino == 2)
    {
        switch (rand() % 2)
        {
        case 0:
            enemigo =
                {
                    "Hombre lagarto",
                    rand() % 5 + 1,
                    100,
                    {
                        {"Ataque1",
                         10,
                         true,
                         10},
                        {"Ataque1",
                         10,
                         true,
                         10},
                        {"Ataque1",
                         10,
                         true,
                         10},
                        {"Ataque1",
                         10,
                         true,
                         10},
                    },
                    100};
        case 1:
            enemigo =
                {
                    "Soldado demonio",
                    rand() % 5 + 1,
                    100,
                    {
                        {"Ataque1",
                         10,
                         true,
                         10},
                        {"Ataque1",
                         10,
                         true,
                         10},
                        {"Ataque1",
                         10,
                         true,
                         10},
                        {"Ataque1",
                         10,
                         true,
                         10},
                    },
                    100};
        }
    }
    else
    {
        switch (rand() % 2)
        {
        case 0:
            enemigo =
                {
                    "Slime gigante",
                    rand() % 5 + 1,
                    100,
                    {
                        {"Ataque1",
                         10,
                         true,
                         10},
                        {"Ataque1",
                         10,
                         true,
                         10},
                        {"Ataque1",
                         10,
                         true,
                         10},
                        {"Ataque1",
                         10,
                         true,
                         10},
                    },
                    100};
        case 1:
            enemigo =
                {
                    "Rey demonio",
                    rand() % 5 + 1,
                    100,
                    {
                        {"Ataque1",
                         10,
                         true,
                         10},
                        {"Ataque1",
                         10,
                         true,
                         10},
                        {"Ataque1",
                         10,
                         true,
                         10},
                        {"Ataque1",
                         10,
                         true,
                         10},
                    },
                    100};
        }
    }
    enemigo.ataqueF += aleatorio_10a10();
    enemigo.ataqueM += aleatorio_10a10();
    enemigo.defensaF += aleatorio_10a10();
    enemigo.defensaM += aleatorio_10a10();
    enemigo.salud += aleatorio_10a10();
    enemigo.velocidad += aleatorio_10a10();
    enemigo.nivel += aleatorio_10a10() / 3;
    return enemigo;
}
