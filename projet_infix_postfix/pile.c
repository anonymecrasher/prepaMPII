#include "pile.h"

//contante du programme
int init_size = 100;



struct stack_s {
  int *values;
  int hd; // hd -> stack head
  int max;
};

stack_int *init(void){
  stack_int *s = malloc(sizeof(stack_int));
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
  int *tmp = malloc(sizeof(int) * (10 * s->max));
  for (int i=0; i < s->hd; i = i + 1){
    tmp[i] = s->values[i];
    }
  free(s->values);
  s->values = tmp;
  s->max = s->max * 10;
}

void push(int x, stack_int *s){
  if (s->hd + 1 >= s->max){realoc(s);}
  s->values = x;
  s->hd = s->hd + 1;
}

int pop(stack_int *s){
  int x = top(s);
  s->hd = s->hd - 1;
  return x;
}


struct stack_string {
  int **values;
  int hd; // hd -> stack head
  int max;
};



stack_str *init_str(void){
  stack_str *s = malloc(sizeof(stack_int));
  s->values = malloc(init_size * sizeof(char*));
  s->hd = -1;
  s->max = init_size;
  return s;
}

bool is_empty_str(stack_str *s){
  return (s->hd == -1);
}

char* top_str(stack_str *s){
  assert(is_empty(s));
  return s->values[s->hd];
}
void realoc_str(stack_str *s){
  char* *tmp = malloc(sizeof(char*) * (10 * s->max));
  for (int i=0; i < s->hd; i = i + 1){
    tmp[i] = s->values[i];
    }
  free(s->values);
  s->values = tmp;
  s->max = s->max * 10;
}

void push_str(char* x, stack_str *s){
  if (s->hd + 1 >= s->max){realoc(s);}
  s->values = x;
  s->hd = s->hd + 1;
}

char* pop_str(stack_str *s){
  char* x = top(s);
  s->hd = s->hd - 1;
  return x;
}




