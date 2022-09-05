#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/ctree.h"

TNode *tnode_create(char data, int last) {
    // Reservo la memoria necesaria
    TNode *new_node = malloc(sizeof(TNode));
    new_node->sons = malloc(sizeof(TNode*) * 26);
    // Asigno los datos correpondientes
    new_node->data = data;
    new_node->last = last;
    for(int i = 0; i < 26; i++) new_node->sons[i] = NULL;
    return new_node;
}

CTree ctree_create() {
    // Creo la raiz del arbol, la cual tendra ciertos datos en especifico
    TNode *root = tnode_create('\0', 0);
    return root;
}

void _ctree_add(TNode *node, char *word, int pos, int length) {
    int last = (pos+1 == length);
    int letter_pos = (int)word[pos]-97;
    // Me fijo si el nodo al cual me tengo que mover ya existe en el arbol
    if(!node->sons[letter_pos]) {
        // En el caso que no, creo uno nuevo con los datos
        TNode *new_node = tnode_create(word[pos], last);
        node->sons[letter_pos] = new_node;
    } else if(!node->sons[letter_pos]->last && last) {
        // En el caso que si y que estemos al final de la palabra
        // modifico la bandera 'last' del nodo ya existente
        // para poder representar la nueva palabra ingresada
        node->sons[letter_pos]->last = last;
    }
    // En el caso que exista el nodo y que no estemos a final de la palabra
    // simplemente avanzo hacia el siguiente nodo
    if(!last) _ctree_add(node->sons[letter_pos], word, pos+1, length); 
}

void ctree_add(CTree ctree, char *word) {
    // Consigo los datos necesarios
    int length = strlen(word);
    int pos = 0;
    TNode *root = ctree;
    // Llamo una funcion auxiliar, para poder utilizar recursion al agregar la palabra
    _ctree_add(root, word, pos, length);
}

int _ctree_search(TNode *node, char *word, int pos, int length) {
    // Primero me fijo si llegue al final de la palabra
    if(pos == length) {
        // Me fijo si es una palabra del diccionario, en el caso que una palabra termine justo en el nodo actual
        return (node->last);
    } else {
        // En caso que no, me fijo si me puedo mover al siguiente nodo con el siguiente caracter
        // Si no puedo, entonces significa que la palabra no esta y devuelvo 0
        int letter_ascii = (int)word[pos]-97;
        return node->sons[letter_ascii] ? _ctree_search(node->sons[letter_ascii], word, pos+1, length) : 0;
    }
}

int ctree_search(CTree ctree, char* word) {
    // Consigo los datos necesarios
    int length = strlen(word);
    int pos = 0;
    TNode *root = ctree;
    // Llamo a una funcion auxiliar para usar recursion en la busqueda
    return _ctree_search(root, word, pos, length);
}

void tnode_destroy(TNode *node) {
    for(int i = 0; i < 26; i++) {
        if(node->sons[i]) tnode_destroy(node->sons[i]);
    }
    free(node->sons);
    free(node);
}

void ctree_destroy(CTree ctree) {
    // Consigo la dirreccion de memoria de la raiz
    TNode *root = ctree;
    // Llamo a una funcion auxiliar para usar recursion al eliminar el arbol
    tnode_destroy(root);
}
