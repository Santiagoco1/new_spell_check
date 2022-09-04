#ifndef __METD_H__
#define __METD_H__

#include "list.h"
#include "ctree.h"

// Estructura Words
/*
    * Estructura que representa el estado de las palabras a utilizar en el algoritmo
    - word : char* / palabra original a corregir
    - len : int / largo de la palabra original
    - pos : int / posicion actual en la palabra original
    - word_mod : char* / palabra donde se realizan las modificaciones de la actual
    - len_mod : int / largo actual de la palabra modiicada
    - pos_mod : int / posicion actual en la palabra modificada
*/
typedef struct _Words {
    char *word; 
    int len;
    int pos;
    char *word_mod;
    int len_mod;
    int pos_mod;
} Words;

// Estrucutura State
/*
    * Estructura que representa el estado actual del algoritmo
    - count : int* / cantidad actual de sugerencias encontradas
    - steps : int / cantidad actual de modificaciones restantes
    - splited : int / bandera que indica si la palabra fue ya separada
*/
typedef struct _State {
    int *count;
    int steps;
    int splited;
} State;

// null_method : TNode*, char**, Words, State -> NULL
/*
    * Este metodo no realiza ninguna modificacion, simplemente avanza al siguiente caracter
    - root : TNode* / raiz del CTree
    - node : TNode* / nodo actual del CTree
    - suggestions : char** / lista de sugerencias encontradas
    - w : Words / variables que indican el estado de las palabras a utilizar en el algoritmo
    - s : State / variables que indican el estado actual del algoritmo 
*/
void null_method(TNode *root, TNode *node, char **suggestions, Words w, State s);

// exchange_char : TNode*, char**, Words, State -> NULL
/*
    * Este metodo intercambia dos caracteres abyacentes de la palabra
    - root : TNode* / raiz del CTree
    - node : TNode* / nodo actual del CTree
    - suggestions : char** / lista de sugerencias encontradas
    - w : Words / variables que indican el estado de las palabras a utilizar en el algoritmo
    - s : State / variables que indican el estado actual del algoritmo 
*/
void exchange_char(TNode *root, TNode *node, char **suggestions, Words w, State s);

// insert_char : TNode*, char**, Words, State -> NULL
/*
    * Este metodo agrega un caracter a la palabra
    - root : TNode* / raiz del CTree
    - node : TNode* / nodo actual del CTree
    - suggestions : char** / lista de sugerencias encontradas
    - w : Words / variables que indican el estado de las palabras a utilizar en el algoritmo
    - s : State / variables que indican el estado actual del algoritmo 
*/
void insert_char(TNode *root, TNode *node, char **suggestions, Words w, State s);

//remove_char : TNode*, char**, Words, State -> NULL
/*
    * Este metodo intercambia una caracter de la palabra
    - root : TNode* / raiz del CTree
    - node : TNode* / nodo actual del CTree
    - suggestions : char** / lista de sugerencias encontradas
    - w : Words / variables que indican el estado de las palabras a utilizar en el algoritmo
    - s : State / variables que indican el estado actual del algoritmo 
*/
void remove_char(TNode *root, TNode *node, char **suggestions, Words w, State s);

// change_char : TNode*, char**, Words, State -> NULL
/*
    * Este metodo remueve un caracter de la palabra
    - root : TNode* / raiz del CTree
    - node : TNode* / nodo actual del CTree
    - suggestions : char** / lista de sugerencias encontradas
    - w : Words / variables que indican el estado de las palabras a utilizar en el algoritmo
    - s : State / variables que indican el estado actual del algoritmo 
*/
void change_char(TNode *root, TNode *node, char **suggestions, Words w, State s);

// split_word : TNode*, char**, Words, State -> NULL
/*
    * Este metodo divide la palabra en dos
    - root : TNode* / raiz del CTree
    - node : TNode* / nodo actual del CTree
    - suggestions : char** / lista de sugerencias encontradas
    - w : Words / variables que indican el estado de las palabras a utilizar en el algoritmo
    - s : State / variables que indican el estado actual del algoritmo 
*/
void split_word(TNode *root, TNode *node, char **suggestions, Words w, State s);

// string_list_search : char**, char*, int -> int
/*
    * Se fija en una lista de strings, si se encuentra un string en especifico
    Devuelve 1 en el caso que si, 0 en el caso contrario
    - list : char** / lista de strings
    - string : char* / string a buscar
    - length : int / largo de la lista
*/
int string_list_search(char **list, char* string, int length);

// check_suggestion : TNode*, char**, Words, State -> NULL
/*
    * Se fija si el string pasado es aceptado por el diccionario,
      en el caso que si, lo guarda en la lista de sugerencias, en el caso contrario no
    - node : TNode* / nodo actual del CTree
    - suggestions : char** / lista de sugerencias encontradas
    - w : Words / variables que indican el estado de las palabras a utilizar en el algoritmo
    - s : State / variables que indican el estado actual del algoritmo 
*/
void check_suggestion(TNode *node, char **suggestions, Words w, State s);

// apply_methods : TNode*, TNode*, char**, Words, State -> NULL
/*
    * Aplica los distintos metodos de forma recursiva avanzado caracter por caracter de una palabra y plasmando sus
      modificaciones en un nuevo string mientras se mueve por un CTree para poder encontrar las distintas sugerencias
      Al llegar al final de la palabra y al haber hecho todas las modificaciones, se fija si el string modificada es aceptado por el diccionario
    - root : TNode* / raiz del CTree
    - node : TNode* / nodo actual del CTree
    - suggestions : char** / lista de sugerencias encontradas
    - w : Words / variables que indican el estado de las palabras a utilizar en el algoritmo
    - s : State / variables que indican el estado actual del algoritmo 
*/
void apply_methods(TNode *root, TNode *node, char **suggestions, Words w, State s);

#endif