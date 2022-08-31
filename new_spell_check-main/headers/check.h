#ifndef __CHECK_H__
#define __CHECK_H__

#include "ctree.h"
#include "corr.h"
#include "list.h"
#include "hash.h"

typedef struct _Strings {
    char *word, *word_mod;
    int length, len_mod;
    int pos, pos_mod;
} Strings;

typedef struct _State {
    int *count;
    int steps;
    int splited;
} State;

void null_method(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word, int length_mod, int pos_wm, int *count, int steps, int splited);

void first_method(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word, int length_mod, int pos_wm, int *count, int steps, int splited);

void second_method(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word, int length_mod, int pos_wm, int *count, int steps, int splited);

void third_method(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word, int length_mod, int pos_wm, int *count, int steps, int splited);

void fourth_method(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word, int length_mod, int pos_wm, int *count, int steps, int splited);

char *get_remaining_word(char *word, int pos, int remaining_letters);

void fifth_method(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word, int length_mod, int pos_wm, int *count, int steps, int splited);

void apply_methods(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word, int length_mod, int pos_wm, int *count, int steps, int splited);

char **find_suggestions(char *word, int *count, CTree dictionary, int *lengths);

int in_range(int length, int *lengths);

CList *check_text(char *path, CTree dictionary, int *lengths);

Corr *check_word(char *str, int length, int line, CTree dictionary, int *lengths);

#endif