#ifndef __METD_H__
#define __METD_H__

#include "list.h"
#include "ctree.h"

typedef struct _Strings {
    char *word; 
    int len;
    int pos;
    char *word_mod;
    int len_mod;
    int pos_mod;
} Strings;

typedef struct _State {
    int *count;
    int steps;
    int splited;
} State;

// null_method : TNode*, char**,  -> NULL
/*
    * Este metodo no realiza ninguna modificacion, simplemente avanza al siguiente caracter
    - root : TNode* / raiz del CTree
    - node : TNode* / nodo actual del CTree
    - suggestions : char** / lista de sugerencias encontradas
    -
    -
*/
void null_method(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word, int length_mod, int pos_wm, int *count, int steps, int splited);

// exchange_char : TNode*, char**,  -> NULL
/*
    * Este metodo intercambia dos caracteres abyacentes de la palabra
    - root : TNode* / raiz del CTree
    - node : TNode* / nodo actual del CTree
    - suggestions : char** / lista de sugerencias encontradas
    -
    -
*/
void exchange_char(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word, int length_mod, int pos_wm, int *count, int steps, int splited);

// insert_char : TNode*, char**,  -> NULL
/*
    * Este metodo agrega un caracter a la palabra
    - root : TNode* / raiz del CTree
    - node : TNode* / nodo actual del CTree
    - suggestions : char** / lista de sugerencias encontradas
    -
    -
*/
void insert_char(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word, int length_mod, int pos_wm, int *count, int steps, int splited);

//remove_char : TNode*, char**,  -> NULL
/*
    * Este metodo intercambia una caracter de la palabra
    - root : TNode* / raiz del CTree
    - node : TNode* / nodo actual del CTree
    - suggestions : char** / lista de sugerencias encontradas
    -
    -
*/
void remove_char(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word, int length_mod, int pos_wm, int *count, int steps, int splited);

// change_char : TNode*, char**,  -> NULL
/*
    * Este metodo remueve un caracter de la palabra
    - root : TNode* / raiz del CTree
    - node : TNode* / nodo actual del CTree
    - suggestions : char** / lista de sugerencias encontradas
    -
    -
*/
void change_char(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word, int length_mod, int pos_wm, int *count, int steps, int splited);

// split_word : TNode*, char**,  -> NULL
/*
    * Este metodo divide la palabra en dos
    - root : TNode* / raiz del CTree
    - node : TNode* / nodo actual del CTree
    - suggestions : char** / lista de sugerencias encontradas
    -
    -
*/
void split_word(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word, int length_mod, int pos_wm, int *count, int steps, int splited);

// string_list_search : char**, char*, int -> int
/*
    * Se fija en una lista de strings, si se encuentra un string en especifico
    Devuelve 1 en el caso que si, 0 en el caso contrario
    - list : char** / lista de strings
    - string : char* / string a buscar
    - length : int / largo de la lista
*/
int string_list_search(char **list, char* string, int length);

// check_suggestion : TNode*, char**,  -> NULL
/*
    * Se fija si el string pasado es aceptado por el diccionario,
      en el caso que si, lo guarda en la lista de sugerencias, en el caso contrario no
    - node : TNode* / nodo actual del CTree
    - suggestions : char** / lista de sugerencias encontradas
*/
void check_suggestion(TNode *node, char **suggestions, char *modded_word, int length_mod, int pos_mod, int *count);

// apply_methods : TNode*, TNode*, char**, -> NULL
/*
    * Aplica los distintos metodos de forma recursiva avanzado caracter por caracter de una palabra y plasmando sus
      modificaciones en un nuevo string mientras se mueve por un CTree para poder encontrar las distintas sugerencias
      Al llegar al final de la palabra y al haber hecho todas las modificaciones, se fija si el string modificada es aceptado por el diccionario
    - root : TNode* / raiz del CTree
    - node : TNode* / nodo actual del CTree
    - suggestions : char** / lista de sugerencias encontradas
*/
void apply_methods(TNode *root, TNode *node, char **suggestions, char *word, int pos, int length, char *modded_word, int length_mod, int pos_wm, int *count, int steps, int splited);

#endif