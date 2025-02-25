#include "sizeable_table.h"




#define INITIAL_CAPACITY 10

size_a_t *SIZEABLE_TABLE_init_str(void) {
    size_a_t *s = (size_a_t *)malloc(sizeof(size_a_t));
    if (s == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    s->data = (char **)malloc(INITIAL_CAPACITY * sizeof(char *));
    if (s->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(s);
        exit(EXIT_FAILURE);
    }

    s->size = INITIAL_CAPACITY;
    for (int i = 0; i < INITIAL_CAPACITY; i++) {
        s->data[i] = NULL;
    }

    return s;
}

bool SIZEABLE_TABLE_is_empty(size_a_t *s) {
    if (s == NULL || s->data == NULL) return true;
    
    for (int i = 0; i < s->size; i++) {
        if (s->data[i] != NULL) {
            return false;
        }
    }
    return true;
}

void SIZEABLE_TABLE_realoc(size_a_t *s) {
    assert(s != NULL && s->data != NULL);
    
    s->size *= 2;
    char **new_data = (char **)realloc(s->data, s->size * sizeof(char *));
    if (new_data == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = s->size / 2; i < s->size; i++) {
        new_data[i] = NULL;
    }

    s->data = new_data;
}

void SIZEABLE_TABLE_free(size_a_t *s) {
    if (s == NULL) return;
    
    for (int i = 0; i < s->size; i++) {
        free(s->data[i]);
    }
    free(s->data);
    free(s);
}

