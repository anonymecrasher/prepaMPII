#include <stdio.h>
#include "stack.h"

int main(int argc, char *argv[]){
  stack_t *s = init();
  assert(is_empty(s));

  push(5, s);
  assert(!is_empty(s));
  assert(5 == top(s));

  pop(s);
  assert(is_empty(s));

  push(1, s);
  assert(!is_empty(s));
  assert(1 == top(s));

  push(4, s);
  assert(4 == top(s));

  push(2, s);
  assert(2 == top(s));

  pop(s);
  assert(4 == top(s));

  pop(s);
  pop(s);
  assert(is_empty(s));

  return EXIT_SUCCESS;
}
