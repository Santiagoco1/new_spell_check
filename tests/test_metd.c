#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../headers/metd.h"
#include "../headers/auxi.h"

// ** No testeo el metodo nulo, debido a que no hace modificaciones y por lo tanto no es posible revisarlo **

// Test Exchange Chars
void test_exchange_chars() {
    // Caso 1 : Intercambiar caracteres 1 y 2
    CTree ctree1 = ctree_create();
    ctree_add(ctree1, "agto\0");
    TNode *root1 = ctree1;

    int count1 = 0;
    char **suggestions1 = malloc(sizeof(char*) * 1);
    char mod_word1[8];

    Words w1 = {"gato", 4, 0, mod_word1, 4, 0};
    State s1 = {&count1, 1, 0};

    apply_methods(root1, root1, suggestions1, w1, s1);

    assert(strcmp(suggestions1[0], "agto") == 0);

    ctree_destroy(ctree1);
    double_list_destroy(suggestions1, 1);
    
    // Caso 2 : Intercambiar caracteres 2 y 3
    CTree ctree2 = ctree_create();
    ctree_add(ctree2, "gtao\0");
    TNode *root2 = ctree2;

    int count2 = 0;
    char **suggestions2 = malloc(sizeof(char*) * 1);
    char mod_word2[8];

    Words w2 = {"gato", 4, 0, mod_word2, 4, 0};
    State s2 = {&count2, 1, 0};

    apply_methods(root2, root2, suggestions2, w2, s2);

    assert(strcmp(suggestions2[0], "gtao") == 0);

    ctree_destroy(ctree2);
    double_list_destroy(suggestions2, 1);

    // Caso 3 : Intercambiar caracteres 3 y 4
    CTree ctree3 = ctree_create();
    ctree_add(ctree3, "gaot\0");
    TNode *root3 = ctree3;

    int count3 = 0;
    char **suggestions3 = malloc(sizeof(char*) * 1);
    char mod_word3[8];

    Words w3 = {"gato", 4, 0, mod_word3, 4, 0};
    State s3 = {&count3, 1, 0};

    apply_methods(root3, root3, suggestions3, w3, s3);

    assert(strcmp(suggestions3[0], "gaot") == 0);

    ctree_destroy(ctree3);
    double_list_destroy(suggestions3, 1);
}

// Test Insert Char
void test_insert_char() {
    // Caso 1 : Agregar letra al principio
    CTree ctree1 = ctree_create();
    ctree_add(ctree1, "xgato\0");
    TNode *root1 = ctree1;

    int count1 = 0;
    char **suggestions1 = malloc(sizeof(char*) * 1);
    char mod_word1[8];

    Words w1 = {"gato", 4, 0, mod_word1, 4, 0};
    State s1 = {&count1, 1, 0};

    apply_methods(root1, root1, suggestions1, w1, s1);

    assert(strcmp(suggestions1[0], "xgato") == 0);

    ctree_destroy(ctree1);
    double_list_destroy(suggestions1, 1);

    // Caso 2 : Agregar letra entre 1-2
    CTree ctree2 = ctree_create();
    ctree_add(ctree2, "gxato\0");
    TNode *root2 = ctree2;

    int count2 = 0;
    char **suggestions2 = malloc(sizeof(char*) * 1);
    char mod_word2[8];

    Words w2 = {"gato", 4, 0, mod_word2, 4, 0};
    State s2 = {&count2, 1, 0};

    apply_methods(root2, root2, suggestions2, w2, s2);

    assert(strcmp(suggestions2[0], "gxato") == 0);

    ctree_destroy(ctree2);
    double_list_destroy(suggestions2, 1);

    // Caso 3 : Agregar letra entre 2-3
    CTree ctree3 = ctree_create();
    ctree_add(ctree3, "gaxto\0");
    TNode *root3 = ctree3;

    int count3 = 0;
    char **suggestions3 = malloc(sizeof(char*) * 1);
    char mod_word3[8];

    Words w3 = {"gato", 4, 0, mod_word3, 4, 0};
    State s3 = {&count3, 1, 0};

    apply_methods(root3, root3, suggestions3, w3, s3);

    assert(strcmp(suggestions3[0], "gaxto") == 0);

    ctree_destroy(ctree3);
    double_list_destroy(suggestions3, 1);

    // Caso 4 : Agregar letra entre 3-4
    CTree ctree4 = ctree_create();
    ctree_add(ctree4, "gatxo\0");
    TNode *root4 = ctree4;

    int count4 = 0;
    char **suggestions4 = malloc(sizeof(char*) * 1);
    char mod_word4[8];

    Words w4 = {"gato", 4, 0, mod_word4, 4, 0};
    State s4 = {&count4, 1, 0};

    apply_methods(root4, root4, suggestions4, w4, s4);

    assert(strcmp(suggestions4[0], "gatxo") == 0);

    ctree_destroy(ctree4);
    double_list_destroy(suggestions4, 1);

    // Caso 5 : Agregar letra al final
    CTree ctree5 = ctree_create();
    ctree_add(ctree5, "gatox\0");
    TNode *root5 = ctree5;

    int count5 = 0;
    char **suggestions5 = malloc(sizeof(char*) * 1);
    char mod_word5[8];

    Words w5 = {"gato", 4, 0, mod_word5, 4, 0};
    State s5 = {&count5, 1, 0};

    apply_methods(root5, root5, suggestions5, w5, s5);

    assert(strcmp(suggestions5[0], "gatox") == 0);

    ctree_destroy(ctree5);
    double_list_destroy(suggestions5, 1);
}

// Test Remove Char
void test_remove_char() {
    // Caso 1 : Borrar primer letra
    CTree ctree1 = ctree_create();
    ctree_add(ctree1, "ato\0");
    TNode *root1 = ctree1;

    int count1 = 0;
    char **suggestions1 = malloc(sizeof(char*) * 1);
    char mod_word1[8];

    Words w1 = {"gato", 4, 0, mod_word1, 4, 0};
    State s1 = {&count1, 1, 0};

    apply_methods(root1, root1, suggestions1, w1, s1);

    assert(strcmp(suggestions1[0], "ato") == 0);

    ctree_destroy(ctree1);
    double_list_destroy(suggestions1, 1);

    // Caso 2 : Borrar segunda letra
    CTree ctree2 = ctree_create();
    ctree_add(ctree2, "gto\0");
    TNode *root2 = ctree2;

    int count2 = 0;
    char **suggestions2 = malloc(sizeof(char*) * 1);
    char mod_word2[8];

    Words w2 = {"gato", 4, 0, mod_word2, 4, 0};
    State s2 = {&count2, 1, 0};

    apply_methods(root2, root2, suggestions2, w2, s2);

    assert(strcmp(suggestions2[0], "gto") == 0);

    ctree_destroy(ctree2);
    double_list_destroy(suggestions2, 1);

    // Caso 3 : Borrar tercera letra
    CTree ctree3 = ctree_create();
    ctree_add(ctree3, "gao\0");
    TNode *root3 = ctree3;

    int count3 = 0;
    char **suggestions3 = malloc(sizeof(char*) * 1);
    char mod_word3[8];

    Words w3 = {"gato", 4, 0, mod_word3, 4, 0};
    State s3 = {&count3, 1, 0};

    apply_methods(root3, root3, suggestions3, w3, s3);

    assert(strcmp(suggestions3[0], "gao") == 0);

    ctree_destroy(ctree3);
    double_list_destroy(suggestions3, 1);

    // Caso 4 : Borrar cuarta letra
    CTree ctree4 = ctree_create();
    ctree_add(ctree4, "gat\0");
    TNode *root4 = ctree4;

    int count4 = 0;
    char **suggestions4 = malloc(sizeof(char*) * 1);
    char mod_word4[8];

    Words w4 = {"gato", 4, 0, mod_word4, 4, 0};
    State s4 = {&count4, 1, 0};

    apply_methods(root4, root4, suggestions4, w4, s4);

    assert(strcmp(suggestions4[0], "gat") == 0);

    ctree_destroy(ctree4);
    double_list_destroy(suggestions4, 1);
}

// Test Change Char
void test_change_char() {
    // Caso 1 : Cambiar primera letra
    CTree ctree1 = ctree_create();
    ctree_add(ctree1, "xato\0");
    TNode *root1 = ctree1;

    int count1 = 0;
    char **suggestions1 = malloc(sizeof(char*) * 1);
    char mod_word1[8];

    Words w1 = {"gato", 4, 0, mod_word1, 4, 0};
    State s1 = {&count1, 1, 0};

    apply_methods(root1, root1, suggestions1, w1, s1);

    assert(strcmp(suggestions1[0], "xato") == 0);

    ctree_destroy(ctree1);
    double_list_destroy(suggestions1, 1);

    // Caso 2 : Cambiar segunda letra
    CTree ctree2 = ctree_create();
    ctree_add(ctree2, "gxto\0");
    TNode *root2 = ctree2;

    int count2 = 0;
    char **suggestions2 = malloc(sizeof(char*) * 1);
    char mod_word2[8];

    Words w2 = {"gato", 4, 0, mod_word2, 4, 0};
    State s2 = {&count2, 1, 0};

    apply_methods(root2, root2, suggestions2, w2, s2);

    assert(strcmp(suggestions2[0], "gxto") == 0);

    ctree_destroy(ctree2);
    double_list_destroy(suggestions2, 1);

    // Caso 3 : Cambiar tercera letra
    CTree ctree3 = ctree_create();
    ctree_add(ctree3, "gaxo\0");
    TNode *root3 = ctree3;

    int count3 = 0;
    char **suggestions3 = malloc(sizeof(char*) * 1);
    char mod_word3[8];

    Words w3 = {"gato", 4, 0, mod_word3, 4, 0};
    State s3 = {&count3, 1, 0};

    apply_methods(root3, root3, suggestions3, w3, s3);

    assert(strcmp(suggestions3[0], "gaxo") == 0);

    ctree_destroy(ctree3);
    double_list_destroy(suggestions3, 1);

    // Caso 4 : Cambiar cuarta letra
    CTree ctree4 = ctree_create();
    ctree_add(ctree4, "gatx\0");
    TNode *root4 = ctree4;

    int count4 = 0;
    char **suggestions4 = malloc(sizeof(char*) * 1);
    char mod_word4[8];

    Words w4 = {"gato", 4, 0, mod_word4, 4, 0};
    State s4 = {&count4, 1, 0};

    apply_methods(root4, root4, suggestions4, w4, s4);

    assert(strcmp(suggestions4[0], "gatx") == 0);

    ctree_destroy(ctree4);
    double_list_destroy(suggestions4, 1);
}

// Test Split Word
void test_split_word() {
    // Caso 1 : Separar entre 1-2
    CTree ctree1 = ctree_create();
    ctree_add(ctree1, "g\0");
    ctree_add(ctree1, "ato\0");
    TNode *root1 = ctree1;

    int count1 = 0;
    char **suggestions1 = malloc(sizeof(char*) * 2);
    char mod_word1[8];

    Words w1 = {"gato", 4, 0, mod_word1, 4, 0};
    State s1 = {&count1, 1, 0};

    apply_methods(root1, root1, suggestions1, w1, s1);

    assert(string_list_search(suggestions1, "g-ato", 5) == 1);

    ctree_destroy(ctree1);
    double_list_destroy(suggestions1, 2);

    // Caso 2 : Separar entre 2-3
    CTree ctree2 = ctree_create();
    ctree_add(ctree2, "ga\0");
    ctree_add(ctree2, "to\0");
    TNode *root2 = ctree2;

    int count2 = 0;
    char **suggestions2 = malloc(sizeof(char*) * 1);
    char mod_word2[8];

    Words w2 = {"gato", 4, 0, mod_word2, 4, 0};
    State s2 = {&count2, 1, 0};

    apply_methods(root2, root2, suggestions2, w2, s2);

    assert(string_list_search(suggestions2, "ga-to", 5) == 1);

    ctree_destroy(ctree2);
    double_list_destroy(suggestions2, 1);

    // Caso 3 : Separar entre 3-4
    CTree ctree3 = ctree_create();
    ctree_add(ctree3, "gat\0");
    ctree_add(ctree3, "o\0");
    TNode *root3 = ctree3;

    int count3 = 0;
    char **suggestions3 = malloc(sizeof(char*) * 2);
    char mod_word3[8];

    Words w3 = {"gato", 4, 0, mod_word3, 4, 0};
    State s3 = {&count3, 1, 0};

    apply_methods(root3, root3, suggestions3, w3, s3);

    assert(string_list_search(suggestions3, "gat-o", 5) == 1);

    ctree_destroy(ctree3);
    double_list_destroy(suggestions3, 2);
}

// Test Check Suggestions
void test_check_suggestions() {
    // Caso 1 : La palabra no se encuentra en el diccionario
    TNode *tnode1 = tnode_create('o', 0);
    int count1 = 0;
    char **suggestions1 = malloc(sizeof(char*) * 1);
    suggestions1[0] = NULL;
    char mod_word1[8];
    Words w1 = {"gato", 4, 4, mod_word1, 4, 4};
    State s1 = {&count1, 1, 0};

    check_suggestion(tnode1, suggestions1, w1, s1);
    assert(suggestions1[0] == NULL);

    tnode_destroy(tnode1);
    double_list_destroy(suggestions1, 1);

    // Caso 2 : La palabra se encuentra en el diccionario
    TNode *tnode2 = tnode_create('o', 1);
    int count2 = 0;
    char **suggestions2 = malloc(sizeof(char*) * 1);
    char mod_word2[8] = "gato\0";
    Words w2 = {"gato", 4, 4, mod_word2, 4, 4};
    State s2 = {&count2, 1, 0};

    check_suggestion(tnode2, suggestions2, w2, s2);
    assert(strcmp(suggestions2[0], "gato") == 0);

    tnode_destroy(tnode2);
    double_list_destroy(suggestions2, 1);

    // Caso 3 : La palabra se encuentra en el diccionario, pero ya esta en la lista de sugerencias
    TNode *tnode3 = tnode_create('o', 1);
    int count3 = 1;
    char **suggestions3 = malloc(sizeof(char*) * 2);
    for(int i = 0; i < 2; i++) suggestions3[i] = NULL;
    suggestions3[0] = malloc(sizeof(char) * 5);
    strcpy(suggestions3[0], "gato\0");
    char mod_word3[8] = "gato\0";
    Words w3 = {"gato", 4, 4, mod_word3, 4, 4};
    State s3 = {&count3, 1, 0};

    check_suggestion(tnode3, suggestions3, w3, s3);
    assert(suggestions3[1] == NULL);

    tnode_destroy(tnode3);
    double_list_destroy(suggestions3, 2);
}

// Test Apply Methods
void test_apply_methods() {
    // Caso 1 : Metodo Intercambiar Caracteres
    CTree ctree1 = ctree_create();
    ctree_add(ctree1, "gtao\0");
    TNode *root1 = ctree1;

    int count1 = 0;
    char **suggestions1 = malloc(sizeof(char*) * 1);
    char mod_word1[8];

    Words w1 = {"gato", 4, 0, mod_word1, 4, 0};
    State s1 = {&count1, 1, 0};

    apply_methods(root1, root1, suggestions1, w1, s1);

    assert(strcmp(suggestions1[0], "gtao") == 0);

    ctree_destroy(ctree1);
    double_list_destroy(suggestions1, 1);

    // Caso 2 : Metodo Agregar Caracter
    CTree ctree2 = ctree_create();
    ctree_add(ctree2, "gaxto\0");
    TNode *root2 = ctree2;

    int count2 = 0;
    char **suggestions2 = malloc(sizeof(char*) * 1);
    char mod_word2[8];

    Words w2 = {"gato", 4, 0, mod_word2, 4, 0};
    State s2 = {&count2, 1, 0};

    apply_methods(root2, root2, suggestions2, w2, s2);

    assert(strcmp(suggestions2[0], "gaxto") == 0);

    ctree_destroy(ctree2);
    double_list_destroy(suggestions2, 1);

    // Caso 3 : Metodo Remover Caracter
    CTree ctree3 = ctree_create();
    ctree_add(ctree3, "gao\0");
    TNode *root3 = ctree3;

    int count3 = 0;
    char **suggestions3 = malloc(sizeof(char*) * 1);
    char mod_word3[8];

    Words w3 = {"gato", 4, 0, mod_word3, 4, 0};
    State s3 = {&count3, 1, 0};

    apply_methods(root3, root3, suggestions3, w3, s3);

    assert(strcmp(suggestions3[0], "gao") == 0);

    ctree_destroy(ctree3);
    double_list_destroy(suggestions3, 1);

    // Caso 4 : Metodo Cambiar Caracter
    CTree ctree4 = ctree_create();
    ctree_add(ctree4, "gaxo\0");
    TNode *root4 = ctree4;

    int count4 = 0;
    char **suggestions4 = malloc(sizeof(char*) * 1);
    char mod_word4[8];

    Words w4 = {"gato", 4, 0, mod_word4, 4, 0};
    State s4 = {&count4, 1, 0};

    apply_methods(root4, root4, suggestions4, w4, s4);

    assert(strcmp(suggestions4[0], "gaxo") == 0);

    ctree_destroy(ctree4);
    double_list_destroy(suggestions4, 1);

    // Caso 5 : Metodo Separar Caracteres
    CTree ctree5 = ctree_create();
    ctree_add(ctree5, "ga\0");
    ctree_add(ctree5, "to\0");
    TNode *root5 = ctree5;

    int count5 = 0;
    char **suggestions5 = malloc(sizeof(char*) * 5);
    char mod_word5[8];

    Words w5 = {"gato", 4, 0, mod_word5, 4, 0};
    State s5 = {&count5, 1, 0};

    apply_methods(root5, root5, suggestions5, w5, s5);

    assert(string_list_search(suggestions5, "ga-to", 5) == 1);

    ctree_destroy(ctree5);
    double_list_destroy(suggestions5, 1);
}

int main() {
    test_exchange_chars();
    test_insert_char();
    test_remove_char();
    test_change_char();
    test_split_word();
    test_apply_methods();
    test_check_suggestions();
    return 0;
}