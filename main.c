#include <stdio.h>
#include <stdlib.h>
#include "headers/list.h"
#include "headers/dict.h"
#include "headers/check.h"
#include "headers/print.h"

// Main : int, char** -> int
/*
  * Funcion principal del programa
    Corrige los errores ortograficos de un texto a partir
    de un diccionaro dado y los imprime en un archivo de salida
    - argc : int / cantidad de argumentos de entrada
    - argv : char** / argumentos de entrada
*/
int main(int argc, char **argv ) {
  // Primero nos fijamos si tenemos todos los argumentos necesarios
  if(argc == 4) {
    // Definimos las variables necesarias
    // - amount : cantidad final de palabras del lemario
    // - max_length : largo maximo final de las palabras del lemario
    int amount = 0, max_length = 0;
    
    // Obtenemos el lemario pasado en el primer argumento
    char **cupboard = get_cupboard(argv[1], &amount, &max_length);

    // Creamos un ctree con las palabras del lemario
    CTree dictionary = get_dictionary(cupboard, amount);
    free(cupboard);

    // Realizamos las correcciones necesarias en el texto dado por el
    // segundo argumento, utilizando el ctree ya creado
    CList *corrections = check_text(dictionary, argv[2], max_length);
    ctree_destroy(dictionary);

    // Imprimimos en un archivo de salida las correcciones hechas
    print_text(corrections, argv[3]);
    free(corrections);

  } else {
    printf("Cantidad incorrecta de argumentos");
  }
  return 0;
}