#ifndef __CTREE_H__
#define __CTREE_H__

typedef struct _TNode {
    char data;
    int last;
    struct _TNode **sons;
} TNode;

typedef TNode *CTree;

// tnode_create : char, int -> TNode
/*
    * Crea y guarda en memoria un nuevo TNode con los datos pasados
    - data : char / letra de una palabra guardada en el arbol
    - last : int / bandera que representa si la letra es la ultima de una palabra
*/
TNode *tnode_create(char data, int last);

// ctree_create : NULL -> CTree
/*
    * Crea y guarda en memoria un nuevo CTree
*/
CTree ctree_create();

// _ctree_add : TNode*, char*^, int, int -> NULL
/*
    * Funcion auxiliar de ctree_add
    - node : TNode* / node actual
    - word : char* / palabra a agregar
    - pos : int / posicion en la palabra
    - length : int / largo de la palabra
*/
void _ctree_add(TNode *node, char *word, int pos, int length);

// ctree_add : CTree, char* -> word
/*
    * Guarda una nueva palabra en el diccionario, osea en el arbol de caracteres
    - ctree : CTree / arbol de caracteres que representa el diccionario
    - word : char* / palabra a agregar
*/
void ctree_add(CTree ctree, char *word);

// _ctree_search : TNode*, char*, int, int -> int
/*
    * Funcion auxiliar de ctree_search
    - node : TNode* / node actual
    - word : char* / palabra a buscar
    - pos : int / posicion en la palabra
    - length : int / largo de la palabra 
*/
int _ctree_search(TNode *node, char *word, int pos, int length);

// ctree_search : CTree, char* -> int
/*
    * Busca en un arbol de caracteres la palabra pasada
      devuelve 1 en caso que si, y 0 en el contrario
    - ctree : CTree / arbol de caracteres que representa el diccionario
    - word : char* / palabra a buscar
*/
int ctree_search(CTree ctree, char* word);

// ctree_destroy : TNode* -> NULL
/*
    * Destruye y borra de la memoria un arbol de caracteres
    - node : TNode* / nodo actual
*/
void ctree_destroy(TNode *node);

#endif