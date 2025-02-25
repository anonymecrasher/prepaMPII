#include "ll.h"
#include <assert.h>

struct maillon{
  /* TODO */
  int val;
  struct maillon *next;
};
typedef struct maillon* list;

list cons(int x, list l){
  /* TODO */
  struct maillon *m = malloc(sizeof(struct maillon));
  m->val = x;
  m->next = l;
  return m;
}

int hd(list l){
  /* TODO */
  assert(l != NULL);
  return l->val;
}

list tl(list l){
  /* TODO */
  if (l != NULL){
    list temp = l->next;
    free(l);
    return temp;}
  return NULL;
}

void print_list(list l){
  /* TODO */
  struct maillon *l1 = l;
  while (l1 != NULL){
    printf("%d ", hd(l1));
    l1 = l1->next;
  }
  printf(" \n");
}

list rand_list(int n, int k){
  /* rand() renvoie un entier aléatoire entre 0 et RAND_MAX */
  /* TODO */
  list l = NULL;
  for (int i = 0; i<n; i++)
    {
      l = cons(rand(), l);
    }
  return l;
}

void free_list(list l){
  /* TODO */
  list l1;
  while (l != NULL){
    l1 = tl(l);
    l = l1;
  }
}

int nth(list l, int n){
  int cpt = 0;
  while (cpt < n){
    assert(l!= NULL);
    l = l->next;
    cpt++;
  }
  return l->val;
}
