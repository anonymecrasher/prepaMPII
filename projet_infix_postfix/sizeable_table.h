#ifndef SIZEABLE_TABLE
#define SIZEABLE_TABLE

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char **data;
    size_t size; // ici size_t est un entier
} size_a_t;

size_a_t *SIZEABLE_TABLE_init_str(void);
bool SIZEABLE_TABLE_is_empty(size_a_t *s);
void SIZEABLE_TABLE_realoc(size_a_t *s);
void SIZEABLE_TABLE_free(size_a_t *s);

#endif
