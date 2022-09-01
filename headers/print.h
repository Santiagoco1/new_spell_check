#ifndef __PRINT_H__
#define __PRINT_H__

#include "list.h"
#include "corr.h"

// print_text : CList*, char* -> NULL
/*
    * Crea un archivo de salida e imprime en el mismo las correcciones obtenidas del texto
    - corrections : CList* / lista de correcciones del texto
    - path : char* / dirreccion del archivo con el archivo del texto a corregir 
*/
void print_text(CList *corrections, char *path);

#endif