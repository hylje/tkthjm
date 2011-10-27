#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"
#include "avl_tree.h"

void printResults(node* tree, int total, int a, int b, int c, int d) {
    printf("WORD\t\tCOUNT\n");
    print_counts(tree);
    printf("Number of sentences: %d\n", total);
    printf("Length distribution:"
            "1-3: %d  4-6: %d, 7-10: %d,  10+: %d\n", a, b, c, d);
}

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
  unsigned int word_pos = 0;
  unsigned int word_alloc = 50;
  int sentences = 0;
  int cur_words = 0;

  int category_1_3 = 0;
  int category_4_6 = 0;
  int category_7_10 = 0;
  int category_over_10 = 0;

  word = malloc(sizeof(char) * word_alloc);

  while ((ch = fgetc(file)) != EOF) {
    if (is_word_boundary(ch)) {
      if (is_meaningful(word)) {
	cur_words++;
	insert(root, word);

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
      
      word_pos = 0;
      word[0] = '\0';
      continue;
    }

    if (strlen(word)+2 > word_alloc) {
      /* the current word may be very long, make sure we can memorize it */
      word_alloc *= 2;
      word = realloc(word, word_alloc);
    }
    
    word[word_pos++] = (char)ch;
    word[word_pos] = '\0';
  }

  printResults(root, sentences, category_1_3, category_4_6, category_7_10, category_over_10);
}

void printHelp() {
    printf("Program prints the number of sentences and the distribution "
            "how many words the sentences contain. The name of the output "
            "file is given either as a command line parameter or it is read "
            "from stdin.\n EXAMPLE './program coolfile.txt'\n");
}

