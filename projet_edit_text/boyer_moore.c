#include "search.h"
#include "table.h"

int **BOYER_MOORE_H_construct_table(char *factor){
  int n = strlen(factor);
  int **tab = malloc(n * sizeof(int *));
  for (int i = 0; i < n ; i++){
    tab[i] = malloc(256 * sizeof(int));
  }
  for (int c = 0; c < 256; c++){
    if ((unsigned char) factor[0] == c){
      tab[0][c] = 0;
    }
    else tab[0][c] = 1;
  }
  for (int i = 1; i < n ; i = i + 1){
    for (int c = 0; c < 256; c++){
      if ((unsigned char) factor[i] == c) tab[i][c] = 0;
      else tab[i][c] = tab[i-1][c] + 1 ;
    }
  }
  return tab;
}

int BOYER_MOORE_H_gap(int **tab, int pos_c, int c){
  return tab[pos_c][(unsigned char) c];
}

int BOYER_MOORE_H_compare_texte_motif(char *word, char *factor, int position){
  for (int j = strlen(factor)-1; j >= 0 && position + j < strlen(word); j--){
    if ((word[j + position] != factor[j])) return j ;
  return -1;
  }
}

int *BOYER_MOORE_H_occurence(int starte, int end, char *word, char *factor){
  int i = starte;
  int **tab = construct_table(factor);
  int *ret;
  TABLEAU_H_init_tableau(ret, 100);
  while ( i + strlen(factor) < end){
    int j = compare_texte_motif(word, factor,i);
    if (j == -1) TABLEAU_H_ajouter_element(ret, i);
    else
      if (i + j > strlen(word)) return ret;
    i = i + gap(tab, j, word[i+j]);
    printf(" %d \n", i);
  }
  return ret;
}



