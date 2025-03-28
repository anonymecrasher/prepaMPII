#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int dist(char u[], char v[]){
  int len_u = strlen(u);
  int len_v = strlen(v);


  int **dist = malloc((len_u + 1) * sizeof(int*));
  for (int i = 0; i <= len_u; i++){
    dist[i] = malloc((len_v + 1) * sizeof(int));
  }

  /*Init*/
  for (int i = 0; i <= len_u; i++){
    dist[i][0] = i;
  }

  for (int j = 0; j <= len_v; j++){
    dist[0][j] = j;
  }


  /*Calcul*/
  for (int i = 1; i <= len_u; i++)
    {
    for (int j = 1; j <= len_v; j++)
      {
      if (u[i-1] == v[j-1])
        {
        dist[i][j] = dist[i-1][j-1];
        }
      else
        {
          int min = dist[i-1][j-1];

          if (dist[i-1][j] < min)
            min = dist[i-1][j];

          if (dist[i][j-1] < min)
            min = dist[i][j-1];

          dist[i][j] = 1 + min;
        }
      }
  }
  int d = dist[len_u][len_v];

  for (int i = 0; i <= len_u; i++){
    free(dist[i]);
  }
  free(dist);
  return d;
}



int main(int argc, char *argv[]){
  dist("aaaa", "abbb");
  //printf("La distance entre %s et %s est %d.\n", argv[1], argv[2], dist(argv[1], argv[2]));
  return EXIT_SUCCESS;
}
