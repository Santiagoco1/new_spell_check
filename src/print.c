#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/print.h"

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

void print_text(CList *corrections, char *path) {

  // Abro o creo el archivo de salida
  FILE *f = fopen(path, "w+");
  CNode *node = corrections->first;

  // Imprimo correccion por correccion, usando una funcion
  while(node) {
    corr_fprintf(node->correction, f);
    node = cnode_pass(node);
  }
  
  fclose(f);
}