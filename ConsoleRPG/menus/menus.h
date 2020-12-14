#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include "../estructuras.h"

/**
 * Muestra el menú de selección de movimiento y el mapa
**/
int menuMapa(int const turno, Posicion const pos);

/**
 * Muestra el menú principal que permite jugar una nueva partida, cargarla o salir
**/
int menuPrincipal();

#endif // MENUS_H_INCLUDED
