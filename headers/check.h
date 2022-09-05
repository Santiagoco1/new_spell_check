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
    - dictionary : CTree* / arbol de caracteres que representa el diccionario
    - word : char* / palabra a corregir
    - count : int* / cantidad sugerencias encontradas
*/
char **find_suggestions(CTree dictionary, char *word, int *count);

// check_word : char*, int, int, CTree, int -> Corr*
/*
    * Chequea que la palabra se encuentre en el diccionario, en el caso que no crea una nueva correccion y
      empieza la busqueda de las sugerencias posibles en el diccionario representado por el CTree
    - dictionary : CTree / arbol de caracteres que representa el diccionario
    - word : char* / palabra del texto
    - length : int / largo de la palabra
    - line : int / linea del texto donde se ubica la palabra
    - max_length : int / largo de la palabra mas larga
*/
Corr *check_word(CTree dictionary, char *str, int length, int line, int max_length);

// check_text : char*, dictionary, max_length -> CList*
/*
    * Va separando las palabras del texto, ignorando ciertos caracteres en especifico 
      mientras va guardando las correcciones de las palabras invalidas
    - dictionary : CTree / arbol de caracteres que representa el diccionario
    - path : char* / direccion del archivo donde se haya el texto
    - max_length : int / largo de la palabra mas larga
*/
CList *check_text(CTree dictionary, char *path, int max_length);

#endif