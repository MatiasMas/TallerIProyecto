#include "ControlErrores.h"

boolean validarComando(Comando comando, ListaStrings listaStrings, ABBSecuencias abbSecuencias) {
    boolean valido = FALSE;
    string stringAux, stringAux2, stringAux3;
    crearString(stringAux);
    crearString(stringAux2);
    crearString(stringAux3);

    switch (comando) {
        case CREATE:
            if (largoLista(listaStrings) != 2) {
                valido = FALSE;
                printf("\nLa cantidad de parametros es incorrecta.\n");
            } else {
                obtenerElementoListaPorIndice(listaStrings, 1, stringAux);
                if (!esAlfabetico(stringAux)) {
                    valido = FALSE;
                    printf("\nEl identificador debe ser puramente alfabetico.\n");
                } else {
                    if (existeSecuencia(abbSecuencias, stringAux)) {
                        valido = FALSE;
                        printf("\nUna secuencia con ese nombre ya existe.\n");
                    } else {
                        valido = TRUE;
                    }
                }
            }
            break;
        case INSBACK:
            if (largoLista(listaStrings) != 3) {
                valido = FALSE;
                printf("\nLa cantidad de parametros es incorrecta.\n");
            } else {
                obtenerElementoListaPorIndice(listaStrings, 1, stringAux);
                if (!esAlfabetico(stringAux)) {
                    valido = FALSE;
                    printf("\nEl identificador debe ser puramente alfabetico.\n");
                } else {
                    obtenerElementoListaPorIndice(listaStrings, 2, stringAux);
                    if (esAlfabetico(stringAux)) {
                        valido = FALSE;
                        printf("\nEl elemento a ingresar en la secuencia debe ser un numero natural.\n");
                    } else {
                        if (!esNumeroNatural(stringAux)) {
                            valido = FALSE;
                            printf("\nEl elemento a ingresar en la secuencia debe ser un numero natural.\n");
                        } else {
                            obtenerElementoListaPorIndice(listaStrings, 1, stringAux);
                            if (!existeSecuencia(abbSecuencias, stringAux)) {
                                valido = FALSE;
                                printf("\nNo existe una secuencia con el identificador ingresado.\n");
                            } else {
                                valido = TRUE;
                            }
                        }
                    }
                }
            }
            break;
        case SHOW:
            if (largoLista(listaStrings) != 1) {
                valido = FALSE;
                printf("\nLa cantidad de parametros es incorrecta.\n");
            } else {
                if (esVacio(abbSecuencias)) {
                    valido = FALSE;
                    printf("\nNo existen secuencias.\n");
                } else {
                    valido = TRUE;
                }
            }

            break;
        case SUM:
            if (largoLista(listaStrings) != 2) {
                valido = FALSE;
                printf("\nLa cantidad de parametros es incorrecta.\n");
            } else {
                obtenerElementoListaPorIndice(listaStrings, 1, stringAux);
                if (!esAlfabetico(stringAux)) {
                    printf("\nEl identificador debe ser puramente alfabetico.\n");
                } else {
                    if (!existeSecuencia(abbSecuencias, stringAux)) {
                        valido = FALSE;
                        printf("\nNo existe una secuencia con el identificador ingresado.\n");
                    } else {
                        valido = TRUE;
                    }
                }
            }

            break;
        case CONCAT:
            if (largoLista(listaStrings) != 4) {
                valido = FALSE;
                printf("\nLa cantidad de parametros es incorrecta.\n");
            } else {
                obtenerElementoListaPorIndice(listaStrings, 1, stringAux);
                obtenerElementoListaPorIndice(listaStrings, 2, stringAux2);
                obtenerElementoListaPorIndice(listaStrings, 3, stringAux3);
                if (!esAlfabetico(stringAux) || !esAlfabetico(stringAux2) || !esAlfabetico(stringAux3)) {
                    valido = FALSE;
                    printf("\nLos identificadores deben ser puramente alfabeticos.\n");
                } else {
                    if (!existeSecuencia(abbSecuencias, stringAux) || !existeSecuencia(abbSecuencias, stringAux2)) {
                        valido = FALSE;
                        printf("\nAl menos una de las secuencias no existe segun el identificador dado.\n");
                    } else {
                        if (existeSecuencia(abbSecuencias, stringAux3)) {
                            valido = FALSE;
                            printf("\nLa secuencia a concatenar ya existe.\n");
                        } else {
                            valido = TRUE;
                        }
                    }
                }
            }
            break;
        case REVERSE:
            if (largoLista(listaStrings) != 3) {
                valido = FALSE;
                printf("\nLa cantidad de parametros es incorrecta.\n");
            } else {
                obtenerElementoListaPorIndice(listaStrings, 1, stringAux);
                obtenerElementoListaPorIndice(listaStrings, 2, stringAux2);
                if (!esAlfabetico(stringAux) || !esAlfabetico(stringAux2)) {
                    valido = FALSE;
                    printf("\nLos identificadores deben ser puramente alfabeticos.\n");
                } else {
                    if (!existeSecuencia(abbSecuencias, stringAux)) {
                        valido = FALSE;
                        printf("\nNo existe una secuencia con el identificador ingresado.\n");
                    } else {
                        if (existeSecuencia(abbSecuencias, stringAux2)) {
                            valido = FALSE;
                            printf("\nUna secuencia con ese nombre ya existe.\n");
                        } else {
                            Secuencia *secuenciaAux = buscarSecuenciaPorIdentificador(abbSecuencias, stringAux);
                            if (esListaEnterosVacia(secuenciaAux->listaEnteros)) {
                                valido = FALSE;
                                printf("\nLa secuencia a revertir no posee elementos dentro.\n");
                            } else {
                                valido = TRUE;
                            }
                        }
                    }
                }
            }

            break;
        case SAVE:
            if (largoLista(listaStrings) != 3) {
                valido = FALSE;
                printf("\nLa cantidad de parametros es incorrecta.\n");
            } else {
                obtenerElementoListaPorIndice(listaStrings, 1, stringAux);
                obtenerElementoListaPorIndice(listaStrings, 2, stringAux2);
                if (!esAlfabetico(stringAux) || !nombreArchivoValido(stringAux2)) {
                    valido = FALSE;
                    printf("\nLos identificadores deben ser puramente alfabeticos.\n");
                } else {
                    if (!existeSecuencia(abbSecuencias, stringAux)) {
                        valido = FALSE;
                        printf("\nNo existe una secuencia con el identificador ingresado.\n");
                    } else {
                        if (!extensionArchivoValido(stringAux2)) {
                            valido = FALSE;
                            printf("\nLa extension del archivo es invalida.\n");
                        } else {
                            valido = TRUE;
                        }
                    }
                }
            }

            break;
        case LOAD:
            if (largoLista(listaStrings) != 3) {
                valido = FALSE;
                printf("\nLa cantidad de parametros es incorrecta.\n");
            } else {
                obtenerElementoListaPorIndice(listaStrings, 1, stringAux);
                obtenerElementoListaPorIndice(listaStrings, 2, stringAux2);
                if (!esAlfabetico(stringAux2) || !nombreArchivoValido(stringAux)) {
                    valido = FALSE;
                    printf("\nLos identificadores deben ser puramente alfabeticos.\n");
                } else {
                    if (existeSecuencia(abbSecuencias, stringAux2)) {
                        valido = FALSE;
                        printf("\nUna secuencia con ese nombre ya existe.\n");
                    } else {
                        if (!extensionArchivoValido(stringAux)) {
                            valido = FALSE;
                            printf("\nLa extension del archivo es invalida.\n");
                        } else {
                            if (!existeArchivo(stringAux)) {
                                valido = FALSE;
                                printf("\nEl archivo con ese nombre no existe.\n");
                            } else {
                                valido = TRUE;
                            }
                        }
                    }
                }
            }

            break;
        case EXIT:
            if (largoLista(listaStrings) != 1) {
                valido = FALSE;
                printf("\nLa cantidad de parametros es incorrecta.\n");
            } else {
                valido = TRUE;
            }

            break;
    }

    return valido;
}
