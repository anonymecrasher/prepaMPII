#include <stdio.h>
#include <stdbool.h>

void print_line(){
  printf("+");
  for (int i = 0; i < 3; i = i + 1){
    for (int j = 0; j < 3; j = j + 1)
      { printf("-"); }
    printf("+");
  }
  printf("\n");
}

void print_row(int r[9]){
  printf("|");
  for (int i = 0; i < 3; i = i + 1){
    for (int j = 0; j < 3; j = j + 1){
      if (r[i*3+j] == 0)
        { printf(" "); }
      else
        { printf("%d",r[i*3+j]); }
    }
    printf("|");
  }
  printf("\n");
}

void print_grid(int g[9][9]){
  print_line();
  for (int i = 0; i < 3; i = i + 1){
    for (int j = 0; j < 3; j = j + 1)
      { print_row(g[3*i+j]); }
    print_line();
  }
}

bool is_in_column(int x, int j, int g[9][9]){
  /* TODO */
  for (int i = 0; i < 9; i++) {
    if (x == g[i][j]) return true;
  }
  return false;
}

bool is_in_row(int x, int i, int g[9][9]){
  /* TODO */
  for (int j = 0; j < 9; j++) {
    if (x == g[i][j]) return true;
  }
  return false;
}

bool is_in_region(int x, int i, int j, int g[9][9]){
  /* TODO */
  for(int ip = 0; ip < 3; ip++){
    for (int jp = 0; jp < 3; jp++){
      if (x == g[3*i + ip][3*j + jp]) return true;
    }
  }
  return false;
}

int first_zero(int g[9][9]){
  /* Returns i*9+j, where (i,j) is the first 0.
     Returns -1 if there is no 0. */
  /* TODO */
  for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++){
      if (g[i][j] == 0) return i*9 + j;
    }
  }
  return -1;
}

bool solve(int g[9][9]){
  /* Fills the grid and returns true if a solution is found.
     Leave the grid unchanged and returns false otherwise. */
  /* TODO */
  int f_0 = first_zero(g);
  if (f_0 == -1) return true;
  int i = f_0 / 9;
  int j = f_0 % 9;
  for (int x = 1; x < 10; x++){
    if (!((is_in_column(x,j,g)) || (is_in_row(x,i,g)) || (is_in_region(x, i/3, j/3,g)))) {
      g[i][j] = x;
      bool flag = solve(g);
      if (flag) return flag;
    }
  }
  g[i][j] = 0;
  return false;
}

int main(int argc, char *argv[]){
  int grille[9][9] = {
    {9,0,0,1,0,0,0,0,5},
    {0,0,5,0,9,0,2,0,1},
    {8,0,0,0,4,0,0,0,0},
    {0,0,0,0,8,0,0,0,0},
    {0,0,0,7,0,0,0,0,0},
    {0,0,0,0,2,6,0,0,9},
    {2,0,0,3,0,0,0,0,6},
    {0,0,0,2,0,0,9,0,0},
    {0,0,1,9,0,4,5,7,0}
  };
  printf("%b", is_in_region);

  print_grid(grille);
  printf("%b",solve(grille));
  printf("\nSolving ...\n\n");

  print_grid(grille);

  return 0;
}
