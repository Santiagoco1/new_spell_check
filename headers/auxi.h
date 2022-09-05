#ifndef __AUXI_H__
#define __AUXI_H__

#include <stdio.h>
#include <stdlib.h>

// Double List Destroy : char**, int -> NULL
/*
    * Destruye y borra de memoria una lista de strings
    - list : char** / lista de strings
    - len : int / largo de la lista
*/
void double_list_destroy(char **list, int len);

// Get Ascii : char -> int
/*
    * Devuelve el valor ascii de una letra
    - letter : char / letra a convertir
*/
int get_ascii(char letter);

// string_list_search : char**, char*, int -> int
/*
    * Se fija en una lista de strings, si se encuentra un string en especifico
      Devuelve 1 en el caso que si, 0 en el caso contrario
    - list : char** / lista de strings
    - string : char* / string a buscar
    - length : int / largo de la lista
*/
int string_list_search(char **list, char* string, int length);

#endif