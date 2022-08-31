#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/print.h"

// print_text : CList*, char* -> NULL
/*
  * Imprime sobre un archivo las correciones obtenidas
  - corrections : CList* - Lista de correciones
  - path : char* - nombre del archivo de entrada con el texto a corregir
*/
void print_text(CList *corrections, char *path) {
  char *output = malloc(sizeof(char) * strlen(path)+9);
  strcpy(output, path);
  output[strlen(path)-4]='\0';
  strcat(output, "-checked.txt");

  FILE *f = fopen(output, "w");
  CNode *node = corrections->first;

  while(node) {
    corr_fprintf(node -> data, f);  
    node = cnode_pass(node);
  }
  free(output);
  fclose(f);
}