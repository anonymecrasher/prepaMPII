#ifndef BOYER_MOORE_H
#define BOYER_MOORE_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "table.h"

/*int strlen(char *factor);*/
int **BOYER_MOORE_H_construct_table(char *factor);
int BOYER_MOORE_H_gap(int **tab,int pos_c,int c);
int BOYER_MOORE_H_compare_texte_motif(char *word, char *factor, int position);
int *BOYER_MOORE_H_occurence(int start, int end, char *word, char *factor);

#endif
