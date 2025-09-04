#include <stdio.h>

int main() {
  int x = 10;
  int *p = &x;

  // Print value of x using variable and pointer
  printf("Value of x: %d\n", x);
  printf("Value of x using pointer: %d\n", *p);
  printf("Address of x: %p\n", (void *)&x);
  printf("Address stored in ptr: %p\n", (void *)p);

  // Modify value of x using pointer
  *p = 20;
  printf("Updated value of x: %d\n", x);

  return 0;
}
