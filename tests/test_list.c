#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../headers/list.h"
#include "../headers/corr.h"

// Test CList Create
void test_clist_create() {
    CList *clist = clist_create();
    assert(clist->first == NULL);
    assert(clist->last == NULL);
    
    clist_destroy(clist);
}

// Test CNode Create
void test_cnode_create() {
    char **suggestions = malloc(sizeof(char*) * 5);
    suggestions[0] = malloc(sizeof(char) * 4);
    strcpy(suggestions[0], "cas\0");
    suggestions[1] = malloc(sizeof(char) * 5);
    strcpy(suggestions[1], "case\0");
    suggestions[2] = malloc(sizeof(char) * 5);
    strcpy(suggestions[2], "caas\0");
    suggestions[3] = NULL;
    suggestions[4] = NULL;
    Corr *corr = corr_create("casa", 1, 3, suggestions);
    
    CNode *cnode = cnode_create(corr);
    assert(strcmp(cnode->correction->word, "casa") == 0);
    assert(cnode->correction->line == 1);
    assert(cnode->correction->count == 3);
    assert(strcmp(cnode->correction->suggs[0], "cas") == 0);
    assert(strcmp(cnode->correction->suggs[1], "case") == 0);
    assert(strcmp(cnode->correction->suggs[2], "caas") == 0);
    assert(cnode->next == NULL);

    cnode_destroy(cnode);
}

// Test CList Add Last
void test_clist_add_last() {
    CList *clist = clist_create();

    char **suggestions1 = malloc(sizeof(char*) * 5);
    suggestions1[0] = malloc(sizeof(char) * 4);
    strcpy(suggestions1[0], "cas\0");
    suggestions1[1] = malloc(sizeof(char) * 5);
    strcpy(suggestions1[1], "case\0");
    suggestions1[2] = malloc(sizeof(char) * 5);
    strcpy(suggestions1[2], "caas\0");
    suggestions1[3] = NULL;
    suggestions1[4] = NULL;

    char **suggestions2 = malloc(sizeof(char*) * 5);
    suggestions2[0] = malloc(sizeof(char) * 5);
    strcpy(suggestions2[0], "perr\0");
    suggestions2[1] = NULL;
    suggestions2[2] = NULL;
    suggestions2[3] = NULL;
    suggestions2[4] = NULL;

    char **suggestions3 = malloc(sizeof(char*) * 5);
    suggestions3[0] = malloc(sizeof(char) * 4);
    strcpy(suggestions3[0], "gat\0");
    suggestions3[1] = malloc(sizeof(char) * 5);
    strcpy(suggestions3[1], "gate\0");
    suggestions3[2] = NULL;
    suggestions3[3] = NULL;
    suggestions3[4] = NULL;

    Corr *corr1 = corr_create("casa", 1, 3, suggestions1);
    Corr *corr2 = corr_create("perro", 2, 1, suggestions2);
    Corr *corr3 = corr_create("gato", 3, 2, suggestions3);

    clist_add_last(clist, corr1);
    clist_add_last(clist, corr2);
    clist_add_last(clist, corr3);

    CNode* cnode = clist->first;
    assert(strcmp(cnode->correction->word, "casa") == 0);
    assert(cnode->correction->line == 1);
    assert(cnode->correction->count == 3);
    assert(strcmp(cnode->correction->suggs[0], "cas") == 0);
    assert(strcmp(cnode->correction->suggs[1], "case") == 0);
    assert(strcmp(cnode->correction->suggs[2], "caas") == 0);

    cnode = cnode->next;
    assert(strcmp(cnode->correction->word, "perro") == 0);
    assert(cnode->correction->line == 2);
    assert(cnode->correction->count == 1);
    assert(strcmp(cnode->correction->suggs[0], "perr") == 0);

    cnode = cnode->next;
    assert(strcmp(cnode->correction->word, "gato") == 0);
    assert(cnode->correction->line == 3);
    assert(cnode->correction->count == 2);
    assert(strcmp(cnode->correction->suggs[0], "gat") == 0);
    assert(strcmp(cnode->correction->suggs[1], "gate") == 0);

    assert(cnode->next == NULL);

    clist_destroy(clist);
}

// Test CNode pass
void test_cnode_pass() {
    CList *clist = clist_create();

    char **suggestions1 = malloc(sizeof(char*) * 5);
    suggestions1[0] = malloc(sizeof(char) * 4);
    strcpy(suggestions1[0], "cas\0");
    suggestions1[1] = malloc(sizeof(char) * 5);
    strcpy(suggestions1[1] , "case\0");
    suggestions1[2] = malloc(sizeof(char) * 5);
    strcpy(suggestions1[2], "caas\0");
    suggestions1[3] = NULL;
    suggestions1[4] = NULL;

    char **suggestions2 = malloc(sizeof(char*) * 5);
    suggestions2[0] = malloc(sizeof(char) * 5);
    strcpy(suggestions2[0], "perr\0");
    suggestions2[1] = NULL;
    suggestions2[2] = NULL;
    suggestions2[3] = NULL;
    suggestions2[4] = NULL;

    Corr *corr1 = corr_create("casa", 1, 3, suggestions1);
    Corr *corr2 = corr_create("perro", 2, 1, suggestions2);

    clist_add_last(clist, corr1);
    clist_add_last(clist, corr2);

    CNode *cnode = clist->first;
    cnode = cnode_pass(cnode);

    assert(strcmp(cnode->correction->word, "perro") == 0);
    assert(cnode->correction->line == 2);
    assert(cnode->correction->count == 1);
    assert(strcmp(cnode->correction->suggs[0], "perr") == 0);

    cnode_destroy(cnode);
    free(clist);
}

int main() {
    test_clist_create();
    test_cnode_create();
    test_clist_add_last();
    test_cnode_pass();
    return 0;
}