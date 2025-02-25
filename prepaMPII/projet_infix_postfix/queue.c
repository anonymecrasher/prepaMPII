#include "queue.h"



queue_char *QUEUE_init(void) {
    queue_char *q = malloc(sizeof(queue_char));
    q->values = malloc(init_size * sizeof(char *));
    q->front = -1;
    q->rear = -1;
    q->max = init_size;
    return q;
}

bool QUEUE_is_empty(queue_char *q) {
    return (q->front == -1);
}

bool QUEUE_is_full(queue_char *q) {
    return (q->rear == q->max - 1);
}

void QUEUE_realoc(queue_char *q) {
    int *tmp = malloc(sizeof(char) * (10 * q->max));
    for (int i = 0; i <= q->rear; i++) {
        tmp[i] = q->values[i];
    }
    free(q->values);
    q->values = tmp;
    q->max *= 10;
}

void QUEUE_enqueue(char *x, queue_char *q) {
    if (QUEUE_is_full(q)) {
        QUEUE_realoc(q);
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->values[++q->rear] = x;
}

char* QUEUE_dequeue(queue_char *q) {
    assert(!QUEUE_is_empty(q));
    char* x = q->values[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return x;
}

int QUEUE_front(queue_char *q) {
    assert(!QUEUE_is_empty(q));
    return q->values[q->front];
}

void QUEUE_free(queue_char *q) {
    free(q->values);
    free(q);
}
