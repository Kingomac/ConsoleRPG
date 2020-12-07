#ifndef ESCRIBIR_H_INCLUDED
#define ESCRIBIR_H_INCLUDED
#include <string>

using namespace std;

void escribir(string mensaje, unsigned char color = 7, int esperarChar = 50, int esperarLinea = 100);
void listaColores();

#endif // ESCRIBIR_H_INCLUDED
