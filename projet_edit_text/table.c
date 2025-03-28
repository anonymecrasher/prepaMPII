#include "table.h"

void TABLEAU_H_init_tableau(Tableau *t, size_t initial_capacity) {
    t->data = (int *)malloc(initial_capacity * sizeof(int));
    if (t->data == NULL) {
        perror("Échec de l'allocation mémoire");
        exit(EXIT_FAILURE);
    }
    t->size = 0;
    t->capacity = initial_capacity;
}

void TABLEAU_H_ajouter_element(Tableau *t, int value) {
    // Si le tableau est plein, on double sa capacité
    if (t->size >= t->capacity) {
        t->capacity *= 2;
        t->data = (int *)realloc(t->data, t->capacity * sizeof(int));
        if (t->data == NULL) {
            perror("Échec de la réallocation mémoire");
            exit(EXIT_FAILURE);
        }
    }

    // Ajouter l'élément à la fin
    t->data[t->size] = value;
    t->size++;
}

void TABLEAU_H_liberer_tableau(Tableau *t) {
    free(t->data);
    t->data = NULL;
    t->size = 0;
    t->capacity = 0;
}

void TABLEAU_H_afficher_tableau(const Tableau *t) {
    for (size_t i = 0; i < t->size; i++) {
        printf("%d ", t->data[i]);
    }
    printf("\n");
}
