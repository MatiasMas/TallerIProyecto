#include "boolean.h"

void cargarBoolean(boolean &b) {
    char c;
    printf("\nIngrese T para TRUE o F para FALSE\n");
    scanf("%c", &c);
    if (c == 'T')
        b = TRUE;
    if (c == 'F')
        b = FALSE;

}

void mostrarBoolean(boolean b) {
    if (b == TRUE)
        printf("\nTRUE\n");
    if (b == FALSE)
        printf("\nFALSE\n");
}
