#include "ll.h"

int main(int argc, char *argv[]){
  list l = NULL;
  l = rand_list(99999, 99);
  print_list(l);
  free_list(l);
  return 0;
}
