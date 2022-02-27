#include "ABBSecuencias.h"

void crearArbol(ABBSecuencias &abbSecuencias) {
    abbSecuencias = NULL;
}

boolean esVacio(ABBSecuencias abbSecuencias) {
    return abbSecuencias == NULL ? TRUE : FALSE;
}

Secuencia darRaiz(ABBSecuencias abbSecuencias) {
    return abbSecuencias->info;
}

ABBSecuencias hijoIzq(ABBSecuencias abbSecuencias) {
    return abbSecuencias->hIzq;
}

ABBSecuencias hijoDer(ABBSecuencias abbSecuencias) {
    return abbSecuencias->hDer;
}

void insertarSecuencia(ABBSecuencias &abbSecuencias, Secuencia secuencia) {
    if (abbSecuencias == NULL) {
        abbSecuencias = new NodoSecuencia;
        abbSecuencias->info = secuencia;
        abbSecuencias->hIzq = NULL;
        abbSecuencias->hDer = NULL;
    } else {
        if (stringMenor(secuencia.identificador, abbSecuencias->info.identificador)) {
            insertarSecuencia(abbSecuencias->hIzq, secuencia);
        } else {
            insertarSecuencia(abbSecuencias->hDer, secuencia);
        }
    }

}

void listarSecuencias(ABBSecuencias abbSecuencias) {
    if (abbSecuencias != NULL) {
        listarSecuencias(abbSecuencias->hIzq);

        mostrarSecuencia(abbSecuencias->info);

        listarSecuencias(abbSecuencias->hDer);
    }
}

boolean existeSecuencia(ABBSecuencias abbSecuencias, string identificador) {
    boolean encontrado = FALSE;

    while (abbSecuencias != NULL && !encontrado) {
        if (stringIguales(abbSecuencias->info.identificador, identificador)) {
            encontrado = TRUE;
        } else {
            if (stringMenor(abbSecuencias->info.identificador, identificador)) {
                abbSecuencias = abbSecuencias->hDer;
            } else {
                abbSecuencias = abbSecuencias->hIzq;
            }
        }
    }

    return encontrado;
}

Secuencia *buscarSecuenciaPorIdentificador(ABBSecuencias abbSecuencias, string identificador) {

    while (abbSecuencias != NULL) {
        if (stringIguales(abbSecuencias->info.identificador, identificador)) {
            return &abbSecuencias->info;
        } else {
            if (stringMenor(abbSecuencias->info.identificador, identificador)) {
                abbSecuencias = abbSecuencias->hDer;
            } else {
                abbSecuencias = abbSecuencias->hIzq;
            }
        }
    }

    return &abbSecuencias->info;
}

void destruirArbol(ABBSecuencias &abbSecuencias) {
    if (abbSecuencias != NULL){
        destruirArbol(abbSecuencias->hIzq);
        destruirArbol(abbSecuencias->hDer);
    }

    destruirSecuencia(abbSecuencias->info);
    delete abbSecuencias;
    abbSecuencias = NULL;
}

