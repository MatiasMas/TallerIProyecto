#ifndef TALLERIPROYECTO_SECUENCIA_H
#define TALLERIPROYECTO_SECUENCIA_H

#include "ListaEnteros.h"
#include "string.h"

typedef struct {
    ListaEnteros listaEnteros;
    string identificador;
} Secuencia;

//Retorna verdadero si existe archivo en el sistema
boolean existeArchivo (string nombreArchivo);

//Crea la secuencia en vacío
void crearSecuencia(Secuencia &secuencia, string identificador);

//Muestra nombre de secuencia seguido de todos los elementos de su lista de enteros
void mostrarSecuencia(Secuencia secuencia);

//Guarda el valor de secuencia en el archivo cuyo nombre es el parámetro pasado
void bajarSecuencia(Secuencia secuencia, string nombreArchivo);

//Lee desde archivo y guarda en secuencia
void levantarSecuencia(Secuencia &secuencia, string nombreArchivo);

//Selectora de la lista de enteros de la Secuencia
ListaEnteros getListaEnteros(Secuencia secuencia);

//Selectora del identificador de la secuencia
void getIdentificador(Secuencia secuencia, string &identificador);

//Destruye la secuencia
void destruirSecuencia(Secuencia &secuencia);

#endif //TALLERIPROYECTO_SECUENCIA_H
