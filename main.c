#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void readFileName(char* filename) {
    printf("Please enter filename: ");
    scanf("%s", filename);
}

void mainloop(FILE* file) {
    //DO SOMETHING
}

int main(int argc, char** argv) {
    char filename[50];
    FILE* file = 0;
    if (argc < 2) {
        readFileName(filename);
        file = fopen(filename, "r");
    } else {
        file = fopen(argv[1], "r");
    }
    if (file == NULL) {
        puts("File could not be read");
        exit(EXIT_FAILURE);
    }
    mainloop(file);
    return (EXIT_SUCCESS);
}
