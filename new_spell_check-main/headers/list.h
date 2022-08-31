#ifndef __LIST_H__
#define __LIST_H__

#include "corr.h"

typedef struct _CNode {
  void *data;
  struct _CNode *next;
} CNode;

typedef struct _CList {
  CNode *first;
  CNode *last;
} CList;

// clist_create : NULL -> CList*
/*
  * Crea una clist
*/
CList *clist_create();

// cnode_create : Corr* -> CNode*
/*
  * Crea un cnode
  - corection : Corr* - correcion
*/
CNode *cnode_create(void *data);

// clist_add_last : CList*, Corr *data -> CList*
/*
  * Agrega una coreccion al final de una clist
  - list : CList* - lista de corecciones
  - corection : Corr* - coreccion
*/
CList *clist_add_last(CList *list, void *data);

// cnode_pass : CNode* -> CNode*
/*
  * Pasa de un cnode al siguiente, y lo destruye
  - node : CNode* - nodo de correcciones
*/
CNode *cnode_pass(CNode *node);

// clist_search : CList*, Corr -> Int
/*
  * Busca en una clist si se encuentra una correccion
  - list : CList* - lista de correcciones
  - corection : Corr* - correccion
*/
int clist_search(CList *list, Corr *correction);

// cnode_search : CNode*
/*
  * Pasa de un cnode al siguiente, y lo destruye
  - node : CNode* - nodo de correcciones
*/
void cnode_destroy(CNode *node);

// cnode_search : CNode*
/*
  * Pasa de un cnode al siguiente, y lo destruye
  - node : CNode* - nodo de correcciones
*/
void clist_destroy(CList *list);

#endif