#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void copy_tab(int taille_1, char tab_1[], int taille_2, char tab_2[]){
  assert (taille_1 < taille_2);
  for (int i = 0; i < taille_1; i = i + 1)
    {
      tab_2[i] = tab_1[i];
    }
}
int main(int argc, char *argv[])
{
  int i = 10;
  char *tab_fich = malloc(i * sizeof(char));
  char *tab_fich_temp;
  int pos_current_char = 0;
  char current_char;



  if (argc == 1)
    {
      return EXIT_SUCCESS;
    }

  if (argc != 2){
    printf("Ce programme utilise au plus un argument.\n");
    return EXIT_FAILURE;
  }



  FILE *f = fopen(argv[1], "r");
  while (fscanf(f, "%c", &current_char) != EOF)
    {
      printf("%c", current_char);
      if (pos_current_char > i){
        i = i *2;
        tab_fich_temp = malloc(i * sizeof(char));
        copy_tab(i-10, tab_fich, i, tab_fich_temp);
        free(tab_fich);
        tab_fich = tab_fich_temp;
      }
      tab_fich[pos_current_char] = current_char;
      pos_current_char = pos_current_char + 1;
    }
  for (int j = 0 ; j < i; j = j +1 ) printf("%c", tab_fich[j]);
  printf("Vous avez choisi le fichier \"%s\".\n", argv[1]);
}
