#include "stack.h"

struct stack_s {
  int *tab;
  int len;
  int max;
};

stack_t *init(void){
  stack_t *a = malloc(sizeof(stack_t));
  (*a).tab = malloc(10 * sizeof(int));
  (*a).len = 0;
  (*a).max = 10;
  return a;
}

bool is_empty(stack_t *s){
  return ((*s).len == 0);

}

int top(stack_t *s){
  assert(!(is_empty(s)));
  return (*s).tab[((*s).len - 1)];
}

void redimention(stack_t *s){
  int *tableau = malloc(2*(s->max)* sizeof(int));
  for (int i = 0; i < s->len; i++){
    tableau[i] = s->tab[i];
  }
  free(s->tab);
  s->tab = tableau;

}

void push(int x, stack_t *s){
  if ((s->len + 1) >= s->max){
    redimention(s);
  }
  s->tab[s->len] = x;
  s->len++;
  return;
}

void pop(stack_t *s){
  assert(!is_empty(s));
  s->len = s->len - 1;
  return;
}
