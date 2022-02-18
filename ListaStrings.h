#ifndef LISTASTRINGS_H_INCLUDED
#define LISTASTRINGS_H_INCLUDED

#include "string.h"

typedef struct nodoS {
    string info;
    nodoS *sig;
} NodoString;

typedef NodoString *ListaStrings;

//Crea la lista de strings
void crearListaStrings(ListaStrings &listaStrings);

//Obtiene un elemento de la lista según el índice pasado
void obtenerElementoListaPorIndice(ListaStrings listaStrings, int index, string &stringAux);

//Divide en una lista de strings un string según los espacios
ListaStrings dividirString(string s);

//Contabiliza la cantidad de elementos en lista
int largoLista(ListaStrings listaStrings);

//Inserta nuevo string en la lista de strings pasada
void insbackListaStrings(ListaStrings &listaStrings, string s);

#endif // LISTASTRINGS_H_INCLUDED
