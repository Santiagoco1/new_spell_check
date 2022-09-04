#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/list.h"

CList *clist_create() {
  // Reservo la memoria necesaria
  CList *list = malloc(sizeof(CList));
  // Asigno los correspondientes datos
  list->first = NULL;
  list->last = NULL;
  return list;
}

CNode *cnode_create(Corr *correction) {
  // Reservo la memoria necesaria
  CNode *new_node = malloc(sizeof(CNode));
  // Asigno los correspondientes datos
  new_node->correction = correction;
  new_node->next = NULL;
  return new_node;
}

CList *clist_add_last(CList *list, Corr *correction) {
  // Creo el nuevo nodo
  CNode *new_node = cnode_create(correction);
  // Modifico las asignaciones con el fin de agregar el nuevo nodo al final
  if(list->first) {
    list->last->next = new_node;
    list->last = new_node;
  } else {
    list->first = new_node;
    list->last = new_node;
  }
  return list;
}

CNode *cnode_pass(CNode *node) {
  // Obtengo la dirreccion del siguiente nodo
  CNode *next_node = node->next;
  // Destruyo el actual
  cnode_destroy(node);
  return next_node;
}

void cnode_destroy(CNode *node) {
  corr_destroy(node->correction);
  free(node);
}

void clist_destroy(CList *list) {
  CNode *node = list->first;
  // Borro los datos de forma iterativa
  while(node) {
    CNode *next_node = node->next;
    cnode_destroy(node);
    node = next_node;
  }
  free(list);
}