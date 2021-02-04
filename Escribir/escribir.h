#define Escribir_VERSION_MAJOR @Escribir_VERSION_MAJOR@
#define Escribir_VERSION_MINOR @Escribir_VERSION_MINOR@
#ifndef ESCRIBIR_H_INCLUDED
#define ESCRIBIR_H_INCLUDED
#include <string>

using namespace std;

/**
 * Imprime por consola un mensaje dando la opción de elegir el color, tiempo de espera entre carácter y linea.
**/
void escribir(string mensaje, unsigned char color = 7, int esperarChar = 25, int esperarLinea = 50);

/**
 * Imprime por consola un texto de un archivo
**/
void escribirArchivo(string archivo, unsigned char color = 7, int esperarChar = 25, int esperarLinea = 50);

/**
 * Imprime por pantalla una lista con los colores numerados según se utilizan en el procedimiento escribir()
 * Se usa únicamente durante el desarrollo
*/
void listaColores();

#endif // ESCRIBIR_H_INCLUDED
