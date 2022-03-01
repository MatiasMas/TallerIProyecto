#include "ListaStrings.h"

void crearListaStrings(ListaStrings &listaStrings) {
    listaStrings = NULL;
}

void obtenerElementoListaPorIndice(ListaStrings listaStrings, int index, string &stringAux) {
    int indexAux = 0;

    if(index < largoLista(listaStrings)){
        while (indexAux < index) {
            listaStrings = listaStrings->sig;
            indexAux++;
        }

        stringAux = listaStrings->info;
    } else {
        printf("El indice esta fuera de rango.");
    }
}

ListaStrings dividirString(string s) {
    boolean leyendoPalabra = FALSE;
    int i = 0, j = 0;
    string palabraAux;
    ListaStrings listaAux;

    crearString(palabraAux);
    crearListaStrings(listaAux);

    while (s[i] != '\0') {
        if (s[i] == ' ') {
            if (leyendoPalabra) {
                palabraAux[j] = '\0';
                insbackListaStrings(listaAux, palabraAux);
                crearString(palabraAux);
                leyendoPalabra = FALSE;
                i++;
                j = 0;
            } else {
                i++;
            }
        } else {
            palabraAux[j] = s[i];
            i++;
            j++;
            if (!leyendoPalabra) {
                leyendoPalabra = TRUE;
            }
        }
    }

    palabraAux[j] = '\0';
    insbackListaStrings(listaAux, palabraAux);

    return listaAux;
}

int largoLista(ListaStrings listaStrings) {
    int contador = 0;

    while (listaStrings != NULL) {
        contador++;
        listaStrings = listaStrings->sig;
    }

    return contador;
}

void insbackListaStrings(ListaStrings &listaStrings, string s) {
    ListaStrings nuevo = new NodoString;
    nuevo->info = s;
    nuevo->sig = NULL;

    if (listaStrings == NULL) {
        listaStrings = nuevo;
    } else {
        ListaStrings aux = listaStrings;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }

        aux->sig = nuevo;
    }
}

void destruirListaStrings(ListaStrings &listaStrings) {
    ListaStrings nodoActual = listaStrings ;
    ListaStrings siguiente = NULL;

    while (nodoActual != NULL) {
        siguiente = nodoActual->sig;
        delete nodoActual;
        nodoActual = siguiente;
    }

    listaStrings = NULL;
}
