#ifndef TEXTOS_H_INCLUDED
#define TEXTOS_H_INCLUDED
#include <string>

using namespace std;

/**
 * Se definen textos constantes que pueden tener múltiples usos para que sea
 * más fácil cambiarlos
**/

// Mensajes de eror
const string T_ERR_MEM = "Error de asignación de memoria\n";

// Mensajes sobre los aliados
const string T_ALI_RECUP = " Después de un breve descanso, los héroes han recuperado sus fuerzas. Es hora de reanudar el viaje.\n";
const string T_VENCER_REY = " Tenemos que derrotar al Rey Demonio\n";
const string T_OBST_M = " ¡Escalando las montañas tardaríamos más tiempo! Sigue el camino indicado por el rey\n";
const string T_OBST_A = " Hiadeki: Soy otaku, jamás me meteré en el agua, podría perder mi esencia\n";

// Mensajes en combate
const string T_EN_APARECE = "\n Han aparecido:\n";
const string T_EN_MUERTO = "MUERTO";
const string T_SEL_EN = " Selecciona el objetivo\n";

// Rutas
const string R_PARTIDAS = "./partidas/";
const string R_T_TITULO = "./textos/titulo.txt";
const string R_T_T_INTRO = "./textos/t_introduccion.txt";
const string R_T_INTRO = "./textos/introduccion.txt";
const string R_T_FIN = "./textos/fin.txt";
const string R_ALI_INI = "./aliados/iniciales.csv";
const string R_EN_1 = "./enemigos/1.csv";
const string R_EN_2 = "./enemigos/2.csv";
const string R_EN_3 = "./enemigos/3.csv";
const string R_EN_4 = "./enemigos/4.csv";

// Mensajes sobre partidas
const string T_REEMPL = " Partidas guardadas (al guardar sobre una partida existente esta se reemplaza):\n";
const string T_GUARD = " Espacio de guardado ";
const string T_SEL_GUARD = "Usar espacio de guardado: ";
const string T_SEL_VAC = "Para cargar una partida primero debes guardarla\n";

#endif // TEXTOS_H_INCLUDED
