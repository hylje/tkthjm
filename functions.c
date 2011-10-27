#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "avl_tree.h"


void printResults(node* tree, int total, int a, int b, int c, int d) {
    printf("WORD\t\tCOUNT\n");
    print_counts(node* tree);
    printf("Number of sentences: %d\n, Lenght distribution:"
            "1-3: %d  4-6: %d, 7-10: %d,  10+: %d", total, a, b, c, d);
}

void mainloop(FILE* file) {
    fgetc(file);
    //   print();
}

void printHelp() {
    printf("Program prints the number of sentences and the distribution "
            "how many words the sentences contain. The name of the output "
            "file is given either as a command line parameter or it is read "
            "from stdin.\n EXAMPLE './program coolfile.txt'\n");
}