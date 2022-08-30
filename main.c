#include <stdio.h>
#include <stdlib.h>
#include "headers/list.h"
#include "headers/dict.h"
#include "headers/check.h"
#include "headers/print.h"

#define LARGEST_WORD 35

int main(int argc, char **argv ) {
  if(argc == 3) {  
    int amount = 0, lengths[LARGEST_WORD];
    for(int i = 0; i < LARGEST_WORD; i++) lengths[i] = 0;
    
    char **words = get_words(argv[1], &amount, lengths);

    CTree dictionary = get_dictionary(words, amount);
    //double_array_destroy(words);

    CList *corrections = check_text(argv[2], dictionary, lengths);
    //ctree_destroy(dictionary);

    print_text(corrections, argv[2]);

  } else {
    printf("Cantidad incorrecta de ");
  }
  return 0;
}