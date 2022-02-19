#ifndef TALLERIPROYECTO_ABBSECUENCIAS_H
#define TALLERIPROYECTO_ABBSECUENCIAS_H

#include "Secuencia.h"

typedef struct nodoA {
    Secuencia info;
    nodoA *hIzq;
    nodoA *hDer;
} NodoSecuencia;

typedef NodoSecuencia *ABBSecuencias;

//Crea un arbol vacio
void crearArbol(ABBSecuencias &abbSecuencias);

//Retorna verdadero si el árbol es vacío
boolean esVacio(ABBSecuencias abbSecuencias);

//Retorna la raíz del árbol, Precondición: árbol no debe estar vacío
Secuencia darRaiz(ABBSecuencias abbSecuencias);

//Retorna el subárbol izquierdo del árbol pasado en el momento, Precondición: El árbol no debe estar vacío
ABBSecuencias hijoIzq(ABBSecuencias abbSecuencias);

//Retorna el subárbol derecho del arbol pasado en el momento, Precondición: El árbol no debe estar vacío
ABBSecuencias hijoDer(ABBSecuencias abbSecuencias);

//Inserta una nueva secuencia en el árbol, Precondición: La secuencia no debe existir en el árbol
void insertarSecuencia(ABBSecuencias &abbSecuencias, Secuencia secuencia);

//Busca y verifica si la secuencia existe en el árbol, Precondición: El árbol no debe estar vacío
boolean existeSecuencia(ABBSecuencias abbSecuencias, string identificador);

//Lista todas las secuencias del árbol desplegando por pantalla en diferentes renglones
void listarSecuencias(ABBSecuencias abbSecuencias);

// Retorna la secuencia según el identificador pasado por parámetro, Precondición: Secuencia debe existir
Secuencia buscarSecuenciaPorIdentificador(ABBSecuencias abbSecuencias, string identificador);

//Recorre el árbol destruyendo las hojas en memoria y se destruye el árbol en sí
void destruirArbol(ABBSecuencias &abbSecuencias);

#endif //TALLERIPROYECTO_ABBSECUENCIAS_H
