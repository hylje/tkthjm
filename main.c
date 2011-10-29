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
    FILE* infile = 0;
    FILE* outfile = 0;

    // -h flag for help
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
      printHelp();
      return (EXIT_SUCCESS);
    }

    // No Parameters
    if (argc == 1) {
        infile = stdin;
	outfile = stdout;
    }
    
    // One parameter
    else if (argc == 2) {
      infile = fopen(argv[1], "r");
      outfile = stdout;
    }
    
    // Two parameters
    else if (argc == 3) {
      if (strcmp(argv[1], "-") == 0) {
	infile = stdin;
      } else {
	infile = fopen(argv[1], "r");
      }
      outfile = fopen(argv[2], "w");
    }
    
    if (infile == NULL) {
      puts("Input file could not be read\n");
      return (EXIT_FAILURE);
    }
    if (outfile == NULL) {
      puts("Output file could not be written to\n");
      return (EXIT_FAILURE);
    }

    mainprogram(infile, outfile);
    return (EXIT_SUCCESS);
}
