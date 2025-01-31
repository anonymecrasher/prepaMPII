#include "pile.h"

//contante du programme
int init_size = 100;



struct stack_s {
  int *values;
  int hd; // hd -> stack head
  int max;
}

stack_int *init(void){
  stack_int s = malloc(sizeof(stack_int));
  s->values = malloc(init_size * sizeof(int));
  s->hd = -1;
  s->max = init_size;
  return s;
}

bool is_empty(stack_int *s){
  return (s->hd == -1);
}

int top(stack_int *s){
  assert(is_empty(s));
  return s->values[s->hd];
}
void realoc(stack_int *s){
  tmp = malloc(sizeof(int) * 10 * s->max);
  for (int i=0; i < s->hd; i = i + 1){
    tmp[i] = s->values[i];
    }
}





