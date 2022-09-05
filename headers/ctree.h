#ifndef __CTREE_H__
#define __CTREE_H__

// Estructura TNode, Tree Node
/*
    * Estructura que representa el nodo de un arbol de caracteres
    - data : char / caracter de una palabra agregada al arbol
    - last : int / bandera que indica si una palabra termina en ese nodo
    - sons : TNode** / lista de nodos que representa cada uno de los caracteres consiguientes posibles
*/
typedef struct _TNode {
    char data;
    int last;
    struct _TNode **sons;
} TNode;

// Estructura CTree, Chars Tree
/*
    * Estrucutra que representa el arbol de caracteres
*/
typedef TNode *CTree;

// tnode_create : char, int -> TNode*
/*
    * Crea y guarda en memoria un nuevo TNode con los datos pasados
    - data : char / letra de una palabra guardada en el arbol
    - last : int / bandera que representa si la letra es la ultima de una palabra
*/
TNode *tnode_create(char data, int last);

// ctree_create : NULL -> CTree
/*
    * Crea y guarda en memoria un nuevo CTree con su respectiva raíz
*/
CTree ctree_create();

// _ctree_add : TNode*, char*, int, int -> NULL
/*
    * Funcion auxiliar de ctree_add
      Se utiliza de forma recursiva para agregar la palabra al CTree
    - node : TNode* / nodo actual
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
      Se utiliza de forma recursiva para buscar una palabra en el CTree
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
    * Destruye y borra de la memoria un TNode
    - node : TNode* / nodo actual del arbol
*/
void tnode_destroy(TNode *node);

// ctree_destroy : CTree* -> NULL
/*
    * Destruye y borra de la memoria un CTree
    - ctree : CTree* / arbol de caracteres
*/
void ctree_destroy(CTree ctree);

#endif