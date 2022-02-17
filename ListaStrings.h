#ifndef LISTASTRINGS_H_INCLUDED
#define LISTASTRINGS_H_INCLUDED

#include "string.h"

typedef struct nodoS {
    string info;
    nodoS *Sig;
} NodoString;

typedef NodoString *ListaStrings;

//Crea la lista de strings
void crearListaStrings(ListaStrings &listaStrings);

//Obtiene un elemento de la lista seg�n el �ndice pasado
void obtenerElementoListaPorIndice(ListaStrings listaStrings, int index, string &stringAux);

//Divide en una lista de strings un string seg�n los espacios
ListaStrings dividirString(string s, ListaStrings &listaStrings);

//Contabiliza la cantidad de elementos en lista
int largoLista(ListaStrings listaStrings);

//Inserta nuevo string en la lista de strings pasada
void insbackListaStrings(ListaStrings &listaStrings, string s);

#endif // LISTASTRINGS_H_INCLUDED