#ifndef __CHECK_H__
#define __CHECK_H__

#include "ctree.h"
#include "corr.h"
#include "list.h"
#include "metd.h"

// find_suggestions : char*, int*, CTree -> char**
/*
    * Se le pasa una palabra a corregir, y busca las cinco sugerencias con menor cantidad de pasos
      utilizando un algoritmo que recorre el diccionario representado por el CTree
    - word : char* / palabra a corregir
    - count : int* / cantidad sugerencias encontradas
    - dictionary : CTree* / arbol de caracteres que representa el diccionario
*/
char **find_suggestions(char *word, int *count, CTree dictionary);

// check_word : char*, int, int, CTree, int -> Corr*
/*
    * Chequea que la palabra se encuentre en el diccionario, en el caso que no
      empieza la busqueda de las sugerencias posibles en el diccionario representado por el CTree
    - word : char* / palabra del texto
    - length : int / largo de la palabra
    - line : int / linea del texto donde se ubica la palabra
    - dictionary : CTree / arbol de caracteres que representa el diccionario
    - max_length : int / largo de la palabra mas larga
*/
Corr *check_word(char *str, int length, int line, CTree dictionary, int max_length);

// check_text : char*, dictionary, max_length -> CList*
/*
    * Va separando las palabras del texto, ignorando ciertos caracteres en especifico
      va guardando las correcciones de las palabras invalidas
    - path : char* / direccion del archivo donde se haya el texto
    - dictionary : CTree / arbol de caracteres que representa el diccionario
    - max_length : int / largo de la palabra mas larga
*/
CList *check_text(char *path, CTree dictionary, int max_length);

#endif