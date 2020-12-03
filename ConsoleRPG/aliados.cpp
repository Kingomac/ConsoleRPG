#include <iostream>
#include "estructuras.h"
#define ALIADOS 3

using namespace std;

void restablecerSalud(Personaje aliados[])
{
    for (char i = 0; i < ALIADOS; i++)
    {
        aliados[i].salud = aliados[i].saludTotal + 1.25 * aliados[i].nivel;
        for (char j = 0; j < 4; j++)
        {
            aliados[i].ataques[j].usos = aliados[i].ataques[j].usosTotales;
        }
    }
}