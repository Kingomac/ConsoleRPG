#include <string>
#include "estructuras.h"
#include "aliados.h"
#include "escribir.h"

using namespace std;

void restablecerSalud(int n, Personaje p[])
{
    for (int i = 0; i < n; i++)
    {
        if (p[i].salud > 0)
        {
            p[i].salud = p[i].saludTotal;
            for (int j = 0; j < 4; j++)
                p[i].ataques[j].usos = p[i].ataques[j].usosTotales;
        }
    }
}

void mostrarEstadisticas(int n, Personaje p[])
{
    for (int i = 0; i < n; i++)
    {
        escribir("\n " + p[i].nombre + " | Salud: " + to_string(p[i].salud < 0 ? 0 : p[i].salud) + "/" + to_string(p[i].saludTotal) + " | Nivel: " + to_string(p[i].nivel) + " | Velocidad: " + to_string(p[i].velocidad) + " \n", 243 + i);
        escribir(" Ataque físico: " + to_string(p[i].ataqueF) + " | Defensa física: " + to_string(p[i].defensaF) + " \n", 243 + i);
        escribir(" Ataque mágico: " + to_string(p[i].ataqueM) + " | Defensa mágica: " + to_string(p[i].defensaM) + " \n", 243 + i);
        escribir(" Ataques: \n", 243 + i);
        for (int j = 0; j < 4; j++)
        {
            escribir("  " + to_string(j + 1) + " - " + p[i].ataques[j].nombre + " | " + to_string(p[i].ataques[j].usos) + "/" + to_string(p[i].ataques[j].usosTotales) + " | " + (p[i].ataques[j].fisico ? "Físico" : "Mágico") + " | Fuerza: " + to_string(p[i].ataques[j].fuerza) + " \n", 243 + i);
        }
    }
}
