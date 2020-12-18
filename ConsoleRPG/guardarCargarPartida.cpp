#include <fstream>
#include <iostream>
#include "escribir.h"
#include "estructuras.h"
#include "textos.h"
#include "aliados.h"
#include "utilidades.h"

using namespace std;

extern int nAliados;

bool leerPartida(Jugador *jugador, Personaje aliados[], int numAliados, string n)
{
    ifstream ifs(R_PARTIDAS + n + ".csv");
    if (ifs.fail())
    {
        ifs.close();
        return false;
    }
    char dato[100];
    ifs.getline(dato, 100, ';');
    jugador->pos.fila = atoi(dato);
    ifs.getline(dato, 100, ';');
    jugador->pos.columna = atoi(dato);
    ifs.getline(dato, 100, '\n');
    jugador->turnos = atoi(dato);
    for (int i = 0; i < numAliados; i++)
    {
        ifs.getline(dato, 100, ';');
        aliados[i].nombre = dato;
        ifs.getline(dato, 100, ';');
        aliados[i].nivel = atoi(dato);
        ifs.getline(dato, 100, ';');
        aliados[i].salud = atoi(dato);
        ifs.getline(dato, 100, ';');
        aliados[i].saludTotal = atoi(dato);
        ifs.getline(dato, 100, ';');
        aliados[i].velocidad = atoi(dato);
        ifs.getline(dato, 100, ';');
        aliados[i].ataqueF = atoi(dato);
        ifs.getline(dato, 100, ';');
        aliados[i].defensaF = atoi(dato);
        ifs.getline(dato, 100, ';');
        aliados[i].ataqueM = atoi(dato);
        ifs.getline(dato, 100, ';');
        aliados[i].defensaM = atoi(dato);
        for (int j = 0; j < 4; j++)
        {
            ifs.getline(dato, 100, ';');
            aliados[i].ataques[j].nombre = dato;
            ifs.getline(dato, 100, ';');
            aliados[i].ataques[j].fuerza = atoi(dato);
            ifs.getline(dato, 100, ';');
            aliados[i].ataques[j].fisico = dato[0] == 't';
            ifs.getline(dato, 100, ';');
            aliados[i].ataques[j].usos = atoi(dato);
            j < 3 ? ifs.getline(dato, 100, ';') : ifs.getline(dato, 100, '\n');
            aliados[i].ataques[j].usosTotales = atoi(dato);
        }
    }

    ifs.close();
    return true;
}

string seleccionarPartida()
{
    int n;
    escribir(T_REEMPL, 7, 5, 10);
    for (int i = 1; i < 6; i++)
    {
        escribir(T_GUARD + to_string(i) + ": " + "\n", 7, 5, 10);
        Jugador j;
        int numAliados = contarLineas(R_PARTIDAS + to_string(i) + ".csv") - 1;
        if (numAliados == -2)
            escribir("Vacío\n", 8, 5, 10);
        else
        {
            Personaje *aliados = NULL;
            if ((aliados = new Personaje[numAliados]) == NULL)
            {
                escribir(T_ERR_MEM, 79);
                exit(1);
            }
            if (leerPartida(&j, aliados, numAliados, to_string(i)))
            {
                escribir("\tTurnos: " + to_string(j.turnos), 7, 5, 10);
                for (int j = 0; j < numAliados; j++)
                    escribir(" | " + aliados[j].nombre + " (" + to_string(aliados[j].nivel) + ")", aliados[j].salud > 0 ? 7 : 4, 5, 10);
                escribir("\n");
            }
            else
                escribir(T_ERR_GUARD_2, 79);
            delete[] aliados;
        }
    }
    do
        n = leerEntero(T_SEL_GUARD);
    while (n < 0 || n > 6);
    return to_string(n);
}

void guardarPartida(Jugador *jugador, Personaje a[])
{
    ofstream ofs(R_PARTIDAS + seleccionarPartida() + ".csv");
    ofs << to_string(jugador->pos.fila) << ";" << to_string(jugador->pos.columna) << ";" << jugador->turnos << endl;
    for (int i = 0; i < nAliados; i++)
    {
        ofs << a[i].nombre << ";" << a[i].nivel << ";" << a[i].salud << ";" << a[i].saludTotal << ";" << a[i].velocidad << ";" << a[i].ataqueF << ";" << a[i].defensaF << ";" << a[i].ataqueM << ";" << a[i].defensaM;
        for (int j = 0; j < 4; j++)
            ofs << ";" << a[i].ataques[j].nombre << ";" << a[i].ataques[j].fuerza << ";" << (a[i].ataques[j].fisico ? 't' : 'f') << ";" << a[i].ataques[j].usos << ";" << a[i].ataques[j].usosTotales;
        ofs << endl;
    }
    ofs.close();
}
