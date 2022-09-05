#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/metd.h"

void null_method(TNode *root, TNode *node, char **suggestions, Words w, State s) {
  int letter_ascii = get_ascii(w.word[w.pos]);
  // Primero me fijo si puedo seguir avanzando por el arbol, con el siguiente caracter de la palabra original
  if(node->sons[letter_ascii]) {
    // Guardo el caracter original
    w.word_mod[w.pos_mod] = w.word[w.pos];
    TNode *next_node = node->sons[letter_ascii];
    // Modifico todas las variables necesarias
    w.pos++;
    w.pos_mod++;
    // Vuelvo a llamar recursivamente a la funcion principal
    apply_methods(root, next_node, suggestions, w, s);
    // Borro con el terminador el caracter que agregue
    w.word_mod[w.pos_mod-1] = '\0';
  }
}

void exchange_chars(TNode *root, TNode *node, char **suggestions, Words w, State s) {
  int first_letter_ascii = get_ascii(w.word[w.pos]);
  int second_letter_ascii = get_ascii(w.word[w.pos+1]);
  // Solamente realizo la modificacion si al intercambiar los caracteres, puedo seguir avanzando por el arbol
  if(node->sons[second_letter_ascii] && node->sons[second_letter_ascii]->sons[first_letter_ascii]) {
    // Realizo las modificiones
    w.word_mod[w.pos_mod] = w.word[w.pos+1];
    w.word_mod[w.pos_mod+1] = w.word[w.pos];
    TNode *next_node = node->sons[second_letter_ascii]->sons[first_letter_ascii];
    // Modifico todas las variables necesarias
    w.pos += 2;
    w.pos_mod += 2;
    s.steps--;
    // Vuelvo a llamar recursivamente a la funcion principal
    apply_methods(root, next_node, suggestions, w, s);
    // Borro con el terminador, las modificaciones que realice
    w.word_mod[w.pos_mod-1] = '\0';
    w.word_mod[w.pos_mod-2] = '\0';
  }
}

void insert_char(TNode *root, TNode *node, char **suggestions, Words w, State s) {
  // Modifico todas las variables necesarias
  w.len_mod++;
  w.pos_mod++;
  s.steps--;
  // Itero sobre cada una los posibles caracteres por los cuales puede avanzar
  for(int i = 0; i < 26; i++) {
    if(node->sons[i]) {
      // Realizo las modificiones
      TNode *next_node = node->sons[i];
      w.word_mod[w.pos_mod-1] = next_node->data;
      // Vuelvo a llamar recursivamente a la funcion principal
      apply_methods(root, next_node, suggestions, w, s);
      // Borro con el terminador, la modificacion que realice
      w.word_mod[w.pos_mod-1] = '\0';
    }
  }
}

void remove_char(TNode *root, TNode *node, char **suggestions, Words w, State s) {
  // Modifico todas las variables necesarias
  w.pos++;
  w.len_mod--;
  s.steps--;
  // Al avanzar sobre la palabra orginal, la modificaion se realiza al ya no tener en cuenta el caracter anterior
  // Vuelvo a llamar recursivamente a la funcion principal
  apply_methods(root, node, suggestions, w, s);
}

void change_char(TNode *root, TNode *node, char **suggestions, Words w, State s) {
  int letter_ascii = get_ascii(w.word[w.pos]);
  // Modifico todas las variables necesarias
  w.pos++;
  w.pos_mod++;
  s.steps--;
  // Itero sobre cada una los posibles caracteres por los cuales puede avanzar, menos el original
  for(int i = 0; i < 26; i++) {
    if(i != letter_ascii && node->sons[i]) {
      // Realizo las modificiones
      TNode *next_node = node->sons[i];
      w.word_mod[w.pos_mod-1] = next_node->data;
      // Vuelvo a llamar recursivamente a la funcion principal
      apply_methods(root, next_node, suggestions, w, s);
      // Borro con el terminador, la modificacion que realice
      w.word_mod[w.pos_mod-1] = '\0';
    }
  }
}

void split_word(TNode *root, TNode *node, char **suggestions, Words w, State s) {
  // Primero me fijo si en el nodo actual termina una palabra del diccionario
  if(node->last) {
    // En el caso que si, guardo un '-' en la palabra modificada para representar la separacion
    w.word_mod[w.pos_mod] = '-';
    // Modifico todas las variables necesarias
    w.pos_mod++;
    w.len_mod++;
    s.steps--;
    s.splited = 1;
    // Vuelvo a llamar recursivamente a la funcion principal
    apply_methods(root, root, suggestions, w, s);
    // Borro con el terminador, la modificacion que realice
    w.word_mod[w.pos_mod-1] = '\0';
  }
}

void check_suggestion(TNode *node, char **suggestions, Words w, State s) {
  // Agrego el terminador al final en el caso que no lo tenga
  w.word_mod[w.pos_mod] = '\0';
  // Me fijo si en el nodo actual termina una palabra del diccionario
  // y si la sugerencia que voy a guardar ya no ha sido guardada con anterioridad
  if(node->last && !string_list_search(suggestions, w.word_mod, (*s.count))) {
    // Guardo la nueva sugerencia
    suggestions[(*s.count)] = malloc(sizeof(char) * w.len_mod+1);
    strcpy(suggestions[(*s.count)], w.word_mod);
    (*s.count)++;
  }
}

void apply_methods(TNode *root, TNode *node, char **suggestions, Words w, State s) {
  // Primero me fijo si ya encontre todas las sugerencias
  if((*s.count) < 5) {
    // Despues chequeo que me encuentre al final de la palabra original, osea ya no hay mas caracteres que agregar de la palabra original
    if(w.pos == w.len) {
      // Luego me fijo si ya realice todas las modificaciones
      if(s.steps > 0) {
        // En el caso que no, realizo la unica posible, agregar una letra al final
        insert_char(root, node, suggestions, w, s);
      } else {
        // En caso que si, chequeo la palabra modificada creada
        check_suggestion(node, suggestions, w, s);
      }
    } else {
      // En el caso que todavia no haya llegado al final de la palabra, realizo todas las modificiones posibles restantes
      // El metodo nulo siempre se realiza por default, y no cuenta como modificacion
      null_method(root, node, suggestions, w, s);
      // En el caso que todavia no haya hecho todas las modificaciones posibles, sigo realizando mas
      if(s.steps > 0) {
        // Intercambio caracteres en el caso que no este en el ultimo caracter de la palabra
        if(w.pos+1 != w.len) exchange_chars(root, node, suggestions, w, s);
        remove_char(root, node, suggestions, w, s);
        // Solamente separo la palabra si no estoy en el primer o ultimo caracter y si no la separe todavia
        if(s.splited == 0 && w.pos > 0 && w.pos < w.len) split_word(root, node, suggestions, w, s);
        insert_char(root, node, suggestions, w, s);
        change_char(root, node, suggestions, w, s);
      } 
    }
  }
}