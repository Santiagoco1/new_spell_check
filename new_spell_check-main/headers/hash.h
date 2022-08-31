#ifndef __HASH_H__
#define __HASH_H__

#include "corr.h"
#include "list.h"

typedef struct _HashTable {
  CList **list;
  int size;
  int amount;
} HashTable;

HashTable *hashtable_create(int size);

int hash_function(char *word, int size);

void hashtable_add(HashTable *dictionary, Corr *word, int hash);

int hashtable_search(HashTable *hashtable, Corr *correction);

// hashtable_destroy
void hashtable_destroy(HashTable *hashtable);

#endif