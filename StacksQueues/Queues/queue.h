#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct queue_s queue_t;

queue_t *init(void);
bool is_empty(queue_t *s);
int top(queue_t *s);
void push(int x, queue_t *s);
void pop(queue_t *s);

#endif
