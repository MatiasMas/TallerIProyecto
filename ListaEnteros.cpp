#include "ListaEnteros.h"

void crearListaEnteros(ListaEnteros &listaEnteros) {
    listaEnteros = NULL;
}

boolean esListaEnterosVacia(ListaEnteros listaEnteros) {
    boolean vacia = FALSE;

    if (listaEnteros == NULL) {
        vacia = TRUE;
    }

    return vacia;
}

void insbackListaEnteros(ListaEnteros &listaEnteros, int num) {
    ListaEnteros nuevo = new NodoEntero;
    nuevo->info = num;
    nuevo->sig = NULL;

    if (listaEnteros == NULL) {
        listaEnteros = nuevo;
    } else {
        ListaEnteros aux = listaEnteros;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }

        aux->sig = nuevo;
    }
}

void bajarListaEnteros(ListaEnteros listaEnteros, FILE *f) {
    while (listaEnteros != NULL) {
        fwrite(&listaEnteros->info, sizeof(int), 1, f);
        listaEnteros = listaEnteros->sig;
    }
}

void levantarListaEnteros(ListaEnteros &listaEnteros, FILE *f) {
    int buffer;

    crearListaEnteros(listaEnteros);
    fread(&buffer, sizeof(int), 1, f);
    while (!feof(f)) {
        insbackListaEnteros(listaEnteros, buffer);
        fread(&buffer, sizeof(int), 1, f);
    }
}

void invertirLista(ListaEnteros listaEnteros, ListaEnteros &nuevaLista) {
    int index = largoListaEnteros(listaEnteros) - 1;
    int indexAux = 0;
    ListaEnteros listaAux = listaEnteros;

    while (index != 0) {
        while (indexAux != index) {
            listaAux = listaAux->sig;
            indexAux++;
        }

        insbackListaEnteros(nuevaLista, listaAux->info);
        listaAux = listaEnteros;
        indexAux = 0;
        index--;
    }

    insbackListaEnteros(nuevaLista, listaAux->info);
}

int largoListaEnteros(ListaEnteros listaEnteros) {
    int contador = 0;

    while (listaEnteros != NULL) {
        contador++;
        listaEnteros = listaEnteros->sig;
    }

    return contador;
}

int sumarListaEnteros(ListaEnteros listaEnteros) {
    int total = 0;

    while (listaEnteros != NULL) {
        total = total + listaEnteros->info;
        listaEnteros = listaEnteros->sig;
    }

    return total;
}

void concatenarSecuencia(ListaEnteros listaA, ListaEnteros listaB, ListaEnteros &listaConcatenada) {
    crearListaEnteros(listaConcatenada);

    while (listaA != NULL) {
        insbackListaEnteros(listaConcatenada, listaA->info);
        listaA = listaA->sig;
    }

    while (listaB != NULL) {
        insbackListaEnteros(listaConcatenada, listaB->info);
        listaB = listaB->sig;
    }
}

void listarEnteros(ListaEnteros listaEnteros) {
    printf("[");

    while (listaEnteros != NULL) {
        printf("%i", listaEnteros->info);
        if (listaEnteros->sig != NULL) {
            printf(" ");
        }
        listaEnteros = listaEnteros->sig;
    }

    printf("]\n");
}

void destruirListaEnteros(ListaEnteros &listaEnteros) {
    ListaEnteros nodoActual = listaEnteros;
    ListaEnteros siguiente = NULL;

    while (nodoActual != NULL) {
        siguiente = nodoActual->sig;
        delete nodoActual;
        nodoActual = siguiente;
    }

    listaEnteros = NULL;
}


