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

bool is_sentence_boundary(char ch) {
  return (ch == '.' || ch == '!' || ch == '?');
}

bool is_word_boundary(char ch) {
  return (ch == ' ' || ch == '\n' || ch == '\t' ||
	  ch == ',' || is_sentence_boundary(ch));
}


/* Leo Honkanen */
void mainloop(FILE* file) {
  int ch;
  char* word;
  unsigned int word_alloc = 50;
  int sentences = 0;
  int cur_words = 0;
  node* words_root;

  int category_1_3 = 0;
  int category_4_6 = 0;
  int category_7_10 = 0;
  int category_over_10 = 0;

  root = create_node(NULL, NULL);
  word = malloc(sizeof(char) * word_alloc);

  while ((ch = fgetc(file)) != EOF) {
    if (is_word_boundary(ch)) {
      if (is_meaningful(word)) {
	cur_words++;
	insert(words_root, word);

	if (is_sentence_boundary(ch)) {
	  if (cur_words <= 3) {
	    category_1_3++;
	  }
	  else if (cur_words <= 6) {
	    category_4_6++;
	  }
	  else if (cur_words <= 10) {
	    category_7_10++;
	  }
	  else {
	    category_over_10++;
	  }

	  sentences++;
	  cur_words = 0;
	}
      }

      word = "";
      cur_words++;
    }

    if (strlen(word)+2 > word_alloc) {
      /* the current word may be very long, make sure we can memorize it */
      word_alloc *= 2;
      word = realloc(word, word_alloc);
    }

    word += ch;    
  }

  printResults(root, sentences, category_1_3, category_4_6, category_7_10, category_over_10);
  printf("\n");
  printf("\n");
  printf("1-3 word sentences: %d\n", category_1_3);
  printf("4-6 word sentences: %d\n", category_4_6);
  printf("7-10 word sentences: %d\n", category_7_10);
  printf("over 10 word sentences: %d\n", category_over_10);
  printf("%d sentences total.\n", sentences);
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

