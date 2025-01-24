#include "queue.h"

struct queue_s {
  int *tab;
  int head;
  int len;
  int max;
};

queue_t *init(void){
  queue_t *a = malloc(sizeof(queue_t));
  (*a).tab = malloc(10 * sizeof(int));
  (*a).head = 0;
  (*a).len = 0;
  (*a).max = 10;
  return a;
}

bool is_empty(queue_t *s){
  return ((*s).len == 0);

}

int top(queue_t *s){
  assert(!(is_empty(s)));
  return (*s).tab[s->head];
}

void redimention(queue_t *s){
  int *tableau = malloc(2*(s->max)* sizeof(int));
  for (int i = 0; i < s->len; i++){
    tableau[i] = s->tab[i];
  }
  free(s->tab);
  s->tab = tableau;

}

void push(int x, queue_t *s){
  if ((s->len + 1) >= s->max){
    redimention(s);
  }
  s->tab[(s->len + s->head)%s->max] = x;
  s->len++;
  return;
}

void pop(queue_t *s){
  assert(!is_empty(s));
  s->len = s->len - 1;
  return;
}
