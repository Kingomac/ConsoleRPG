#ifndef COMBATE_H_INCLUDED
#define COMBATE_H_INCLUDED
#include "estructuras.h"

/**
 * Calcula el da�o que se realiza en un turno de combate
 * Se usa tanto para aplicar los da�os totales como para que los enemigos determinen qu� ataque es m�s eficaz
**/
int dano(Ataque ataque, Personaje atacante, Personaje objetivo);

/**
 * Devuelve la cantidad de personajes vivos
**/
int nVivos(int n, Personaje p[]);

/**
 * Devuelve un personaje aleatorio vivo o uno aleatorio
 * Se usa para decidir a que aliado ataca cada enemigo
**/
int personajeAleatorioVivo(Personaje aliados[]);

/**
 * Muestra los mensajes y men�s para hacer el combate
**/
void combate(Personaje aliados[], int camino);

#endif // COMBATE_H_INCLUDED
