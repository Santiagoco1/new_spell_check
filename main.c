#include <stdio.h>
#include <stdlib.h>
#include "headers/list.h"
#include "headers/dict.h"
#include "headers/check.h"
#include "headers/print.h"

#define LARGEST_WORD 35

int main(int argc, char **argv ) {
  if(argc == 3) {  
    int amount = 0, max_length = 0;
    
    char **cupboard = get_cupboard(argv[1], &amount, &max_length);

    CTree dictionary = get_dictionary(cupboard, amount);
    free(cupboard);

    CList *corrections = check_text(argv[2], dictionary, max_length);
    ctree_destroy(dictionary);

    print_text(corrections, argv[2]);
    free(corrections);

  } else {
    printf("Cantidad incorrecta de argumentos");
  }
  return 0;
}