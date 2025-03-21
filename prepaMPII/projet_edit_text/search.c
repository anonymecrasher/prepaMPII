#include "search.h"

/* int strlen(char *factor){
  int i = 0;
  while (factor[i] != '\0'){
    i++;
    }
  return --i;
} */

int **construct_table(char *factor){
  int n = (strlen(factor));
  int **tab = malloc((n) * sizeof(int *));
  for (int i = 0; i < n ; i = i + 1){
    tab[i] = malloc(256 * sizeof(int));
  }

  for (int c = 0; c < 256; c = c + 1){
    if ((char) c == factor[0]) tab[0][c] = 0;
    else tab[0][c] = 1;
  }
  for (int i = 0 ; i < n; i++){
    for (int c = 0 ; c < 256; c++){
       if ((char) c == factor[0]) tab[i][c] = 0;
       else tab[i][c] = tab[i-1][c] + 1;
    }
  }

  return tab;
}


int gap(int **tab , int c , int pos_c){
  return tab[pos_c][c];
}

int compare_texte_motif(char *word, char *factor, int position){
  int i = strlen(factor);
  bool flag = true;
  while (i > 0 && flag && (i + position) < strlen(factor)){
    flag = (word[position + i - 1 ] == factor[i-1]);
    i--;
  if (!(flag))
    return i;
  return -1;
  }
}


int first_occurence(int start, int end, char *word, char *factor){
  int **tab = construct_table(factor);
  int i = 0;
  int n = strlen(factor);
  while (start + i + n < end){
    int result_temp = compare_texte_motif(word, factor, start + i);
    if (result_temp == -1) return i;
    else {
      int dis = gap(tab , (unsigned char) word[i+result_temp] , result_temp);
      i = i + dis;
    }
  }
  return -1;
}


void main(void){
  char *word = "Les chaussettes de l'archiduchesse sont-elles seches archisèches.";
  char *factor = "seches";
  printf("%d\n", first_occurence(0, strlen(word)-1 ,word,factor));
}
