#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/corr.h"

Corr *corr_create(char *str, int line, int count, char **suggestions) {
  // Reservo la memoria necesaria
  Corr *new_correction = malloc(sizeof(Corr));
  new_correction->word = malloc(sizeof(char) * strlen(str)+1);
  // Asigno los correspondientes datos
  strcpy(new_correction->word, str);
  new_correction->line = line;
  new_correction->count = count;
  new_correction->suggs = suggestions;
  
  return new_correction;
}

void corr_destroy(Corr *correction) {
  free(correction->word);
  for(int i = 0; i < correction->count; i++) {
    free(correction->suggs[i]);
  }
  free(correction->suggs);
  free(correction);
}