#include <stdio.h>
#include "queue.h"

int main(int argc, char *argv[]){
  queue_t *q = init();
  assert(is_empty(q));

  push(5, q);
  assert(!is_empty(q));
  assert(5 == top(q));

  pop(q);
  assert(is_empty(q));

  push(1, q);
  assert(!is_empty(q));
  assert(1 == top(q));

  push(4, q);
  assert(1 == top(q));

  push(2, q);
  assert(1 == top(q));

  pop(q);
  assert(4 == top(q));

  pop(q);
  assert(2 == top(q));
  pop(q);
  assert(is_empty(q));

  return EXIT_SUCCESS;
}
