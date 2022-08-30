#ifndef __CTREE_H__
#define __CTREE_H__

typedef struct _TNode {
    char data;
    int last;
    struct _TNode **sons;
} TNode;

typedef TNode *CTree;

TNode *tnode_create(char data, int last);

CTree ctree_create();

void _ctree_add(TNode *node, char *word, int pos, int length);

void ctree_add(CTree ctree, char *word);

void ctree_print(CTree ctree);

int _ctree_search(TNode *node, char *word, int pos, int length);

int ctree_search(CTree ctree, char* word);

#endif