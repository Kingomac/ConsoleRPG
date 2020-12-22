#ifndef PERSONAJES_H_INCLUDED
#define PERSONAJES_H_INCLUDED
#include <string>
using namespace std;

/**
 * Información de un ataque
**/
struct Ataque
{
    string nombre;
    int fuerza;
    bool fisico; // Físico true || Mágico false
    int usosTotales, usos;
};

/**
 * Información de un personaje
 * Se usa para enemigos y aliados
*/
struct Personaje
{
    string nombre;
    int nivel;
    int salud;
    int saludTotal;
    Ataque ataques[4];
    int velocidad;
    int ataqueF = 0, defensaF = 0, ataqueM = 0, defensaM = 0;
};

/**
 * Devuelve la cantidad de personajes vivos
**/
int nVivos(int n, Personaje p[]);

/**
 * Devuelve un personaje aleatorio vivo o uno aleatorio
 * Se usa para decidir a que aliado ataca cada enemigo
**/
int personajeAleatorioVivo(int n, Personaje p[]);

/**
 * Restablece la salud y usos disponibles de cada ataque de personajes
**/
void restablecerSalud(int n, Personaje aliados[]);

/**
 * Imprime todas las estadísticas de los personajes
**/
void mostrarEstadisticas(int n, Personaje aliados[]);

/**
 * Carga personajes iniciales de un archivo CSV
 * Estos continen únicamente la información necesaria para crear un personaje de 0
**/
void cargarPersonajes(Personaje p[], int lineas, string archivo);


#endif // PERSONAJES_H_INCLUDED
