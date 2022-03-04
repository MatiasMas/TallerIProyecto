#include "Secuencia.h"

boolean existeArchivo(string nombreArchivo) {
    boolean existeArchivo = TRUE;

    FILE *f = fopen(nombreArchivo, "rb");
    if (f == NULL) {
        existeArchivo = FALSE;
    } else {
        fclose(f);
    }

    return existeArchivo;
}

void crearSecuencia(Secuencia &secuencia, string identificador, ListaEnteros listaEnteros) {
    crearListaEnteros(secuencia.listaEnteros);
    crearString(secuencia.identificador);
    secuencia.identificador = identificador;
    secuencia.listaEnteros = listaEnteros;
}


void mostrarSecuencia(Secuencia secuencia) {
    printString(secuencia.identificador);
    printf("= ");
    listarEnteros(secuencia.listaEnteros);
}

void bajarSecuencia(Secuencia secuencia, string nombreArchivo) {
    FILE *f = fopen(nombreArchivo, "wb");

    bajarListaEnteros(secuencia.listaEnteros, f);

    fclose(f);
}

void levantarSecuencia(Secuencia &secuencia, string nombreArchivo) {
    FILE *f = fopen(nombreArchivo, "rb");

    levantarListaEnteros(secuencia.listaEnteros, f);

    fclose(f);
}

ListaEnteros getListaEnteros(Secuencia secuencia) {
    return secuencia.listaEnteros;
}

void getIdentificador(Secuencia secuencia, string &identificador) {
    identificador = secuencia.identificador;
}

void destruirSecuencia(Secuencia &secuencia) {
    destruirString(secuencia.identificador);
    destruirListaEnteros(secuencia.listaEnteros);
}
