#include <stdlib.h>
#include <stdio.h>


int fib_rec(int fibo[], int n){
  if (fibo[n] == -1)
    fibo[n] = fib_rec(fibo, n-1) + fib_rec(fibo, n-2);
  return fibo[n];
}

int fib(int n){
  int *mem = malloc((n+1) * sizeof(int));
  mem[0] = 0;
  mem[1] = 1;
  for (int i = 2 ; i <= n ; i++)
    mem[i] = -1;
  int res = fib_rec(mem, n);
  free(mem);
  return res;
}


/*  version naive
int fib(int n){
  if (n < 2) return n;
  return fib(n-1) + fib(n-2);

}

*/

void main(void){
  int n = 40000;
  printf("fib %d = %d\n", n , fib(n));
}
