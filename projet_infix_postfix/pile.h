#ifndef PILE_H
#define PILE_H

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct stack_s stack_int;

stack_int *init(void);
bool is_empty(stack_int *s);
int top(stack_int *s);
void realoc(stack_int *s);
void push(int x, stack_int *s);
int pop(stack_int *s);

#endif
