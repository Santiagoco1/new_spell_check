#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/metd.h"

void null_method(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word,
                   int length_mod, int pos_wm, int *count, int steps, int splited) {
  int letter_ascii = (int)word[pos]-97;
  if(node->sons[letter_ascii]) {
    modded_word[pos_wm] = word[pos];
    TNode *next_node = node->sons[letter_ascii];    
    apply_methods(root, next_node, suggestions, word, pos+1, length, modded_word, length_mod, pos_wm+1, count, steps, splited);
  }
}

void exchange_chars(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word,
                   int length_mod, int pos_wm, int *count, int steps, int splited) {
  int first_letter_ascii = (int)word[pos]-97;
  int second_letter_ascii = (int)word[pos+1]-97;
  if(node->sons[second_letter_ascii] && node->sons[second_letter_ascii]->sons[first_letter_ascii]) {
    modded_word[pos_wm] = word[pos+1];
    modded_word[pos_wm+1] = word[pos];
    TNode *next_node = node->sons[second_letter_ascii]->sons[first_letter_ascii];
    apply_methods(root, next_node, suggestions, word, pos+2, length, modded_word, length_mod, pos_wm+2, count, steps-1, splited);
  }
}

void insert_char(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word,
                     int length_mod, int pos_wm, int *count, int steps, int splited) {
  for(int i = 0; i < 26; i++) {
    if(node->sons[i]) {
      TNode *next_node = node->sons[i];
      modded_word[pos_wm] = next_node->data;
      apply_methods(root, next_node, suggestions, word, pos, length, modded_word, length_mod+1, pos_wm+1, count, steps-1, splited);
    }
  }
}

void remove_char(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word,
                     int length_mod, int pos_wm, int *count, int steps, int splited) {
  apply_methods(root, node, suggestions, word, pos+1, length, modded_word, length_mod, pos_wm, count, steps-1, splited);
}

void change_char(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word,
                     int length_mod, int pos_wm, int *count, int steps, int splited) {
  int letter_ascii = (int)word[pos]-97;
  for(int i = 0; i < 26; i++) {
    if(i != letter_ascii && node->sons[i]) {
      TNode *next_node = node->sons[i];
      modded_word[pos_wm] = next_node->data;
      apply_methods(root, next_node, suggestions, word, pos+1, length, modded_word, length_mod, pos_wm+1, count, steps-1, splited);
    }
  }
}

void split_word(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word,
                     int length_mod, int pos_wm, int *count, int steps, int splited) {
  if(node->last) {
    modded_word[pos_wm] = '-';
    int remaining_letters = length - (pos);
    char *remaining_word = word+pos; //explicar
    apply_methods(root, root, suggestions, remaining_word, 0, remaining_letters, modded_word, length_mod+1, pos_wm+1,
    count, steps-1, 1);
  }
}

int string_list_search(char **list, char* string, int length) {
  for(int i = 0; i < length; i++) {
    if(strcmp(list[i], string) == 0) return 1;
  }
  return 0;
}

void check_suggestion(TNode *node, char **suggestions, char *modded_word, int length_mod, int pos_mod, int *count) {
  modded_word[pos_mod] = '\0';
  if(node->last && !string_list_search(suggestions, modded_word, (*count))) {
    suggestions[(*count)] = malloc(sizeof(char) * length_mod+1);
    strcpy(suggestions[(*count)], modded_word);
    (*count)++;
  }
}

void apply_methods(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word,
                    int length_mod, int pos_wm, int *count, int steps, int splited) {
  if((*count) < 5) {
    if(pos == length) {
      if(steps > 0) {
        insert_char(root, node, suggestions, word, pos, length, modded_word, length_mod, pos_wm, count, steps, splited);
      } else {
        check_suggestion(node, suggestions, modded_word, length_mod, pos_wm, count);
      }
    } else {
      null_method(root, node, suggestions, word, pos, length, modded_word, length_mod, pos_wm, count, steps, splited);
      if(steps > 0) {
        if(pos+1 != length) exchange_chars(root, node, suggestions, word, pos, length, modded_word, length_mod, pos_wm, count, steps, splited);
        insert_char(root, node, suggestions, word, pos, length, modded_word, length_mod, pos_wm, count, steps, splited);
        remove_char(root, node, suggestions, word, pos, length, modded_word, length_mod, pos_wm, count, steps, splited);
        change_char(root, node, suggestions, word, pos, length, modded_word, length_mod, pos_wm, count, steps, splited);
        if(splited == 0 && pos > 0 && pos+1 < length) split_word(root, node, suggestions, word, pos, length, modded_word, length_mod, pos_wm, count, steps, splited);
      } 
    }
  }
}