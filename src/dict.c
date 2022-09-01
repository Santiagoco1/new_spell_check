#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/dict.h"

char **get_cupboard(char *path, int *amount, int *max_length) {

  int size = 1024, length;
  char string[35];
  char **buf = malloc(sizeof(char*) * size);

  FILE *file = fopen(path, "r");

  while(fscanf(file, "%s\n", string) == 1) {

    if((*amount) >= size) {
      size *= 2;
      buf = realloc(buf, sizeof(char*) * size);
    }

    length = strlen(string);
    buf[(*amount)] = malloc(sizeof(char) * length+1);
    strcpy(buf[(*amount)], string);
    buf[(*amount)][length] = '\0'; //preguntar
    if(length > (*max_length)) (*max_length) = length;

    (*amount)++;
  }

  fclose(file);
  return buf;
}

CTree get_dictionary(char **cupboard, int amount) {
  CTree dicionary = ctree_create();
  for(int i = 0; i < amount; i++) {
    ctree_add(dicionary, cupboard[i]);
    free(cupboard[i]);
  }
  return dicionary;
}
