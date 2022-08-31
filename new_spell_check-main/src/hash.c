#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/hash.h"

HashTable *hashtable_create(int size) {

  HashTable *hashtable = malloc(sizeof(HashTable));
  hashtable->list = malloc(sizeof(CList*) * size);

  for(int i = 0; i < size; i++) {
    hashtable->list[i] = NULL;
  }
  hashtable->size = size;
  hashtable->amount = 0;

  return hashtable;
}

int hash_function (char *word, int size) {
  unsigned hashval;
  for (hashval = 0; *word != '\0'; ++word) {
    hashval = *word + 31 * hashval;
  }
  return hashval % size;
}

void hashtable_add (HashTable *hashtable, Corr *correction, int hash) {
  hashtable->list[hash] = add_node(hashtable->list[hash], correction);
  hashtable->amount += 1;
}

int hashtable_search(HashTable *hashtable, Corr *correction) {
  int hash = hash_function(correction->word, hashtable->size);
  if(clist_search(hashtable->list[hash], correction)) return hash;
  else return -1;
}

void hashtable_destroy(HashTable *hashTable) {
  for(int i = 0; i < hashTable->size; i++) {
    CList *list = hashTable->list[i];
    clist_destroy(list);
  }
  free(hashTable -> list);
  free(hashTable);
}   