#include <iostream>
#include <string>
#include "estructuras.h"
#include "aliados.h"
#include "escribir.h"

using namespace std;

int nAliados; // Variable global que guarda el número de aliados

void restablecerSalud(Personaje aliados[])
{
    for (int i = 0; i < nAliados; i++)
    {
        if (aliados[i].salud > 0)
        {
            aliados[i].salud = aliados[i].saludTotal;
            for (int j = 0; j < 4; j++)
                aliados[i].ataques[j].usos = aliados[i].ataques[j].usosTotales;
        }
    }
}

void mostrarEstadisticas(Personaje aliados[])
{
    for (int i = 0; i < nAliados; i++)
    {
        escribir("\n " + aliados[i].nombre + " | Salud: " + to_string(aliados[i].salud < 0 ? 0 : aliados[i].salud) + "/" + to_string(aliados[i].saludTotal) + " | Nivel: " + to_string(aliados[i].nivel) + " | Velocidad: " + to_string(aliados[i].velocidad) + " \n", 243 + i);
        escribir(" Ataque físico: " + to_string(aliados[i].ataqueF) + " | Defensa física: " + to_string(aliados[i].defensaF) + " \n", 243 + i);
        escribir(" Ataque mágico: " + to_string(aliados[i].ataqueM) + " | Defensa mágica: " + to_string(aliados[i].defensaM) + " \n", 243 + i);
        escribir(" Ataques: \n", 243 + i);
        for (int j = 0; j < 4; j++)
        {
            escribir("  " + to_string(j + 1) + " - " + aliados[i].ataques[j].nombre + " | " + to_string(aliados[i].ataques[j].usos) + "/" + to_string(aliados[i].ataques[j].usosTotales) + " | " + (aliados[i].ataques[j].fisico ? "Físico" : "Mágico") + " | Fuerza: " + to_string(aliados[i].ataques[j].fuerza) + " \n", 243 + i);
        }
    }
}
