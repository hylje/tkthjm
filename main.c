#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(int argc, char** argv) {
    char filename[50];
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
        puts("File could not be read");
        return (EXIT_FAILURE);
    }

    mainloop(file);
    return (EXIT_SUCCESS);
}
