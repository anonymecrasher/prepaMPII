#include <stdlib.h>
#include <stdio.h>

typedef struct maillon* list;

// On ne considère ici que des listes d'entiers

// Ajoute x à la liste l et renvoie la nouvelle liste
list cons(int x, list l); // O(1)

// Renvoie l'entier en tête de la liste l
int hd(list l); // O(1)

// Renvoie la liste l privée de son premier élément. On libèrera la mémoire occupée par ce premier maillon
list tl(list l); // O(1)

// Affiche le contenu d'une liste
void print_list(list l); // O(|l|)

// Génère une liste aléatoire de n éléments valant entre 0 inclus et k exclus
list rand_list(int n, int k); // O(n)

// Libère l'espace occupé par une liste
void free_list(list l); // O(|l|)
