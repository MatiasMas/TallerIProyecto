#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include "boolean.h"

const int MAX=80;
typedef char * string;

//Crea un string vacio
void crearString(string &s);

//Libera la memoria usada por el string
void destruirString(string &s);

//Carga el string desde teclado
void cargarString(string &s);

//Imprime el string pasado
void printString(string s);

//Copia el valor del string 2 en el string 1
void copiarString(string &s1, string s2);

//Retorna longitud del string
int stringLargo(string s);

//Valida que la extensión del nombre de archivo pasado sea .txt
boolean extensionArchivoValido(string nombreArchivo);

//Valida que el nombre de archivo pasado sea alfabético
boolean nombreArchivoValido(string nombreArchivo);

//Valida que el string pasado sea alfabético
boolean esAlfabetico(string s);

//Escribe en el archivo los caracteres del string s (incluido '\0'), Precondición: El archivo debe venir abierto para escritura
void bajarString(string s, FILE *f);

//Lee desde el archivo los caracteres del string s, Precondición: El archivo debe venir abierto para lectura
void levantarString(string &s, FILE *f);

//Determina si ambos strings son iguales en contenido
boolean stringIguales(string s1, string s2);

//Carga un string con los caracteres .txt
void cargarStringExtensionArchivo(string &s);

#endif // STRING_H_INCLUDED
