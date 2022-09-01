#ifndef __CORR_H__
#define __CORR_H__

typedef struct _Corr {
  char *word;
  int line;
  int count;
  char **suggs;
} Corr;

// corr_create : char*, int, int, char** -> Corr*
/*
  * Crea y guarda en memoria un nuevo Corr con los datos pasados
  - str : char* / palabra a corregir
  - line : int / linea del texto donde se ubica la palabra
  - count : int / cantidad sugerencias encontradas
  - suggestions : char** / lista de sugerencias encontradas para la palabra
*/
Corr *corr_create(char *str, int line, int count, char **suggestions);

// corr_fprintf : Corr*, FILE* -> NULL
/*
  * Guarda en un archivo la correccion pasada
  - correction : Corr* / correccion de una palabra invalida
  - path : FILE* / archivo donde guardar la correccion
*/
void corr_fprintf(Corr *correction, FILE *path);

// corr_destroy : Corr* -> NULL
/*
  * Destrute y borra de memoria una correccion
  - correction : Corr* / correccion a destruir
*/
void corr_destroy(Corr *correction);

#endif