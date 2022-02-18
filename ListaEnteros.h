#ifndef TALLERIPROYECTO_LISTAENTEROS_H
#define TALLERIPROYECTO_LISTAENTEROS_H

#include "boolean.h"

typedef struct nodoE {
    int info;
    nodoE *sig;
} NodoEntero;

typedef NodoEntero *ListaEnteros;

//Crea la lista en memoria
void crearListaEnteros(ListaEnteros &listaEnteros);

//Retorna verdadero si la lista está vacía
boolean esListaEnterosVacia(ListaEnteros listaEnteros);

//Insertar nuevo elemento en la última posición
void insbackListaEnteros(ListaEnteros &listaEnteros, int num);

//Escribe en el archivo los datos de todos los enteros de la lista, Precondición: El archivo debe venir abierto para escritura
void bajarListaEnteros(ListaEnteros listaEnteros, FILE *f);

//Lee desde el archivo los datos de los enteros de la lista, Precondición: El archivo debe venir abierto para lectura
void levantarListaEnteros(ListaEnteros &listaEnteros, FILE *f);

//Invierta los elementos de la lista de enteros en una nueva lista dada por el segundo param
void invertirLista(ListaEnteros listaEnteros, ListaEnteros &nuevaLista);

//Suma los elementos de la lista pasada y guarda el total en el segundo parámetro
int sumarListaEnteros(ListaEnteros listaEnteros);

//Concatena listaA y listaB en listaConcatenada, Precondicion: Todas las listas deben existir
void concatenarSecuencia(ListaEnteros listaA, ListaEnteros listaB, ListaEnteros &listaConcatenada);

//Lista los enteros de la lista entre corchetes []
void listarEnteros(ListaEnteros listaEnteros);

//Destruir lista de enteros
void destruirListaEnteros(ListaEnteros &listaEnteros);

//Retorna el largo de la lista de enteros
int largoListaEnteros(ListaEnteros listaEnteros);

#endif //TALLERIPROYECTO_LISTAENTEROS_H
