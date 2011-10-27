#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "avl_tree.h"


void readFileName(char* filename) {
    printf("Please enter filename: ");
    while (scanf("%49s", filename) < 1);
}

bool is_meaningful(word)

void mainloop(FILE* file) {
  int ch;
  int word_length;
  char* word;
  int word_alloc = 50;
  int sentences = 0;
  node* root;

  data = malloc(sizeof(char) * data_alloc);

  while ((ch = fgetc(file)) != EOF) {
    if (ch == ' ' || ch == '\n' || ch == '\t' 
	|| ch == '.' || ch == '!' || ch == '?') {
      /* word boundary */
      if (is_meaningful(word)) {
	insert(root, word);
      }
      word = '';
    }

    if (ch == '.' || ch == '!' || ch == '?') {
      /* also a sentence boundary */
      if(strlen(word) > 1) {
	sentences++;
      }
      word = '';
    }

    if (strlen(word)+2 > word_alloc) {
      /* the current word may be very long, make sure we can memorize it */
      word_alloc *= 2;
      word = remalloc(word, word_alloc);
    }

    word += ch;    
  }

  
}

void printHelp() {
    printf("Program prints the number of sentences and the distribution "
            "how many words the sentences contain. The name of the output "
            "file is given either as a command line parameter or it is read "
            "from stdin.\n EXAMPLE './program coolfile.txt'");
}
