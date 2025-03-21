#include "search.h"


// Fonction pour calculer la longueur d'une chaîne de caractères
/* int strlen(char *factor) {
  int i = 0;
  while (factor[i] != '\0') {
    i++;
  }
  return i;
}*/

// Fonction pour construire le tableau des décalages
int **construct_table(char *factor) {
  int n = strlen(factor);  // Longueur du motif
  int **tab = malloc(n * sizeof(int *));  // Allocation d'un tableau de pointeurs pour les lignes du tableau
  for (int i = 0; i < n; i++) {
    tab[i] = malloc(256 * sizeof(int));  // Allocation de la mémoire pour chaque ligne (256 caractères possibles)
  }

  // Initialisation du tableau avec les bons décalages
  for (int i = 0; i < n; i++) {
    for (int c = 0; c < 256; c++) {
      if ((char)c == factor[i]) {
        tab[i][c] = i + 1;  // Si le caractère correspond au caractère du motif à la position i, on place i+1
      } else if (i == 0) {
        tab[i][c] = 1;  // Première ligne : si le caractère n'est pas celui du motif, on le décale de 1
      } else {
        tab[i][c] = tab[i-1][c] + 1;  // Pour les autres lignes, on copie la valeur de la ligne précédente et on ajoute 1
      }
    }
  }

  return tab;
}

// Fonction qui retourne le décalage à appliquer en fonction du caractère et de sa position dans le tableau
int gap(int **tab, int c, int pos_c) {
  return tab[pos_c][c];  // Retourne le décalage du caractère c à la position pos_c
}

// Fonction qui compare le motif avec la partie du texte à partir de la position donnée
int compare_texte_motif(char *word, char *factor, int position) {
  int i = strlen(factor);  // Longueur du motif
  bool flag = true;
  
  // Comparaison caractère par caractère
  while (i > 0 && flag && (position + i - 1) < strlen(word)) {
    flag = (word[position + i - 1] == factor[i - 1]);  // Vérifie si le caractère dans word correspond à celui du motif
    i--;  // Décrémentation de i pour comparer le caractère suivant
  }
  
  // Si flag reste vrai, cela signifie que tous les caractères ont été trouvés, sinon, on retourne la position où l'erreur s'est produite
  return (flag) ? -1 : i;  // Retourne -1 si tous les caractères sont trouvés, sinon retourne la position où l'échec a eu lieu
}

// Fonction qui cherche la première occurrence du motif dans le texte
int first_occurence(int start, int end, char *word, char *factor) {
  int **tab = construct_table(factor);  // Construction du tableau des décalages
  int i = 0;  // Initialisation de l'indice dans le texte
  int n = strlen(factor);  // Longueur du motif
  
  // Boucle pour chercher l'occurrence du motif dans le texte
  while (start + i + n <= end) {  // Tant que la position actuelle plus la longueur du motif ne dépasse pas la fin du texte
    int result_temp = compare_texte_motif(word, factor, start + i);  // Comparaison à la position actuelle
    if (result_temp == -1) {  // Si le motif est trouvé
      // Libération de la mémoire allouée pour le tableau de décalages
      for (int j = 0; j < n; j++) {
        free(tab[j]);
      }
      free(tab);
      return i;  // Retourne l'indice de la première occurrence
    } else {
      int dis = gap(tab, (int)word[start + i + result_temp], result_temp);  // Calcul du décalage en fonction du caractère et de la position
      i = i + dis;  // Avance dans le texte
    }
  }

  // Libération de la mémoire allouée pour le tableau de décalages
  for (int j = 0; j < n; j++) {
    free(tab[j]);
  }
  free(tab);

  return -1;  // Si aucune occurrence n'est trouvée, retourne -1
}

// Fonction principale pour tester le programme
void main(void) {
  char *word = "Les chaussettes de l'archiduchesse sont-elles seches archisèches.";  // Texte dans lequel on cherche le motif
  char *factor = "seches";  // Motif à rechercher
  
  // Affichage de l'indice de la première occurrence du motif dans le texte
  printf("%d\n", first_occurence(0, strlen(word) - 1, word, factor));
}
