#include <iostream>
#include "estructuras.h"
#include "constantes.h"
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string>
#include "utilidades.h"
#include "escribir.h"
#include <fstream>

using namespace std;

char menuPrincipal();
char partida(Jugador &jugador, Personaje personajes[4]);
void cargarPersonajes(Personaje p[], int lineas, string archivo);
void liberarMemEnemigos();
string seleccionarPartida();
bool leerPartida(Jugador *jugador, Personaje aliados[3], string n);

Personaje *personajes = NULL;
int nAliados = 3;

const string RAIZ = "./"; //CAMIBIAR EN LA VERSIÓN DEFINITIVA POR UNA RUTA RELATIVA

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    srand(time(NULL));
    listaColores();
    escribir("\n\n");
    escribirArchivo("./textos/titulo.txt", 15, 0, 100);
    string archivo = "./textos/titulo.txt";
    ifstream ifs(archivo);
    if (ifs.fail())
    {
        cout << "Error leyendo el archivo " << archivo << endl;
        exit(1);
    }
    string a;
    while (!ifs.eof())
    {
        getline(ifs, a);
        escribir(a, 15, 0, 100);
    }
    ifs.close();
    escribir("\n\n", 7, 0, 0);
    char opcion = menuPrincipal();
    if (opcion == 'N')
    {
        // Se define un nuevo jugador y se inicia la partida
        Jugador jugador =
            {
                {F_INICIAL,
                 C_INICIAL},
                0};

        nAliados = contarLineas(RAIZ + "aliados/iniciales.csv");
        if ((personajes = new Personaje[nAliados]) == NULL)
        {
            cout << "Error de asignación de memoria" << endl;
            exit(1);
        }
        cargarPersonajes(personajes, nAliados, "./aliados/iniciales.csv");
        escribirArchivo("./textos/introduccion.txt");
        opcion = partida(jugador, personajes);

        delete personajes;
    }
    if (opcion == 'C')
    {
        Jugador jugador;
        Personaje aliados[3];
        string o = seleccionarPartida();
        if (leerPartida(&jugador, aliados, o))
        {
            for (int i = 0; i < 3; i++)
            {
                cout << aliados[i].nombre << " " << aliados[i].salud << "/" << aliados[i].saludTotal << endl;
            }
            partida(jugador, aliados);
        }
        else
            escribir("Para cargar una partida primero debes guardarla");
    }
    liberarMemEnemigos();
    return 0;
}
