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

CList *clist_create();

CNode *cnode_create(void *data);

CList *clist_add_last(CList *list, void *data);

CNode *cnode_pass(CNode *node);

#endif