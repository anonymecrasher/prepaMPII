#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct stack_s stack_t;

stack_t *init(void);
bool is_empty(stack_t *s);
int top(stack_t *s);
void push(int x, stack_t *s);
void pop(stack_t *s);

#endif
