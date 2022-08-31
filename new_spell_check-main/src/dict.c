#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/dict.h"

char **get_words(char *path, int *amount, int *lengths) {

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
    buf[(*amount)] = malloc(sizeof(char) * length);
    strcpy(buf[(*amount)], string);
    if(!lengths[length]) lengths[length]++;

    (*amount)++;
  }

  fclose(file);
  return buf;
}

CTree get_dictionary(char **words, int amount) {
  CTree dicionary = ctree_create();
  for(int i = 0; i < amount; i++) {
    ctree_add(dicionary, words[i]);
  }
  return dicionary;
}
