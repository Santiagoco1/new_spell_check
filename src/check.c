#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../headers/check.h"

#define SUGGESTIONS 5
#define STEPS 3
#define INITIAL_SIZE 1000

char **find_suggestions(CTree dictionary, char *word, int *count) {
  // Asigno los datos necesarios
  int length = strlen(word), length_mod = length, splited = 0;
  TNode *root = dictionary;
  char **suggestions = malloc(sizeof(char*) * SUGGESTIONS);
  for(int i = 0; i < SUGGESTIONS; i++) suggestions[i] = NULL;
  // La palabra modificada tendra una mayor cantidad de caracteres posibles
  // debido a los posibles agregados de caracteres por las modificaciones y por el terminador
  char modded_word[length+STEPS+1]; 

  // Itero sobre la cantidad de modificaciones posibles
  // Asi primero encuentro las de menor cantidad
  int i = 1;
  while((*count) < 5 && i <= STEPS) {
    // Asigno las estructuras que me serviran para llevar un registro del estado del algoritmo
    Words w = {word, length, 0, modded_word, length_mod, 0};
    State s = {count, i, splited};
    // LLamo la funcion que da inicio al algoritmo
    apply_methods(root, root, suggestions, w, s);
    i++;
  }
  // Si no se encontraron sugerencias, borro de la memoria la lista de sugerencias
  // ya que no ya no sera necesario tenerla
  if((*count) > 0) return suggestions;
  else {
    free(suggestions);
    return NULL;
  }
}

Corr *check_word(CTree dictionary, char *word, int length, int line, int max_length) { 
  Corr *correction = NULL;
  // Me fijo si la palabra esta en el diccionario
  if(!ctree_search(dictionary, word)) {
    // En el caso que no, creo una correccion con las sugerencias encontradas
    int count = 0;
    char **suggestions = NULL;
    // Me fijo si la palabra no supera el largo maximo del diccionario
    if(length <= max_length) {
      // En el caso que no, busco las sugerencias
      suggestions = find_suggestions(dictionary, word, &count);
    }
    // La correccion puede tener una lista vacia de sugerencias, indicando que no se han encontrado
    correction = corr_create(word, line, count, suggestions);
  }
  // En el caso que la palabra este en el diccionario, la correccion seguira siendo NULL
  // y por lo tanto no sera tomada en cuenta
  return correction; 
}

CList *check_text(CTree dictionary, char *path, int max_length) {
  // Contador de saltos de linea
  int line = 1;
  // Contador de cantidad de letras
  int i = 0;
  // Variables auxiliares para ir guardando los caracteres y palabras que aparecen en el texto
  char c, str[35];
  Corr *correction;
  CList *corrections_list = clist_create();
  FILE *file = fopen(path, "r");

  // Itera sobre los caracteres del texto, hasta que encuentra un espacio o salto de linea
  // y separa la palabra formada hasta ese entonces, para despues corregirla
  // Ignora ciertos caracteres en especifico
  while(fscanf(file, "%c%*[:;,.?!]", &c) == 1) {
    // Cuando encuentra un enter o un salto de linea corta la palabra que estaba formando
    if(c == ' ' || c == '\n') {
      str[i] = '\0';

      // Se fija si la palabra formada hasta ese entonces no es vacia
      if (i > 0) {
        // Manda a corregir la palabra
        if((correction = check_word(dictionary, str, i, line, max_length))) {
          corrections_list = clist_add_last(corrections_list, correction);
        }
      }
      // Al ya guardar la palabra, resetea el contador de letras
      i = 0;
      // En caso de encontrar un salto de linea, suma uno mas
      if(c == '\n') line++;

    // En el caso que no haya un salto de linea o espacio, sigue adelante, guardando la letra en una auxiliar 
    } else {
      str[i] = tolower(c);
      i++;
    }
  }
  // Me fijo con la ultima palabra del texto
  str[i] = '\0';
  if((i > 0) && (correction = check_word(dictionary, str, i, line, max_length))) {
    corrections_list = clist_add_last(corrections_list, correction);
  }
  fclose(file);
  return corrections_list;
}