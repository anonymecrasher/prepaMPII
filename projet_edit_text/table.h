#ifndef TABLE_H
#define TABLE_H

#include <stdlib.h>
#include <stdio.h>

// Structure de tableau redimensionnable
typedef struct {
    int *data;       // Tableau d'entiers
    size_t size;     // Taille actuelle du tableau
    size_t capacity; // Capacité maximale du tableau
} Tableau;

void TABLEAU_H_init_tableau(Tableau *t, size_t initial_capacity);
void TABLEAU_H_ajouter_element(Tableau *t, int value);
void TABLEAU_H_liberer_tableau(Tableau *t);
void TABLEAU_H_afficher_tableau(const Tableau *t);

#endif
