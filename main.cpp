#include "string.h"
#include "ListaStrings.h"
#include "ListaEnteros.h"

int main() {
//    Comienzo bloque de pruebas para extensionArchivoValido()

//    string nombreArchivo;
//    crearString(nombreArchivo);
//    cargarString(nombreArchivo);
//
//    printString(nombreArchivo);
//
//    if(extensionArchivoValido(nombreArchivo)){
//        printf("\nExtension archivo valido.");
//    } else {
//        printf("\nExtension archivo invalido.");
//    }

//    Fin bloque de pruebas para extensionArchivoValido()

//    Comienzo bloque de pruebas para nombreArchivoValido()

//    string nombreArchivo;
//    crearString(nombreArchivo);
//    cargarString(nombreArchivo);
//
//    printString(nombreArchivo);
//
//    if(nombreArchivoValido(nombreArchivo)){
//        printf("\nNombre archivo valido.");
//    } else {
//        printf("\nNombre archivo invalido.");
//    }

//    Fin bloque de pruebas para nombreArchivoValido()

//    Comienzo bloque de pruebas para esAlfabetico()

//    string nombreArchivo;
//    crearString(nombreArchivo);
//    cargarString(nombreArchivo);
//
//    printString(nombreArchivo);
//
//    if(esAlfabetico(nombreArchivo)){
//        printf("\nEs alfabetico.");
//    } else {
//        printf("\nNo es alfabetico.");
//    }

//    Fin bloque de pruebas para esAlfabetico()

//    Comienzo bloque de pruebas para insbackListaStrings()

//    string string1;
//    string string2;
//    string string3;
//    ListaStrings listaStrings;
//    crearString(string1);
//    crearString(string2);
//    crearString(string3);
//    cargarString(string1);
//    cargarString(string2);
//    cargarString(string3);
//    crearListaStrings(listaStrings);
//
//    insbackListaStrings(listaStrings, string1);
//    insbackListaStrings(listaStrings, string2);
//    insbackListaStrings(listaStrings, string3);
//
//    while (listaStrings != NULL){
//        printString(listaStrings->info);
//        listaStrings = listaStrings->Sig;
//    }

//    Fin bloque de pruebas para insbackListaStrings()

//    Comienzo bloque de pruebas para largoLista()

//    string string1;
//    string string2;
//    string string3;
//    ListaStrings listaStrings;
//    crearString(string1);
//    crearString(string2);
//    crearString(string3);
//    cargarString(string1);
//    cargarString(string2);
//    cargarString(string3);
//    crearListaStrings(listaStrings);
//
//    insbackListaStrings(listaStrings, string1);
//    insbackListaStrings(listaStrings, string2);
//    insbackListaStrings(listaStrings, string3);
//
//    int elementosDeListaStrings = largoLista(listaStrings);
//    printf("\nLa cantidad de elementos en listaStrings es: %i", elementosDeListaStrings);

//    Fin bloque de pruebas para largoLista()

//    Comienzo bloque de pruebas para dividirString()

//    string comandoIngresado;
//    ListaStrings listaStrings;
//    crearString(comandoIngresado);
//    cargarString(comandoIngresado);
//    crearListaStrings(listaStrings);
//
//    listaStrings = dividirString(comandoIngresado);
//
//    while (listaStrings != NULL){
//        printString(listaStrings->info);
//        listaStrings = listaStrings->Sig;
//    }

//    Fin bloque de pruebas para dividirString()

//    Comienzo bloque de pruebas para obtenerElementoListaPorIndice()

//    string comandoIngresado;
//    string stringAux;
//    ListaStrings listaStrings;
//
//    crearString(comandoIngresado);
//    crearString(stringAux);
//    cargarString(comandoIngresado);
//    crearListaStrings(listaStrings);
//
//    listaStrings = dividirString(comandoIngresado);
//
//    obtenerElementoListaPorIndice(listaStrings, 5, stringAux);
//
//    printString(stringAux);

//    Fin bloque de pruebas para obtenerElementoListaPorIndice()

//    Comienzo bloque de pruebas para crearListaEnteros(), esListaEnterosVacia(), insbackListaEnteros()

//    ListaEnteros listaA;
//
//    crearListaEnteros(listaA);
//
//    if (esListaEnterosVacia(listaA)){
//        printf("Lista de enteros vacia\n");
//    } else {
//        printf("La lista no esta vacia\n");
//    }
//
//    insbackListaEnteros(listaA, 5);
//    insbackListaEnteros(listaA, 1);
//    insbackListaEnteros(listaA, 3);
//    insbackListaEnteros(listaA, 50);
//    insbackListaEnteros(listaA, 120);
//
//    if (esListaEnterosVacia(listaA)){
//        printf("Lista de enteros vacia");
//    } else {
//        printf("La lista no esta vacia");
//    }
//
//    listarEnteros(listaA);

//    Fin bloque de pruebas para crearListaEnteros(), esListaEnterosVacia(), insbackListaEnteros()

//    Comienzo bloque de pruebas para invertirLista()

//    ListaEnteros listaA, listaInvertida;
//
//    crearListaEnteros(listaA);
//    crearListaEnteros(listaInvertida);
//
//    insbackListaEnteros(listaA, 5);
//    insbackListaEnteros(listaA, 1);
//    insbackListaEnteros(listaA, 3);
//    insbackListaEnteros(listaA, 50);
//    insbackListaEnteros(listaA, 120);
//
//    invertirLista(listaA, listaInvertida);
//
//    listarEnteros(listaInvertida);

//    Fin bloque de pruebas para invertirLista()

//    Comienzo bloque de pruebas para suamarLista()

//    ListaEnteros listaA;
//
//    crearListaEnteros(listaA);
//
//    insbackListaEnteros(listaA, 5);
//    insbackListaEnteros(listaA, 1);
//    insbackListaEnteros(listaA, 3);
//    insbackListaEnteros(listaA, 50);
//    insbackListaEnteros(listaA, 120);
//
//    int total = sumarListaEnteros(listaA);
//
//    printf("El total es: %i \n", total);

//    Fin bloque de pruebas para sumarLista()

//    Comienzo bloque de pruebas para invertirLista()

//    ListaEnteros listaA, listaB, listaConcatenada;
//
//    crearListaEnteros(listaA);
//    crearListaEnteros(listaB);
//    crearListaEnteros(listaConcatenada);
//
//    insbackListaEnteros(listaA, 5);
//    insbackListaEnteros(listaA, 1);
//    insbackListaEnteros(listaA, 3);
//    insbackListaEnteros(listaA, 50);
//    insbackListaEnteros(listaA, 120);
//    insbackListaEnteros(listaB, 453);
//    insbackListaEnteros(listaB, 5);
//    insbackListaEnteros(listaB, 9);
//    insbackListaEnteros(listaB, 8);
//    insbackListaEnteros(listaB, 908);
//
//    concatenarSecuencia(listaA, listaB, listaConcatenada);
//
//    listarEnteros(listaConcatenada);

//    Fin bloque de pruebas para invertirLista()

}
