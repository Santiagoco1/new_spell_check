#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/ctree.h"

TNode *tnode_create(char data, int last) {
    TNode *new_node = malloc(sizeof(TNode));
    new_node->data = data;
    new_node->last = last;
    new_node->sons = malloc(sizeof(TNode*) * 26);
    for(int i = 0; i < 26; i++) new_node->sons[i] = NULL;
    return new_node;
}

CTree ctree_create() {
    TNode *root = tnode_create('\0', 0);
    return root;
}

void _ctree_add(TNode *node, char *word, int pos, int length) {
    int last = (pos+1 == length);
    int letter_pos = (int)word[pos]-97;
    if(!node->sons[letter_pos]) {
        TNode *new_node = tnode_create(word[pos], last);
        node->sons[letter_pos] = new_node;
    }
    if(!last) _ctree_add(node->sons[letter_pos], word, pos+1, length); 
}

void ctree_add(CTree ctree, char *word) {
    int length = strlen(word);
    int pos = 0;
    TNode *root = ctree;
    _ctree_add(root, word, pos, length);
}

void _ctree_print(TNode *node) {
    if(node != NULL) {
        if(node->data != '\0') printf("%c : %d", node->data, node->last);
        else printf("root");
        printf("[");
        for(int i = 0; i < 26; i++) {
            _ctree_print(node->sons[i]);
        }
        printf("]");    
    }
}

void ctree_print(CTree ctree) {
    TNode *node = ctree;
    _ctree_print(node);
}

int _ctree_search(TNode *node, char *word, int pos, int length) {
    if(pos == length) {
        return (node->last);
    } else {
        int letter_ascii = (int)word[pos]-97;
        return node->sons[letter_ascii] ? _ctree_search(node->sons[letter_ascii], word, pos+1, length) : 0;
    }
}

int ctree_search(CTree ctree, char* word) {
    int length = strlen(word);
    int pos = 0;
    TNode *root = ctree;
    return _ctree_search(root, word, pos, length);
}

void ctree_destroy(TNode *node) {
    for(int i = 0; i < 26; i++) {
        if(node->sons[i]) ctree_destroy(node->sons[i]);
    }
    free(node->sons);
    free(node);
}
