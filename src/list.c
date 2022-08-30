#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/list.h"

CList *clist_create() {
  CList *list = malloc(sizeof(CList));
  list->first = NULL;
  list->last = NULL;
  return list;
}

CNode *cnode_create(void *data) {
  CNode *new_node = malloc(sizeof(CNode));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

CList *clist_add_last(CList *list, void *data) {
  CNode *new_node = cnode_create(data);
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
  CNode *next_node = node->next;
  //corr_destroy(node->data);
  free(node);
  return next_node;
}