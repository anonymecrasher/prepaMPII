#ifndef PILE_H
#define PILE_H

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct stack_s stack_int;
typedef struct stack_string stack_str; 

stack_int *PILE_init(void);
bool PILE_is_empty(stack_int *s);
int PILE_top(stack_int *s);
void PILE_realoc(stack_int *s);
void PILE_push(int x, stack_int *s);
int PILE_pop(stack_int *s);

stack_str *PILE_init_str(void);
bool PILE_is_empty_str(stack_str *s);
char* PILE_top_str(stack_str *s);
void PILE_realoc_str(stack_str *s);
void PILE_push_str(char* x, stack_str *s);
char* PILE_pop_str(stack_str *s);


#endif
