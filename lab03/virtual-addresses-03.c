#include <stdio.h>

int main(void) {
  int x = 3;
  int y = 4;

  printf("location of stack (x): %p\n", (void *)&x);
  printf("location of stack (y): %p\n", (void *)&y);

  return 0;
}
