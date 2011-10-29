#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"
#include "avl_tree.h"

void printResults(FILE* outfile, node* tree, int total, int a, int b, int c, int d) {
  fprintf(outfile, "COUNT WORD\n");
  print_counts(outfile, tree);
  fprintf(outfile, "Number of sentences: %d\n", total);
  fprintf(outfile, "Length distribution: "
	  "| 1-3: %d | 4-6: %d | 7-10: %d | 10+: %d |\n", a, b, c, d);
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
void mainprogram(FILE* infile, FILE* outfile) {
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

  while ((ch = fgetc(infile)) != EOF) {
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

  printResults(outfile, root, sentences, category_1_3, category_4_6, category_7_10, category_over_10);
}

void printHelp() {
    printf("This program prints the number of sentences and the distribution "
	   "how many words the sentences contain. The name of the input "
	   "file is given either as the first command line parameter "
	   "or assumed to be stdin. The name of the output file is either "
	   "given as the second command line parameter or assumed to be "
	   "stdout. Use '-' as explicit stdin when outputting to a file.\n\n"
	   "EXAMPLES\n"
	   "./tkthjm\n"
	   "./tkthjm coolfile.txt\n"
	   "./tkthjm coolfile.txt coolresult.txt\n"
	   "./tkthjm - coolresult.txt\n");
}

