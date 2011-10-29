#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

/**
 * Tekij�: Juuso Hyv�nen
 * Tarkoitus: Parsii komentoriviparametrit sek� kutsuu p��ohjelmaa
 * Parametrit: Parametrien lukum��r�, parametritaulukko.
 * -h tulostaa k�ytt�ohjeet. Muussa tapauksessa parametrin
 * oletetaan olevan tiedostonimi
 * Palauttaa: exit-koodin
 * Muuttaa: Ei mit��n-
 */
int main(int argc, char** argv) {
    FILE* file = 0;
    if (argc > 1 && strcmp(argv[1], "-h") == 0) {
        printHelp();
        return (EXIT_SUCCESS);
    }

    if (argc == 1) {
        file = stdin;
    } else {
        file = fopen(argv[1], "r");
    }
    if (file == NULL) {
        puts("File could not be read\n");
        return (EXIT_FAILURE);
    }

    mainprogram(file);
    return (EXIT_SUCCESS);
}
