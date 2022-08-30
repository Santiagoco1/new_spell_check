#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../headers/check.h"

#define SUGGESTIONS 5
#define STEPS 3
#define INITIAL_SIZE 1000

void null_method(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word, int pos_wm, int *count, int steps, int splited) {
  int letter_ascii = (int)word[pos]-97;
  if(node->sons[letter_ascii]) {
    modded_word[pos_wm] = word[pos];
    TNode *next_node = node->sons[letter_ascii];    
    apply_methods(root, next_node, suggestions, word, pos+1, length, modded_word, pos_wm+1, count, steps, splited);
  } else {
  }
}

void first_method(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word, int pos_wm, int *count, int steps, int splited) {
  int first_letter_ascii = (int)word[pos]-97;
  int second_letter_ascii = (int)word[pos+1]-97;
  if(node->sons[second_letter_ascii] && node->sons[second_letter_ascii]->sons[first_letter_ascii]) {
    modded_word[pos_wm] = word[pos+1];
    modded_word[pos_wm+1] = word[pos];
    TNode *next_node = node->sons[second_letter_ascii]->sons[first_letter_ascii];
    apply_methods(root, next_node, suggestions, word, pos+2, length, modded_word, pos_wm+2, count, steps-1, splited);
  } else {
  }
}

void second_method(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word, int pos_wm, int *count, int steps, int splited) {
  for(int i = 0; i < 26; i++) {
    if(node->sons[i]) {
      TNode *next_node = node->sons[i];
      modded_word[pos_wm] = next_node->data;
      apply_methods(root, next_node, suggestions, word, pos, length, modded_word, pos_wm+1, count, steps-1, splited);
    }
  }
}

void third_method(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word, int pos_wm, int *count, int steps, int splited) {
  apply_methods(root, node, suggestions, word, pos+1, length, modded_word, pos_wm, count, steps-1, splited);
}

void fourth_method(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word, int pos_wm, int *count, int steps, int splited) {
  int letter_ascii = (int)word[pos]-97;
  for(int i = 0; i < 26; i++) {
    if(i != letter_ascii && node->sons[i]) {
      TNode *next_node = node->sons[i];
      modded_word[pos_wm] = next_node->data;
      apply_methods(root, next_node, suggestions, word, pos+1, length, modded_word, pos_wm+1, count, steps-1, splited);
    }
  }
}

char *get_remaining_word(char *word, int pos, int remaining_letters) {
  char *remaining_word = malloc(sizeof(char) * remaining_letters);
  for(int i = 0; i < remaining_letters; i++) {
    remaining_word[i] = word[pos+i];
  }
  return remaining_word;
}

void fifth_method(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word, int pos_wm, int *count, int steps, int splited) {
  if(node->last) {
    modded_word[pos_wm] = '-';
    int remaining_letters = length - (pos+1);
    char *remaining_word = get_remaining_word(word, pos+1, remaining_letters);
    apply_methods(root, root, suggestions, remaining_word, 0, remaining_letters, modded_word, pos_wm+1, count, steps-1, 1);
  } else {
  }
}

void apply_methods(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word, int pos_wm, int *count, int steps, int splited) {
  if((*count) < 5) {
    if(pos == length) {
      if(node->last) {
        suggestions[(*count)] = malloc(sizeof(char) * length+1);
        strcpy(suggestions[(*count)], modded_word);
        suggestions[(*count)][pos_wm] = '\0';
        (*count)++;
      }
    } else {
      null_method(root, node, suggestions, word, pos, length, modded_word, pos_wm, count, steps, splited);
      if(steps > 0) {
        if(pos+1 != length) first_method(root, node, suggestions, word, pos, length, modded_word, pos_wm, count, steps, splited);
        second_method(root, node, suggestions, word, pos, length, modded_word, pos_wm, count, steps, splited);
        third_method(root, node, suggestions, word, pos, length, modded_word, pos_wm, count, steps, splited);
        fourth_method(root, node, suggestions, word, pos, length, modded_word, pos_wm, count, steps, splited);
        if(splited == 0 && pos > 0 && pos+1 < length) fifth_method(root, node, suggestions, word, pos, length, modded_word, pos_wm, count, steps, splited);
      } 
    }
  }
}

char **find_suggestions(char *word, int *count, CTree dictionary, int *lengths) {
  int length = strlen(word), splited = 0;
  TNode *root = dictionary;
  char **suggestions = malloc(sizeof(char*) * SUGGESTIONS), modded_word[length+3];
  for(int i = 0; i < SUGGESTIONS; i++) suggestions[i] = NULL;

  for(int i = 1; (*count) < 5 && i <= STEPS; i++) {
    apply_methods(root, root, suggestions, word, 0, length, modded_word, 0, count, i, splited);
  }
  return suggestions;
}

int in_range(int length, int *lengths) {
  if(lengths[length]) return 1;
  for(int i = 1; i <= STEPS; i++) {
    if(lengths[length+i]) return 1;
    if(lengths[length-i]) return 1;
  }
  return 0;
}

Corr *check_word(char *word, int length, int line, CTree dictionary, int *lengths) { 
  Corr *correction = NULL;
  if(!ctree_search(dictionary, word)) {
    int count = 0;
    char **suggestions = NULL;
    if(in_range(length, lengths)) {
      suggestions = find_suggestions(word, &count, dictionary, lengths);
    }
    correction = corr_create(word, line, count, suggestions);
  }

  return correction; 
}

CList *check_text(char *path, CTree dictionary, int *lengths) {

  int line = 1, i = 0;
  char c, str[35];
  Corr *correction;
  CList *corrections_list = clist_create();
  //HashTable *correction_table = hashtable_create(INITIAL_SIZE);
  FILE *file = fopen(path, "r");

  while(fscanf(file, "%c%*[:;,.?!]", &c) == 1) {
    if(c == ' ' || c == '\n') {
      str[i] = '\0';

      for(int j = 0; j < i; j++) {
        str[j] = tolower(str[j]);
      }

      if((correction = check_word(str, i, line, dictionary, lengths))) {
        corrections_list = clist_add_last(corrections_list, correction);
      }
      i = 0;
      if(c == '\n') line++;
    } else {
      str[i] = c;
      i++;
    }
  }
  str[i] = '\0';
  if((correction = check_word(str, i, line, dictionary, lengths))) {
    corrections_list = clist_add_last(corrections_list, correction);
  }
  fclose(file);
  return corrections_list;
}