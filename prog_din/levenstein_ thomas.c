
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


int dist(char u[], char v[])
{
  int len_u = strlen(u);
  int len_v = strlen(v);
  
  int** dist = malloc((len_u + 1) * sizeof(int*));
  for (int i = 0; i <= len_u; i += 1)
    dist[i] = malloc((len_v + 1) * sizeof(int));

  /* Initialisation */
  for (int i = 0; i <= len_u; i += 1)
    dist[i][0] = i;

  for (int j = 0; j <= len_v; j += 1)
    dist[0][j] = j;


  /* Calcul */
  for (int i = 1; i <= len_u; i += 1)
  {
    for (int j = 1; j <= len_v; j += 1)
    {
      if (u[i - 1] == v[j - 1]) 
      {
        dist[i][j] = dist[i - 1][j - 1];
      }
      else
      {
        int min = dist[i - 1][j - 1];

        if (dist[i - 1][j] < min)
          min = (dist[i - 1][j]);

        if (dist[i][j - 1] < min)
          min = dist[i][j - 1];

        dist[i][j] = min + 1;
      }
    }
  }

  int d = dist[len_u][len_v];

  for (int i = 0; i <= len_u; i += 1)
    free(dist[i]);
  free(dist);

  return d;
}

int main(int argc, char** argv)
{
  assert(argc == 3);

  printf("distance : %d\n", dist(argv[1], argv[2]));

  return 0;
}
