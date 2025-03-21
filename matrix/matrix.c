#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void main(void){

  int n = 10;
  int **matrix = malloc(n * sizeof(int *));
  for (int i = 0 ; i < n ; i++) {
    matrix[i] = malloc(n * sizeof(int));
  }
  for (int i = 0; i < n * n; i++){
    matrix[i/n][i%n] = i;
  }
  for (int i = 0; i < n ; i++){
    printf("| ");
    for (int y = 0; y < n ; y++){
      printf(" %d ", matrix[i][y]);
    }
    printf(" |\n");
  }
  
}
