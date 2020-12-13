#include <fstream>
#include "escribir.h"
#include "estructuras.h"
#include "textos.h"
#include "aliados.h"
#include "utilidades.h"

using namespace std;

extern int nAliados;

bool leerPartida(Jugador *jugador, Personaje aliados[], string n)
{
    ifstream ifs(R_PARTIDAS + n + ".csv");
    if (ifs.fail())
        return false;
    else
    {
        char dato[100];
        ifs.getline(dato, 100, ';');
        jugador->pos.fila = atoi(dato);
        ifs.getline(dato, 100, ';');
        jugador->pos.columna = atoi(dato);
        ifs.getline(dato, 100, '\n');
        jugador->turnos = atoi(dato);
        for (int i = 0; i < nAliados; i++)
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
        return true;
    }
    ifs.close();
}

string seleccionarPartida()
{
    int n;
    escribir(T_REEMPL);
    for (int i = 1; i < 6; i++)
    {
        escribir(T_GUARD + to_string(i) + ": " + "\n");
        Jugador j;
        Personaje *aliados = NULL;
        if ((aliados = new Personaje[nAliados]) == NULL)
        {
            escribir(T_ERR_MEM, 79);
            exit(1);
        }
        if (leerPartida(&j, aliados, to_string(i)))
        {
            escribir("\tTurnos: " + to_string(j.turnos));
            for (int j = 0; j < nAliados; j++)
                if (aliados[j].salud > 0)
                    escribir(" | " + aliados[j].nombre + " (" + to_string(aliados[j].nivel) + ")");
        }
        else
            escribir("Vacío\n", 8);
        delete aliados;
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
