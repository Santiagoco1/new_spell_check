#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../headers/dict.h"

// Test Get Cupboard
void test_get_cupboard() {
    
    // * Caso lemario vacio
    int amount = 0, max_length = 0;
    char *path1 = "../tests_files/example_cupboard_1.txt";
    char** cupboard1 = get_cupboard(path1, &amount, &max_length);
    assert(cupboard1[0] = NULL);
    assert(amount = 0);
    assert(max_length = 0);
    free(cupboard1);

    // * Caso lemario con una unica palabra
    amount = 0, max_length = 0;
    char *path2 = "../tests_files/example_cupboard_2.txt";
    char** cupboard2 = get_cupboard(path2, &amount, &max_length);
    printf("A\n");
    assert(strcmp(cupboard2[0], "casa") == 0);
    assert(amount = 1);
    assert(max_length = 4);
    free(cupboard2);

    // * Caso lemario con muchas palabras
    amount = 0, max_length = 0;
    char *path3 = "../tests_files/example_cupboard_3.txt";
    char** cupboard3 = get_cupboard(path3, &amount, &max_length);
    assert(strcmp(cupboard3[0], "casa") == 0);
    assert(strcmp(cupboard3[1], "perro") == 0);
    assert(strcmp(cupboard3[2], "gato") == 0);
    assert(amount == 3);
    assert(max_length == 5);
    free(cupboard3);
}

// Test Get Dictionary
void test_get_dictionary() {

    // * Caso 1 : lemario con varias palabras no interconectadas
    int amount1 = 3;
    char **cupboard1 = malloc(sizeof(char*) * amount1);
    cupboard1[0] = malloc(sizeof(char) * 5);
    strcpy(cupboard1[0], "casa\0");
    cupboard1[1] = malloc(sizeof(char) * 5);
    strcpy(cupboard1[1], "gato\0");
    cupboard1[2] = malloc(sizeof(char) * 5);
    strcpy(cupboard1[2], "dedo\0");
    CTree dictionary1 = get_dictionary(cupboard1, amount1);
    
    TNode *cnode1 = dictionary1;
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

    cnode1 = dictionary1;
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

    cnode1 = dictionary1;
    assert(cnode1->data == '\0');
    assert(cnode1->last == 0);
    cnode1 = cnode1->sons[3];
    assert(cnode1->data == 'd');
    assert(cnode1->last == 0);
    cnode1 = cnode1->sons[4];
    assert(cnode1->data == 'e');
    assert(cnode1->last == 0);
    cnode1 = cnode1->sons[3];
    assert(cnode1->data == 'd');
    assert(cnode1->last == 0);
    cnode1 = cnode1->sons[14];
    assert(cnode1->data == 'o');
    assert(cnode1->last == 1);

    ctree_destroy(dictionary1);
    free(cupboard1);

    // * Caso 2 : lemario con varias palabras inteconectadas
    int amount2 = 3;
    char **cupboard2 = malloc(sizeof(char*) * amount2);
    cupboard2[0] = malloc(sizeof(char) * 5);
    strcpy(cupboard2[0], "casa\0");
    cupboard2[1] = malloc(sizeof(char) * 5);
    strcpy(cupboard2[1], "caso\0");
    cupboard2[2] = malloc(sizeof(char) * 5);
    strcpy(cupboard2[2], "case\0");
    
    CTree dictionary2 = get_dictionary(cupboard2, amount2);
    
    TNode *cnode2 = dictionary2;
    assert(cnode2->data == '\0');
    assert(cnode2->last == 0);
    cnode2 = cnode2->sons[2];
    assert(cnode2->data == 'c');
    assert(cnode2->last == 0);
    cnode2 = cnode2->sons[0];
    assert(cnode2->data == 'a');
    assert(cnode2->last == 0);
    cnode2 = cnode2->sons[18];
    assert(cnode2->data == 's');
    assert(cnode2->last == 0);
    
    TNode *ramification = cnode2;
    cnode2 = ramification->sons[0];
    assert(cnode2->data == 'a');
    assert(cnode2->last == 1);

    cnode2 = ramification->sons[14];
    assert(cnode2->data == 'o');
    assert(cnode2->last == 1);

    cnode2 = ramification->sons[4];
    assert(cnode2->data == 'e');
    assert(cnode2->last == 1);

    ctree_destroy(dictionary2);
    free(cupboard2);

    // * Caso 3 : lemario sin palabras
    int amount3 = 1;
    char **cupboard3 = malloc(sizeof(char*) * amount3);
    cupboard3[0] = malloc(sizeof(char) * 5);
    strcpy(cupboard3[0], "casa\0");
    
    CTree dictionary3 = get_dictionary(cupboard3, amount3);
    
    TNode *cnode3 = dictionary3;
    assert(cnode3->data == '\0');
    assert(cnode3->last == 0);
    cnode3 = cnode3->sons[2];
    assert(cnode3->data == 'c');
    assert(cnode3->last == 0);
    cnode3 = cnode3->sons[0];
    assert(cnode3->data == 'a');
    assert(cnode3->last == 0);
    cnode3 = cnode3->sons[18];
    assert(cnode3->data == 's');
    assert(cnode3->last == 0);
    cnode3 = cnode3->sons[0];
    assert(cnode3->data == 'a');
    assert(cnode3->last == 1);

    ctree_destroy(dictionary3);
    free(cupboard3);
}

int main() {
    test_get_dictionary();
    return 0;
}