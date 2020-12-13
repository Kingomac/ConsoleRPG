#include <iostream>
#include "estructuras.h"
#define ALIADOS 3

using namespace std;

void restablecerSalud(Personaje aliados[])
{
    for (int i = 0; i < ALIADOS; i++)
    {
        if (aliados[i].salud > 0)
        {
            aliados[i].salud = aliados[i].saludTotal + 1.25 * aliados[i].nivel;
            for (int j = 0; j < 4; j++)
            {
                aliados[i].ataques[j].usos = aliados[i].ataques[j].usosTotales;
            }
        }
    }
}
