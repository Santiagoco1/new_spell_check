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

void corr_fprintf(Corr *correction, FILE *f) {
  fprintf(f, "Linea %d, '%s' no esta en el diccionario.\n", correction->line, correction->word);
  int i = 0;
  // Me fijo si se encontraron sugerencias
  if(correction->suggs) {
    fprintf(f, "Quizas quiso decir: ");
    // Imprimo cada una de las sugerencias
    for(; i < correction->count-1; i++) {
      fprintf(f, "%s, ", correction->suggs[i]);
    }
    // La ultima no tendra ',' al final, pero si '\n\n' para separarla de la siguiente correccion
    fprintf(f, "%s\n\n", correction->suggs[i]);
  } else {
    // En el caso de no haber encontrado sugerencias, lo notifico
    fprintf(f, "No se encontraron sugerencias\n\n");
  }
}

void corr_destroy(Corr *correction) {
  free(correction->word);
  for(int i = 0; i < correction->count; i++) {
    free(correction->suggs[i]);
  }
  free(correction->suggs);
  free(correction);
}