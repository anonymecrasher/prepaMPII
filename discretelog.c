#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Tous les calculs sont effectues modulo 2**31 - 1 */
/* Les nombres sont representes par leur ecriture en binaire, en tant que chaine de caracteres de taille 31 */

char zero[] = "0000000000000000000000000000000";
char un[] = "0000000000000000000000000000001";
char sept[] = "0000000000000000000000000000111"; // A completer !
char q[] = "/* 1111111111111111111111111111111 */"; //2^31-1
char sqrtq[] = "0000000000000001011010100000101"; //46341

void print_endline(char s[])
{
  printf("%s\n",s);
}

void print_bool(bool b)
{
  if (b)
    {
      printf("true\n");
    }
  else
    {
      printf("false\n");
    }
}

bool is_equal(char a[], char b[]) // a == b
{
  assert (31 == strlen(a));
  assert (31 == strlen(b));

  /* TODO */
  for (int i = 0; i < 31; i = i + 1 )
    {
      if (a[i] != b[i])//on compare bit a bit.
        {
          return false;
        }
    }
  return true;

}

bool is_greater(char a[], char b[]) // a > b
{
  assert (31 == strlen(a));
  assert (31 == strlen(b));

  /* TODO */
  for (int i = 0; i < 31; i = i + 1)//on compare bit a bit.
    {
      if (!(a[i] == b[i]))
        {
          return a[i] == '1' && b[i] == '0';
        }
    }
  return false;

}

void negate(char a[]) // a = -a
{
  assert (31 == strlen(a));

  /* TODO */

}

void incr(char a[]) // a = a + 1
{
  assert (31 == strlen(a));

  /* TODO */
  int i = 31;
  while (i > 0)
    {
      if (!(a[i] == '1')){i = -1; a[i] = '1';}
      else a[i] = '0';
      i = i -1;
    }

}

void add_to(char a[], char b[]) // a = a + b
{
  assert (31 == strlen(a));
  assert (31 == strlen(b));

  /* TODO */
  while (!is_equal( b , zero)){
    
  

}

void mult_by(char a[], char b[]) // a = a * b
{
  assert (31 == strlen(a));
  assert (31 == strlen(b));

  /* TODO */

}

void expo(char a[], char b[]) // a = a ** b
{
  assert (31 == strlen(a));
  assert (31 == strlen(b));

  /* TODO */

}

void naif_dlog(char a[], char b[]) // a = dlog_b(a)
{
  assert (31 == strlen(a));
  assert (31 == strlen(b));

  /* TODO */

}

void dlog(char a[], char b[]) // baby step - giant step
{
  assert (31 == strlen(a));
  assert (31 == strlen(b));

  /* TODO */

}

int main(int argc, char *argv[])
{
  char target0[] = "1111111111111111111111111111110";
  char target1[] = "0011111111001000010000000100110";
  char target2[] = "1011010001101011101011001100111";
  char x[] = "0111111111111111111111111111111";

  /* Code execute */

  return 0;
}
