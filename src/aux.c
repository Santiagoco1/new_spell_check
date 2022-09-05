#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/aux.h"

// Valor ascii del caracter 'a'
#define ASCII_A 97

void double_list_destroy(char **list, int len) {
    for(int i = 0; i < len; i++) {
       if(list[i]) free(list[i]);
    }
    free(list);
}

int get_ascii(char letter) {
    return (int)letter-ASCII_A;
}

int string_list_search(char **list, char* string, int length) {
  // Busco de forma iterativa si el elemento pertenece a la lista
  for(int i = 0; i < length; i++) {
    if(strcmp(list[i], string) == 0) return 1;
  }
  return 0;
}