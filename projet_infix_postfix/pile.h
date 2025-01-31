#ifndef PILE_H
#define PILE_H

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct stack_s stack_int;
typedef struct stack_string stack_str; 

stack_int *init(void);
bool is_empty(stack_int *s);
int top(stack_int *s);
void realoc(stack_int *s);
void push(int x, stack_int *s);
int pop(stack_int *s);

stack_str *init_str(void);
bool is_empty_str(stack_str *s);
char* top_str(stack_str *s);
void realoc_str(stack_str *s);
void push_str(char* x, stack_str *s);
char* pop_str(stack_str *s);


#endif
