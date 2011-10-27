#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

/**
 * Tekijä: Juuso Hyvönen
 * Tarkoitus: Parsii komentoriviparametrit sekä kutsuu pääohjelmaa
 * Parametrit: Parametrien lukumäärä, parametritaulukko.
 * -h tulostaa käyttöohjeet. Muussa tapauksessa parametrin
 * oletetaan olevan tiedostonimi
 * Palauttaa: exit-koodin
 * Muuttaa: Ei mitään-
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

    mainloop(file);
    return (EXIT_SUCCESS);
}
