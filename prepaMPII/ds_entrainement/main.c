#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct maillon {
  int value;
  struct maillon *prev;
  struct maillon *next;
};

typedef struct maillon* list;

list push_right(int x, list l){
  struct maillon *m = malloc(sizeof(struct maillon));
  m->value = x;
  if (l != NULL){

    m->next = l->next;
    l->next->prev = m;
    m->prev = l;
    l->next = m;
  }
  if (l == NULL){
    m->next = m;
    m->prev = m;
  }
  return m;
}

list push_left(int x, list l){
  struct maillon *m = malloc(sizeof(struct maillon));
  m->value = x;
  if (l != NULL){
    m->next = l;
    m->prev = l->prev;
    l->prev->next = m;
    l->prev = m;
  }
  if (l == NULL){
    m->next = m;
    m->prev = m;
  }
  return m;
}


list pop_left(list l){
  assert(l != NULL);
  if (l->next == l) return NULL;
  list m = l->next;
  l->prev->next = l->next;
  l->next->prev = l->prev;
  free(l);
  return m;

}

list pop_right(list l){
  assert(l != NULL);
  if (l->next == l) return NULL;
  list m = l->prev;
  l->prev->next = l->next;
  l->next->prev = l->prev;
  free(l);
  return m;
}

int len(list l){
  list m;

  if (l == NULL)
    return 0;

  int cpt = 1;
  m = l->next;

  while (m != l){
    cpt++;
    m = m->next;
  }
  return cpt;
}


void print_list(list l){
  list m;

  if (l == NULL)
    printf("/n");

  m = l->next;

  while (m != l){
    printf("%d/n", m->value);
    m = m->next;
  }
  return;
}


int hd(list l){
  assert(l != NULL);
  return l->value;
}



