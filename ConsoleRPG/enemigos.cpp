#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "estructuras.h"

using namespace std;

Personaje enemigoAleatorio(char camino)
{
    srand(time(NULL));
    if (camino == 1)
    {
        switch (rand() % 2)
        {
        case 0:
            return {
                "Slime",
                rand() % 5 + 1,
                100,
                {
                    {"Ataque1",
                     10,
                     true},
                    {"Ataque1",
                     10,
                     true},
                    {"Ataque1",
                     10,
                     true},
                    {"Ataque1",
                     10,
                     true},
                },
                100};
        case 1:
            return {
                "Goblin",
                rand() % 5 + 1,
                100,
                {{"Ataque1",
                  10,
                  true},
                 {"Ataque1",
                  10,
                  true},
                 {"Ataque1",
                  10,
                  true},
                 {"Ataque1",
                  10,
                  true}},
                100};
            // M�s enemigos
        }
    }
    else if (camino == 2)
    {
        switch (rand() % 2)
        {
        case 0:
            return {
                "Hombre lagarto",
                rand() % 5 + 1,
                100,
                {{"Ataque1",
                  10,
                  true},
                 {"Ataque1",
                  10,
                  true},
                 {"Ataque1",
                  10,
                  true},
                 {"Ataque1",
                  10,
                  true}},
                100};
        case 1:
            return {
                "Soldado demonio",
                rand() % 5 + 1,
                100,
                {{"Ataque1",
                  10,
                  true},
                 {"Ataque1",
                  10,
                  true},
                 {"Ataque1",
                  10,
                  true},
                 {"Ataque1",
                  10,
                  true}},
                100};
        }
    }
    else
    {
        switch (rand() % 2)
        {
        case 0:
            return {
                "Slime gigante",
                rand() % 5 + 1,
                100,
                {{"Ataque1",
                  10,
                  true},
                 {"Ataque1",
                  10,
                  true},
                 {"Ataque1",
                  10,
                  true},
                 {"Ataque1",
                  10,
                  true}},
                100};
        case 1:
            return {
                "Rey demonio",
                rand() % 5 + 1,
                100,
                {{"Ataque1",
                  10,
                  true},
                 {"Ataque1",
                  10,
                  true},
                 {"Ataque1",
                  10,
                  true},
                 {"Ataque1",
                  10,
                  true}},
                100};
        }
    }
}
