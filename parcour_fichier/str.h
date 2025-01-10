#ifndef STR_H
#define STR_H


struct string_s {
  char *data
  int len;
  int max;

};

struct string_s str_create(int taille); // crée un string de taille n - O(1)
void str_add(struct string_s str, char c);
int str_length(struct string_s str);
void str_print(struct string_s str);


#endif
