#ifndef __CORR_H__
#define __CORR_H__

typedef struct _Corr {
  char *word;
  int line;
  int count;
  char **suggs;
} Corr;

Corr *corr_create(char *str, int line, int count, char **suggestions);

void corr_fprintf(Corr *correction, FILE *path);

void corr_destroy(Corr *correction);

#endif