#include "str.h"


struct string_s str_create(int taille) {
  struct string_s str;
  str.data = malloc(n * sizeof(char));
  str.len = 0;
  str.max = n;
  return str;
}

void redimention(struct string_s str);

void str_add(struct string_s str, char c){
  if (str.len + 1 < str.max) {

    str.data[(str.len+1)] = c;
    str.len = str.len + 1;
  }
  else
    {
      
    }
}
