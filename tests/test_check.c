#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../headers/check.h"
#include "../headers/aux.h"

// Test Find Suggestions
void test_find_suggestions() {
    // Caso 1: palabras con paso 1
    CTree ctree1 = ctree_create();
    ctree_add(ctree1, "gat\0");
    ctree_add(ctree1, "gate\0");
    ctree_add(ctree1, "ga\0");
    ctree_add(ctree1, "to\0");
    ctree_add(ctree1, "gaot\0");
    ctree_add(ctree1, "gatos\0");

    int count1 = 0;
    char **suggestions1 = find_suggestions(ctree1, "gato", &count1);

    assert(string_list_search(suggestions1, "gat", 5) == 1);
    assert(string_list_search(suggestions1, "gate", 5) == 1);
    assert(string_list_search(suggestions1, "ga-to", 5) == 1);
    assert(string_list_search(suggestions1, "gaot", 5) == 1);
    assert(string_list_search(suggestions1, "gatos", 5) == 1);

    ctree_destroy(ctree1);
    double_list_destroy(suggestions1, 5);

    // Caso 2: palabras con paso 2
    CTree ctree2 = ctree_create();
    ctree_add(ctree2, "get");
    ctree_add(ctree2, "gatose");
    ctree_add(ctree2, "g");
    ctree_add(ctree2, "atos");
    ctree_add(ctree2, "gota");
    
    int count2 = 0;
    char **suggestions2 = find_suggestions(ctree2, "gato", &count2);

    assert(string_list_search(suggestions2, "get", 5) == 1);
    assert(string_list_search(suggestions2, "gatose", 5) == 1);
    assert(string_list_search(suggestions2, "atos", 5) == 1);
    assert(string_list_search(suggestions2, "g-atos", 5) == 1);
    assert(string_list_search(suggestions2, "gota", 5) == 1);

    ctree_destroy(ctree2);
    double_list_destroy(suggestions2, 5);

    // Caso 3: palabras con paso 3
    CTree ctree3 = ctree_create();
    ctree_add(ctree3, "ges");
    ctree_add(ctree3, "gataaa");
    ctree_add(ctree3, "gt");
    ctree_add(ctree3, "agtose");
    ctree_add(ctree3, "ate");
    
    int count3 = 0;
    char **suggestions3 = find_suggestions(ctree3, "gato", &count3);

    assert(string_list_search(suggestions3, "ges", 5) == 1);
    assert(string_list_search(suggestions3, "gataaa", 5) == 1);
    assert(string_list_search(suggestions3, "gt", 5) == 1);
    assert(string_list_search(suggestions3, "ate", 5) == 1);
    assert(string_list_search(suggestions3, "gt-ate", 5) == 1);

    ctree_destroy(ctree3);
    double_list_destroy(suggestions3, 5);

    // Caso 4: palabras con pasos diferentes
    CTree ctree4 = ctree_create();
    ctree_add(ctree4, "get");
    ctree_add(ctree4, "g");
    ctree_add(ctree4, "atos");
    ctree_add(ctree4, "gate");
    ctree_add(ctree4, "gtas");

    int count4 = 0;
    char **suggestions4 = find_suggestions(ctree4, "gato", &count4);

    assert(string_list_search(suggestions4, "get", 5) == 1);
    assert(string_list_search(suggestions4, "g-atos", 5) == 1);
    assert(string_list_search(suggestions4, "atos", 5) == 1);
    assert(string_list_search(suggestions4, "gate", 5) == 1);
    assert(string_list_search(suggestions4, "gtas", 5) == 1);

    ctree_destroy(ctree4);
    double_list_destroy(suggestions4, 5);

    // Caso 5 : palabra sin sugerencias posibles
    CTree ctree5 = ctree_create();
    ctree_add(ctree5, "cas");
    ctree_add(ctree5, "case");
    ctree_add(ctree5, "ca");
    ctree_add(ctree5, "sa");
    ctree_add(ctree5, "caas");
    ctree_add(ctree5, "casas");
    
    int count5 = 0;
    char **suggestions5 = find_suggestions(ctree5, "asipiising", &count5);

    assert(suggestions5 == NULL);

    ctree_destroy(ctree5);
    free(suggestions5);
}

// Test Check Word
void test_check_word() {
    CTree ctree = ctree_create();
    ctree_add(ctree, "cas");
    ctree_add(ctree, "case");
    ctree_add(ctree, "ca");
    ctree_add(ctree, "sa");
    ctree_add(ctree, "caas");
    ctree_add(ctree, "casas");

    // Caso 1 : palabra no encontrada en el diccionario
    Corr *corr1 = check_word(ctree, "casa", 4, 1, 5);

    assert(strcmp(corr1->word, "casa") == 0);
    assert(corr1->line == 1);
    assert(corr1->count == 5);
    assert(string_list_search(corr1->suggs, "cas", 5) == 1);
    assert(string_list_search(corr1->suggs, "case", 5) == 1);
    assert(string_list_search(corr1->suggs, "ca-sa", 5) == 1);
    assert(string_list_search(corr1->suggs, "caas", 5) == 1);
    assert(string_list_search(corr1->suggs, "casas", 5) == 1);

    corr_destroy(corr1);

    // Caso 2 : palabra no encontrada en el diccionario pero sin sugerencias posibles
    Corr *corr2 = check_word(ctree, "adiipising", 10, 1, 10);
    
    assert(strcmp(corr2->word, "adiipising") == 0);
    assert(corr2->line == 1);
    assert(corr2->count == 0);
    assert(corr2->suggs == NULL);

    corr_destroy(corr2);
    
    // Caso 3 : palabra mas larga que el largo maximo
    Corr *corr3 = check_word(ctree, "murcielago", 10, 1, 5);
    assert(strcmp(corr3->word, "murcielago") == 0);
    assert(corr3->line == 1);
    assert(corr3->count == 0);
    assert(corr3->suggs == NULL);

    corr_destroy(corr3);

    // Caso 4 : palabra ubicada en el diccionario
    Corr *corr4 = check_word(ctree, "caas", 4, 1, 5);
    assert(corr4 == NULL);

    ctree_destroy(ctree);
}

int main() {
    test_find_suggestions();
    test_check_word();
    return 0;
}