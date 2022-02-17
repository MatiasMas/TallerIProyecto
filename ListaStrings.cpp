#include "ListaStrings.h"

void crearListaStrings(ListaStrings &listaStrings) {
    listaStrings = NULL;
}

void obtenerElementoListaPorIndice(ListaStrings listaStrings, int index, string &stringAux) {
    int indexAux = 0;

    while (indexAux <= index) {
        listaStrings = listaStrings->Sig;
        indexAux++;
    }

    stringAux = listaStrings->info;
}

ListaStrings dividirString(string s) {
    boolean leyendoPalabra = FALSE;
    int i = 0;
    string palabraAux;
    ListaStrings listaAux;

    crearListaStrings(listaAux);
    crearString(palabraAux);

    while (s[i] != '\0'){
        if (s[i] == ' '){
            if (leyendoPalabra){
                insbackListaStrings(listaAux, palabraAux);
                i++;
                palabraAux = NULL;
                leyendoPalabra = FALSE;
            }
        } else {
            palabraAux[i] = s[i];
            i++;
            if (!leyendoPalabra){
                leyendoPalabra = TRUE;
            }
        }
    }

    return listaAux;
}

int largoLista(ListaStrings listaStrings) {
    int contador = 0;

    while (listaStrings != NULL) {
        contador++;
        listaStrings = listaStrings->Sig;
    }

    return contador;
}

void insbackListaStrings(ListaStrings &listaStrings, string s) {
    ListaStrings nuevo = new NodoString;
    nuevo->info = s;
    nuevo->Sig = NULL;

    if (listaStrings == NULL) {
        listaStrings = nuevo;
    } else {
        ListaStrings aux = listaStrings;
        while (aux->Sig != NULL) {
            aux = aux->Sig;
        }

        aux->Sig = nuevo;
    }
}
