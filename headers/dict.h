#ifndef __DICT_H__
#define __DICT_H__

#include "ctree.h"

// get_cupboard : char*, int*, int* -> char**
/*
    * Devuelve en una lista de strings todas las palabras encontradas en un lemario,
    ademas de definir la cantidad de palabras y el largo de la palabra mas larga
    - path : char* / direccion del archivo donde esta el lemario
    - amount : int* / direccion de memoria de la variable que guarda la cantidad de palabras del lemario
    - max_length : int* /  direccion de memoria de la variable que guarda el largo de la palabra mas larga
*/
char **get_cupboard(char *path, int *amount, int *max_length);

// get_dictionary : char**, int -> CTree
/*
    * Arma un diccionario, osea un arbol de carateres con el lemario pasado
    - cupboard : char** / lemario de palabras
    - amount : int / cantidad de palabras del lemario
*/
CTree get_dictionary(char **cupboard, int amount);

#endif