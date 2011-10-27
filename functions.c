#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void mainloop(FILE* file) {
    fgetc(file);
    //   print();
}

/*
 Juuso Hyvönen
 */
void printHelp() {
    printf("Program prints the number of sentences and the distribution "
            "how many words the sentences contain. The name of the output "
            "file is given either as a command line parameter or it is read "
            "from stdin.\n EXAMPLE './program coolfile.txt'\n");
}