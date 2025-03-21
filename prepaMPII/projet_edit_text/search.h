#ifndef SEARCH_H
#define SEARCH_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/*int strlen(char *factor);*/
int **construct_table(char *factor);
int gap(int **tab,int pos_c,int c);
int compare_texte_motif(char *word, char *factor, int position);
int first_occurence(int start, int end, char *word, char *factor);
void main(void);

#endif
