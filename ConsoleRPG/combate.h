#ifndef COMBATE_H_INCLUDED
#define COMBATE_H_INCLUDED
#include "estructuras.h"

int dano(Ataque ataque, Personaje atacante, Personaje objetivo);
int nVivos(int n, Personaje p[]);
int personajeAleatorioVivo(Personaje aliados[]);
void combate(Personaje aliados[], int camino);

#endif // COMBATE_H_INCLUDED
