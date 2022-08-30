#ifndef __DICT_H__
#define __DICT_H__

#include "ctree.h"

char **get_words(char *path, int *amount, int *lengths);

CTree get_dictionary(char **words, int amount);

#endif