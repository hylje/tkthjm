#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"
#include "avl_tree.h"

/* Leo Honkanen */
bool is_meaningful(char* word) {
  return strlen(word) > 1;
}

/* Leo Honkanen */
void mainloop(FILE* file) {
  int ch;
  char* word;
  char* node_word;
  int word_alloc = 50;
  int sentences = 0;
  int words = 0;
  node* root;

  data = malloc(sizeof(char) * data_alloc);

  while ((ch = fgetc(file)) != EOF) {
    if (ch == ' ' || ch == '\n' || ch == '\t' ||
	ch == ',' || ch == '.' || ch == '!' || ch == '?') {
      /* word boundary */
      if (is_meaningful(word)) {
	node_word = malloc(sizeof(char) * strlen(word) + 1);
	strcpy(node_word, word);
	insert(root, node_word);
      }
      word = '';
      words++;
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

  print_ordered(root);
  printf("\n");
  printf("\n");
  printf("%d sentences with an average of %f words each", 
	 sentences, 
	 (float)words/(float)sentences);
  /* TODO print data */
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

