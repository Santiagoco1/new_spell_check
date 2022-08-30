#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/corr.h"

Corr *corr_create(char *str, int line, int count, char **suggestions) {
  Corr *new_correction = malloc(sizeof(Corr));
  new_correction->word = malloc(sizeof(char) * strlen(str)+1);
  
  strcpy(new_correction->word, str);
  new_correction->line = line;
  new_correction->count = count;
  new_correction->suggs = suggestions;
  
  return new_correction;
}

void corr_fprintf(Corr *correction, FILE *f) {
  fprintf(f, "Linea %d, '%s' no esta en el diccionario.\n", correction->line, correction->word);
  int i = 0;
  if(correction->suggs) {
    fprintf(f, "Quizas quiso decir: ");
    for(; i < correction->count-1; i++) {
      fprintf(f, "%s, ", correction->suggs[i]);
    }
    fprintf(f, "%s\n\n", correction->suggs[i]);
  } else fprintf(f, "No se encontraron sugerencias\n\n");
}

void corr_destroy(void *correction) {
  free(((Corr*)correction)->word);
  for(int i = 0; i < ((Corr*)correction)->count; i++) {
    free(((Corr*)correction)->suggs[i]);
  }
  free(((Corr*)correction)->suggs);
  free(correction);
}