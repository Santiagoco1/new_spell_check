#ifndef __HASH_H__
#define __HASH_H__

#include "coor.h"
#include "list.h"

typedef struct _HashTable {
  CList **list;
  int size;
} HashTable;

HashTable *hashtable_create(int size);

int hash_function(char *word, int amount);

void hashtable_add(HashTable *dictionary, Corr *word);

void search_and_add(HashTable *words_table, Glist *words, Word *word);

int search_hashtable(char *word, HashTable *dictionary);

void free_hashtable(HashTable *hashTable);

#endif