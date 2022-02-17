#include "string.h"

//Crea un string vacio
void crearString(string &s) {
    s = new char[MAX];
    s[0] = '\0';
}

//Libera la memoria usada por el string
void destruirString(string &s) {
    delete[] s;
    s = NULL;
}

//Carga el string desde teclado
void cargarString(string &s) {
    string aux = new char[MAX];
    int i = 0;
    char c;

    scanf("%c", &c);
    while ((c != '\n' && i < MAX - 1)) {
        aux[i] = c;
        i++;
        scanf("%c", &c);
    }

    aux[i] = '\0';
    copiarString(s, aux);
    destruirString(aux);
}

//Imprime el string pasado
void printString(string s) {
    int i = 0;

    while (s[i] != '\0') {
        printf("%c", s[i]);
        i++;
    }
}

//Copia el valor del string 2 en el string 1
void copiarString(string &s1, string s2) {
    int i = 0;
    int largo = stringLargo(s2) + 1;

    delete[] s1;
    s1 = new char[largo];
    while (s2[i] != '\0') {
        s1[i] = s2[i];
        i++;
    }

    s1[i] = '\0';
}

//Retorna longitud del string
int stringLargo(string s) {
    int i = 0;

    while (s[i] != '\0')
        i++;
    return i;
}

boolean stringIguales(string s1, string s2) {
    int i = 0;
    boolean iguales = TRUE;

    while (iguales && (s1[i] != '\0') && (s2[i] != '\0')) {
        if (s1[i] != s2[i]) {
            iguales = FALSE;
        }
        i++;
    }

    if ((s1[i] != '\0') || (s2[i] != '\0')) {
        iguales = FALSE;
    }
    return iguales;
}

void cargarStringExtensionArchivo(string &s) {
    string aux = new char[MAX];
    aux[0] = '.';
    aux[1] = 't';
    aux[2] = 'x';
    aux[3] = 't';

    aux[4] = '\0';
    copiarString(s, aux);
    destruirString(aux);
}

boolean extensionArchivoValido(string nombreArchivo) {
    boolean valido = TRUE;
    string aux, stringExtensionArchivo;
    int i = 0, index = 0;
    crearString(aux);

    int largoString = stringLargo(nombreArchivo);
    if (largoString <= 4) {
        return valido = FALSE;
    } else {
        index = largoString - 4;
    }

    while (nombreArchivo[index] != '\0') {
        aux[i] = nombreArchivo[index];
        index++;
        i++;
    }

    aux[i] = '\0';
    cargarStringExtensionArchivo(stringExtensionArchivo);

    if (!stringIguales(aux, stringExtensionArchivo)) {
        return valido = FALSE;
    }

    return valido;
}

boolean nombreArchivoValido(string nombreArchivo) {
    boolean valido = TRUE;
    string aux;
    int index = 0, i = 0;

    int largoString = stringLargo(nombreArchivo);
    if (largoString <= 4) {
        return valido = FALSE;
    } else {
        index = largoString - 4;
    }

//    Analizar si se puede sustituir este bloque de codigo por la funcion esAlfabetico
    while (i < index) {
        if (nombreArchivo[i] >= 'A' && nombreArchivo[i] <= 'Z' || nombreArchivo[i] >= 'a' && nombreArchivo[i] <= 'z') {
            i++;
        } else {
            return valido = FALSE;
        }
    }

    return valido;
}

boolean esAlfabetico(string s) {
    boolean valido = TRUE;
    int i = 0;

    while (s[i] != '\0') {
        if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z') {
            i++;
        } else {
            return valido = FALSE;
        }
    }

    return valido;
}

void bajarString(string s, FILE *f) {

    int i = 0;
    while (s[i] != '\0') {
        fwrite(&s[i], sizeof(char), 1, f);
        i++;
    }
    // escribo el '\0'
    fwrite(&s[i], sizeof(char), 1, f);

}

//Probar esto con archivos
void levantarString(string &s, FILE *f) {
    int i = 0;
    string aux;

    aux = new char[MAX];
    fread(&aux[i], sizeof(char), 1, f);

    while (!feof(f) && (aux[i] != '\0')) {
        i++;
        fread(&aux[i], sizeof(char), 1, f);
    }

    copiarString(s, aux);
    delete[] aux;
}
