#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../headers/corr.h"

// Test Corr Create
void test_corr_create() {
    char **suggestions = malloc(sizeof(char*) * 5);
    suggestions[0] = malloc(sizeof(char) * 4);
    strcpy(suggestions[0], "cas\0");
    suggestions[1] = malloc(sizeof(char) * 5);
    strcpy(suggestions[1] , "case\0");
    suggestions[2] = malloc(sizeof(char) * 5);
    strcpy(suggestions[2], "caas\0");
    suggestions[3] = NULL;
    suggestions[4] = NULL;

    Corr *corr = corr_create("casa", 1, 3, suggestions);

    assert(strcmp(corr->word, "casa") == 0);
    assert(corr->line == 1);
    assert(corr->count == 3);
    assert(strcmp(corr->suggs[0], "cas") == 0);
    assert(strcmp(corr->suggs[1], "case") == 0);
    assert(strcmp(corr->suggs[2], "caas") == 0);

    corr_destroy(corr);
}

int main() {
    test_corr_create();
    return 0;
}