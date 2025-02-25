#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// Constante du programme
int init_size = 100;

// Structure de la file d'entiers
typedef struct {
    char* *values;
    int front;
    int rear;
    int max;
} queue_char;

queue_char *QUEUE_init(void);
bool QUEUE_is_empty(queue_char *q);
bool QUEUE_is_full(queue_char *q);
void QUEUE_realoc(queue_char *q);
void QUEUE_enqueue(char *x, queue_char *q);
char* QUEUE_dequeue(queue_char *q);
int QUEUE_front(queue_char *q);
void QUEUE_free(queue_char *q);
