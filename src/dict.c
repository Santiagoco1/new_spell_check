#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/dict.h"

char **get_cupboard(char *path, int *amount, int *max_length) {
  // Como no se la cantidad de palabras que tendra el lemario creo un buffer
  // que las ira almacenando y en el caso que llegue a su limite, lo agrando
  // Repito este procedimiento hasta que llegue al final del lemario
  int size = 1024, length;
  char string[35];
  char **buf = malloc(sizeof(char*) * size);

  FILE *file = fopen(path, "r");

  while(fscanf(file, "%s\n", string) == 1) {

    // Me fijo si ya me pase del limite previamente establecido
    if((*amount) >= size) {
      // En el caso que si, lo vuelvo a auemntar por el doble
      size *= 2;
      buf = realloc(buf, sizeof(char*) * size);
    }

    // Guardo la palabra obtenida en el buffer
    length = strlen(string);
    buf[(*amount)] = malloc(sizeof(char) * length+1);
    strcpy(buf[(*amount)], string);
    buf[(*amount)][length] = '\0';

    // Me fijo si la palabra supero el largo maximo, en el caso que si lo cambio
    if(length > (*max_length)) (*max_length) = length;

    (*amount)++;
  }

  fclose(file);
  return buf;
}

CTree get_dictionary(char **cupboard, int amount) {
  // Creo el arbol de caracteres que funcionara como diccionario
  CTree dicionary = ctree_create();
  // Itero por cada una de las palabras del lemario, agregandolas al diccionario
  for(int i = 0; i < amount; i++) {
    ctree_add(dicionary, cupboard[i]);
    free(cupboard[i]);
  }
  return dicionary;
}
