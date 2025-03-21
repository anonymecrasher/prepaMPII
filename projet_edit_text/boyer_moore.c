#include "search.h"

int **construct_table(char *factor){
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

int gap(int **tab, int pos_c, int c){
  printf("/n %c /n",(unsigned char) c);
  return tab[pos_c][(unsigned char) c];
}

int compare_texte_motif(char *word, char *factor, int position){
  for (int j = strlen(factor)-1; j >= 0 && position + j < strlen(word); j--){
    if ((word[j + position] != factor[j])) return j ;
  return -1;
  }
}

int first_occurence(int starte, int end, char *word, char *factor){
  int i = starte;
  int **tab = construct_table(factor);
  while ( i + strlen(factor) < end){
    int j = compare_texte_motif(word, factor,i);
    if (j == -1) return i;
    
    else  printf(" %d \n", i); if (i + j > strlen(word)) return -1; i = i + gap(tab, j, word[i+j]);
    printf(" %d \n", i);
  }
  return -1;
}

void main(void){
  int **tab = construct_table("aab");

  for (int i = 0; i < strlen("aab") ; i++){
    for (int c = 0 ; c < 256 ; c++){
      printf(" %c ", tab[i][c]);
    }
    printf("\n");
  }

  for (int i = 0; i < 5; i++){
    printf("\n");
  }


  for (int i = 0; i < 5; i++){
    printf("\n");
  }

  printf(" %d ", first_occurence(0, strlen("aaaaaaaaaaaaaaaaaaabonjour je m'appel mathiasftyjseehrmifmucdhjcv bnhvecchjvkcvryeuvce86765.2138634") - 1 , "aaaaaaaaaaaaaaaaaaabonjour je m'appel mathiasftyjseehrmifmucdhjcv bnhvecchjvkcvryeuvce86765.213863", "aab"));

  for (int i = 0; i <  strlen("aab"); i++){
    free(tab[i]);
  }
  free(tab);
}

