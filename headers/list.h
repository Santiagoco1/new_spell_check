#ifndef __LIST_H__
#define __LIST_H__

#include "corr.h"

// Estrucutura CNode
/*
    * Estrcutura que representa un nodo de una lista de correcciones
    - correction : Corr* / correccion a guardar
    - next : CNode* / siguiente nodo en la lista
*/
typedef struct _CNode {
  Corr *correction;
  struct _CNode *next;
} CNode;

// Estructura CList
/*
    * Estructura que representa una lista de correcciones
    - first : CNode* / primer nodo de la lista
    - last : CNode* / ultimo nodo de la lista
*/
typedef struct _CList {
  CNode *first;
  CNode *last;
} CList;

// clist_create : NULL -> CList*
/*
    * Crea y guarda en memoria una CList
 */
CList *clist_create();

// cnode_create : Corr* -> CNode*
/*
    * Crea y guarda en memoria un CNode
    - correction : Corr* - correcion
*/
CNode *cnode_create(Corr *correction);

// clist_add_last : CList*, Corr *data -> CList*
/*
    * Agrega una coreccion al final de una CList
    - list : CList* - lista de corecciones
    - correction : Corr* - coreccion
*/
CList *clist_add_last(CList *list, Corr *correction);

// cnode_pass : CNode* -> CNode*
/*
    * Pasa de un CNode al siguiente, y lo destruye
    - node : CNode* - nodo de correcciones
*/
CNode *cnode_pass(CNode *node);

// cnode_search : CNode*
/*
    * Pasa de un CNode al siguiente, y lo destruye
    - node : CNode* - nodo de correcciones
*/
void cnode_destroy(CNode *node);

// cnode_search : CNode*
/*
    * Pasa de un CNode al siguiente, y lo destruye
    - node : CNode* - nodo de correcciones
*/
void clist_destroy(CList *list);

#endif