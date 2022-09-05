#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../headers/ctree.h"

// Test TNode Create
void test_tnode_create() {
    TNode *tnode = tnode_create('a', 0);
    assert(tnode->data == 'a');
    assert(tnode->last == 0);
    for(int i = 0; i < 26; i++) {
        assert(tnode->sons[i] == NULL);
    }

    tnode_destroy(tnode);
}

// Test CTree create
void test_ctree_create() {
    CTree ctree = ctree_create();
    assert(ctree->data == '\0');
    assert(ctree->last == 0);
    for(int i = 0; i < 26; i++) {
        assert(ctree->sons[i] == NULL);
    }

    ctree_destroy(ctree);
}

// Test Ctree Add
void test_ctree_add() {
    CTree ctree = ctree_create();

    // Caso 1 : palabras diferentes
    ctree_add(ctree, "casa");
    ctree_add(ctree, "gato");

    TNode *cnode1 = ctree;
    assert(cnode1->data == '\0');
    assert(cnode1->last == 0);
    cnode1 = cnode1->sons[2];
    assert(cnode1->data == 'c');
    assert(cnode1->last == 0);
    cnode1 = cnode1->sons[0];
    assert(cnode1->data == 'a');
    assert(cnode1->last == 0);
    cnode1 = cnode1->sons[18];
    assert(cnode1->data == 's');
    assert(cnode1->last == 0);
    cnode1 = cnode1->sons[0];
    assert(cnode1->data == 'a');
    assert(cnode1->last == 1);

    cnode1 = ctree;
    assert(cnode1->data == '\0');
    assert(cnode1->last == 0);
    cnode1 = cnode1->sons[6];
    assert(cnode1->data == 'g');
    assert(cnode1->last == 0);
    cnode1 = cnode1->sons[0];
    assert(cnode1->data == 'a');
    assert(cnode1->last == 0);
    cnode1 = cnode1->sons[19];
    assert(cnode1->data == 't');
    assert(cnode1->last == 0);
    cnode1 = cnode1->sons[14];
    assert(cnode1->data == 'o');
    assert(cnode1->last == 1);

    // Caso 2 : palabra adentro de otra
    ctree_add(ctree, "gaton");
    TNode *cnode2 = ctree;
    assert(cnode2->data == '\0');
    assert(cnode2->last == 0);
    cnode2 = cnode2->sons[6];
    assert(cnode2->data == 'g');
    assert(cnode2->last == 0);
    cnode2 = cnode2->sons[0];
    assert(cnode2->data == 'a');
    assert(cnode2->last == 0);
    cnode2 = cnode2->sons[19];
    assert(cnode2->data == 't');
    assert(cnode2->last == 0);
    cnode2 = cnode2->sons[14];
    assert(cnode2->data == 'o');
    assert(cnode2->last == 1);
    cnode2 = cnode2->sons[13];
    assert(cnode2->data == 'n');
    assert(cnode2->last == 1);

    // Caso 3 : palabra intercalada con otra
    ctree_add(ctree, "gatos");
    TNode *cnode3 = ctree;
    assert(cnode3->data == '\0');
    assert(cnode3->last == 0);
    cnode3 = cnode3->sons[6];
    assert(cnode3->data == 'g');
    assert(cnode3->last == 0);
    cnode3 = cnode3->sons[0];
    assert(cnode3->data == 'a');
    assert(cnode3->last == 0);
    cnode3 = cnode3->sons[19];
    assert(cnode3->data == 't');
    assert(cnode3->last == 0);
    TNode* ramification = cnode3->sons[14];
    assert(ramification->data == 'o');
    assert(ramification->last == 1);
    cnode3 = ramification->sons[13];
    assert(cnode3->data == 'n');
    assert(cnode3->last == 1);
    cnode3 = ramification->sons[18];
    assert(cnode3->data == 's');
    assert(cnode3->last == 1);

    ctree_destroy(ctree);
}

// Test CTree Search
void test_ctree_search() {
    CTree ctree = ctree_create();
    ctree_add(ctree, "casa");
    ctree_add(ctree, "perro");
    ctree_add(ctree, "gato");

    // Caso 1 : la palabra no esta
    assert(ctree_search(ctree, "dedo") == 0);
    
    // Caso 2 : la palabra esta
    assert(ctree_search(ctree, "casa") == 1);

    // Caso 3 : la palabra esta, pero como una subpalabra de otra
    assert(ctree_search(ctree, "cas") == 0);

    ctree_destroy(ctree);
}

int main() {
    test_tnode_create();
    test_ctree_create();
    test_ctree_add();
    test_ctree_search();
    return 0;
}