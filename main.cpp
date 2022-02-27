#include "ControlErrores.h"

int main() {
    ListaStrings listaStrings;
    ABBSecuencias abbSecuencias;
    ListaEnteros listaEnteros;
    string stringAux1, stringAux2;
    Secuencia secuenciaAux;
    Comando comando;
    boolean valido = FALSE;

    crearListaStrings(listaStrings);
    crearArbol(abbSecuencias);
    crearListaEnteros(secuenciaAux.listaEnteros);
    crearString(stringAux1);

    do {
        stringAux1 = NULL;
        stringAux2 = NULL;
        secuenciaAux.identificador = NULL;
        secuenciaAux.listaEnteros = NULL;

        printf("Ingrese un comando con sus respectivos parametros en caso de necesitarlos.\n");
        fflush(stdin);
        cargarString(stringAux1);

        listaStrings = dividirString(stringAux1);

        if (listaStrings == NULL) {
            printf("\nNo se han ingresado comandos validos.\n");
        } else {
            obtenerElementoListaPorIndice(listaStrings, 0, stringAux1);
            if (stringIguales(stringAux1, "create")) {
                comando = CREATE;
                if (validarComando(comando, listaStrings, abbSecuencias)) {
                    obtenerElementoListaPorIndice(listaStrings, 1, stringAux1);
                    crearSecuencia(secuenciaAux, stringAux1, secuenciaAux.listaEnteros);
                    insertarSecuencia(abbSecuencias, secuenciaAux);
                    printf("\nEsta es la secuencia ingresada:\n");
                    mostrarSecuencia(secuenciaAux);
                    printf("\nEste es el arbol: \n");
                    listarSecuencias(abbSecuencias);

                    stringAux1 = NULL;
                }

            } else {
                if (stringIguales(stringAux1, "insback")) {

                    comando = INSBACK;
                    if (validarComando(comando, listaStrings, abbSecuencias)) {
                        obtenerElementoListaPorIndice(listaStrings, 1, stringAux1);
                        obtenerElementoListaPorIndice(listaStrings, 2, stringAux2);

                        Secuencia *secuenciaPuntero = buscarSecuenciaPorIdentificador(abbSecuencias, stringAux1);
                        insbackListaEnteros(secuenciaPuntero->listaEnteros, (int)stringAux2);
                        mostrarSecuencia(*secuenciaPuntero);
                    }
                }
            }


        }
    } while (comando != EXIT);
}
