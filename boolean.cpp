#include "boolean.h"

void cargarBoolean(boolean &b) {
    char c;
    printf("Ingrese T para TRUE o F para FALSE\n");
    scanf("%c", &c);
    if (c == 'T')
        b = TRUE;
    if (c == 'F')
        b = FALSE;

}

void mostrarBoolean(boolean b) {
    if (b == TRUE)
        printf("TRUE");
    if (b == FALSE)
        printf("FALSE");
}
