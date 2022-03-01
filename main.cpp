#include "ControlErrores.h"

int main() {
    ListaStrings listaStrings;
    ABBSecuencias abbSecuencias;
    string stringAux1, stringAux2;
    Secuencia secuenciaAux;
    Comando comando;
    Secuencia *secuenciaPuntero, *secuenciaPuntero2, *secuenciaPuntero3;
    char opcionArchivo;

    crearListaStrings(listaStrings);
    crearArbol(abbSecuencias);
    crearListaEnteros(secuenciaAux.listaEnteros);
    crearString(stringAux1);

    do {
        stringAux1 = NULL;
        stringAux2 = NULL;
        secuenciaAux.identificador = NULL;
        secuenciaAux.listaEnteros = NULL;
        secuenciaPuntero = NULL;
        secuenciaPuntero2 = NULL;
        secuenciaPuntero3 = NULL;

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
                    mostrarSecuencia(secuenciaAux);
                }

            } else if (stringIguales(stringAux1, "insback")) {

                comando = INSBACK;
                if (validarComando(comando, listaStrings, abbSecuencias)) {
                    obtenerElementoListaPorIndice(listaStrings, 1, stringAux1);
                    obtenerElementoListaPorIndice(listaStrings, 2, stringAux2);
                    secuenciaPuntero = buscarSecuenciaPorIdentificador(abbSecuencias, stringAux1);

                    insbackListaEnteros(secuenciaPuntero->listaEnteros, parseInt(stringAux2));
                    mostrarSecuencia(*secuenciaPuntero);
                }
            } else if (stringIguales(stringAux1, "show")) {
                comando = SHOW;
                if (validarComando(comando, listaStrings, abbSecuencias)) {
                    listarSecuencias(abbSecuencias);
                }
            } else if (stringIguales(stringAux1, "sum")) {
                comando = SUM;
                if (validarComando(comando, listaStrings, abbSecuencias)) {
                    obtenerElementoListaPorIndice(listaStrings, 1, stringAux1);
                    secuenciaPuntero = buscarSecuenciaPorIdentificador(abbSecuencias, stringAux1);

                    int sumaEnteros = sumarListaEnteros(secuenciaPuntero->listaEnteros);
                    printf("\nLa suma de los elementos contenidos dentro de la secuencia es: %i.\n", sumaEnteros);
                }
            } else if (stringIguales(stringAux1, "concat")) {
                comando = CONCAT;
                if (validarComando(comando, listaStrings, abbSecuencias)) {
                    obtenerElementoListaPorIndice(listaStrings, 3, stringAux1);
                    crearSecuencia(secuenciaAux, stringAux1, secuenciaAux.listaEnteros);

                    obtenerElementoListaPorIndice(listaStrings, 1, stringAux2);
                    secuenciaPuntero2 = buscarSecuenciaPorIdentificador(abbSecuencias, stringAux2);
                    obtenerElementoListaPorIndice(listaStrings, 2, stringAux2);
                    secuenciaPuntero3 = buscarSecuenciaPorIdentificador(abbSecuencias, stringAux2);

                    concatenarSecuencia(secuenciaPuntero2->listaEnteros, secuenciaPuntero3->listaEnteros,
                                        secuenciaAux.listaEnteros);
                    insertarSecuencia(abbSecuencias, secuenciaAux);
                    mostrarSecuencia(secuenciaAux);
                }
            } else if (stringIguales(stringAux1, "reverse")) {
                comando = REVERSE;
                if (validarComando(comando, listaStrings, abbSecuencias)) {
                    obtenerElementoListaPorIndice(listaStrings, 2, stringAux1);
                    crearSecuencia(secuenciaAux, stringAux1, secuenciaAux.listaEnteros);

                    obtenerElementoListaPorIndice(listaStrings, 1, stringAux1);
                    secuenciaPuntero = buscarSecuenciaPorIdentificador(abbSecuencias, stringAux1);

                    invertirLista(secuenciaPuntero->listaEnteros, secuenciaAux.listaEnteros);
                    insertarSecuencia(abbSecuencias, secuenciaAux);
                    mostrarSecuencia(secuenciaAux);
                }
            } else if (stringIguales(stringAux1, "save")) {
                comando = SAVE;
                if (validarComando(comando, listaStrings, abbSecuencias)) {
                    obtenerElementoListaPorIndice(listaStrings, 1, stringAux1);
                    secuenciaPuntero = buscarSecuenciaPorIdentificador(abbSecuencias, stringAux1);

                    obtenerElementoListaPorIndice(listaStrings, 2, stringAux2);

                    if (existeArchivo(stringAux2)) {
                        printf("\nEl archivo ya existe, desea sobreescribir? S/N\n");
                        scanf("%c", &opcionArchivo);
                        if (opcionArchivo == 'S') {
                            bajarSecuencia(*secuenciaPuntero, stringAux2);
                            printf("La secuencia fue guardada en archivo.");
                        } else if (opcionArchivo == 'N') {
                            printf("\nLa secuencia no sera guardada, vuelva a intentar si asi lo desea.\n");
                        } else {
                            printf("\nLa opcion seleccionada no es valida.\n");
                        }
                    } else {
                        bajarSecuencia(*secuenciaPuntero, stringAux2);
                        printf("La secuencia fue guardada en archivo.");
                    }
                }
            } else if (stringIguales(stringAux1, "load")) {
                comando = LOAD;
                if (validarComando(comando, listaStrings, abbSecuencias)) {
                    obtenerElementoListaPorIndice(listaStrings, 2, stringAux1);
                    crearSecuencia(secuenciaAux, stringAux1, secuenciaAux.listaEnteros);

                    obtenerElementoListaPorIndice(listaStrings, 1, stringAux2);
                    levantarSecuencia(secuenciaAux, stringAux2);
                    insertarSecuencia(abbSecuencias, secuenciaAux);
                    mostrarSecuencia(secuenciaAux);
                }
            } else if (stringIguales(stringAux1, "exit")) {
                comando = EXIT;
                if (validarComando(comando, listaStrings, abbSecuencias)){
                    destruirArbol(abbSecuencias);
                    destruirListaStrings(listaStrings);
                    destruirString(stringAux1);
                    destruirString(stringAux2);
                    destruirSecuencia(secuenciaAux);
                    destruirSecuencia(*secuenciaPuntero);
                    destruirSecuencia(*secuenciaPuntero2);
                    destruirSecuencia(*secuenciaPuntero3);
                }
            }
        }
    } while (comando != EXIT);
}
