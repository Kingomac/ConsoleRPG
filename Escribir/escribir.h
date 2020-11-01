#ifndef ESCRIBIR_H_INCLUDED
#define ESCRIBIR_H_INCLUDED
#include <string>

using namespace std;

void esperar();
void escribir(string mensaje);
void listaColores();
enum colores {
    azulMate = 1,
    verdeMate,
    azulClaroMate,
    rojoMate,
    purpuraMate,
    amarilloOscuro,
    blancoMate,
    gris,
    azul,
    verde,
    cyan,
    salmon,
    purpura,
    amarilloClaro,
    blanco,
    AO_grisOscuro,
    AO_azulOscuro,
    AO_turquesaOscuro,
    AO_azulClaro,
    AO_rojo,
    AO_marron,
    AO_amarilloOscuro,
    AO_blancoMate,
    AO_gris,
    AO_azul,
    AO_turquesa,
    AO_azulBrillante,
    AO_salmon,
    AO_purpura,
    AO_amarilloClaro,
    AO_blanco,
    V_negro,
    V_azulOscuro
};
#endif // ESCRIBIR_H_INCLUDED
