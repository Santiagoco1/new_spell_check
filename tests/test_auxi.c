#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../headers/auxi.h"

// String List Search
void test_string_list_search() {
    
    int len = 3;
    char **list = malloc(sizeof(char*) * len);
    list[0] = malloc(sizeof(char) * 5);
    strcpy(list[0], "casa\0");
    list[1] = malloc(sizeof(char) * 6);
    strcpy(list[1], "perro\0");
    list[2] = malloc(sizeof(char) * 5);
    strcpy(list[2], "gato\0");
    
    // Caso 1 : se encuentra la palabra
    char *string1 = "casa";
    assert(string_list_search(list, string1, len) == 1);

    // Caso 2 : no se encuentra la palabra
    char *string2 = "dedo";
    assert(string_list_search(list, string2, len) == 0);

    double_list_destroy(list, len);
}

// Get Ascii
// ** Decidí no hacer un test, debido a la simpleza del código **

int main() {
    test_string_list_search();
    return 0;
}