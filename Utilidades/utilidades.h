#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED
#include <string>

using namespace std;

/**
 * Lee un entero por teclado
 * Se asegura de que sea de tipo entero y solo uno
**/
int leerEntero(string mensaje);

/**
 * Lee un carácter por teclado
**/
char leerChar(string mensaje);

/**
 * Cuenta las líneas de un archivo
**/
int contarLineas(string archivo);

#endif // UTILIDADES_H_INCLUDED
