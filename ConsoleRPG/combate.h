#ifndef COMBATE_H_INCLUDED
#define COMBATE_H_INCLUDED
#include "personajes.h"

/**
 * Calcula el daño que se realiza en un turno de combate
 * Se usa tanto para aplicar los daños totales como para que los enemigos determinen qué ataque es más eficaz
**/
int dano(Ataque ataque, Personaje atacante, Personaje objetivo);

/**
 * Muestra los mensajes y menús para hacer el combate
**/
void combate(Personaje aliados[], int camino);

#endif // COMBATE_H_INCLUDED
