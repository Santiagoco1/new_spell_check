#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../headers/check.h"

#define SUGGESTIONS 5
#define STEPS 3
#define INITIAL_SIZE 1000

char **find_suggestions(char *word, int *count, CTree dictionary) {
  int length = strlen(word), length_mod = length, splited = 0;
  TNode *root = dictionary;
  char **suggestions = malloc(sizeof(char*) * SUGGESTIONS);
  char modded_word[length+4]; // explicar 4
  for(int i = 0; i < SUGGESTIONS; i++) suggestions[i] = NULL;

  for(int i = 1; (*count) < 5 && i <= STEPS; i++) {
    apply_methods(root, root, suggestions, word, 0, length, modded_word, length_mod, 0, count, i, splited);
  }
  return suggestions;
}

Corr *check_word(char *word, int length, int line, CTree dictionary, int max_length) { 
  Corr *correction = NULL;
  if(!ctree_search(dictionary, word)) {
    int count = 0;
    char **suggestions = NULL;
    if(length <= max_length) {
      suggestions = find_suggestions(word, &count, dictionary);
    }
    correction = corr_create(word, line, count, suggestions);
  }
  return correction; 
}

CList *check_text(char *path, CTree dictionary, int max_length) {

  int line = 1, i = 0;
  char c, str[35];
  Corr *correction;
  CList *corrections_list = clist_create();
  FILE *file = fopen(path, "r");

  while(fscanf(file, "%c%*[:;,.?!]", &c) == 1) {
    if(c == ' ' || c == '\n') {
      str[i] = '\0';

      if (i > 0) {
        if((correction = check_word(str, i, line, dictionary, max_length))) {
          corrections_list = clist_add_last(corrections_list, correction);
        }
      }
      i = 0;
      if(c == '\n') line++;

    } else {
      str[i] = tolower(c);
      i++;
    }
  }
  str[i] = '\0';
  if((correction = check_word(str, i, line, dictionary, max_length))) {
    corrections_list = clist_add_last(corrections_list, correction);
  }
  fclose(file);
  return corrections_list;
}