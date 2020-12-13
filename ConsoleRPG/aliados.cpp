#include <iostream>
#include "estructuras.h"
#include "aliados.h"

using namespace std;

int nAliados;

void restablecerSalud(Personaje aliados[])
{
    for (int i = 0; i < nAliados; i++)
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
