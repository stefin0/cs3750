#include <stdio.h>
#include <unistd.h>

int main() {
  printf("Attempting privileged operation...\n");

  // Directly accessing hardware (causes segmentation fault in user mode)
  int *ptr = (int *)0xFFFF0000; // Arbitrary high address
  *ptr = 42;

  printf("Privileged operation successful.\n");

  return 0;
}
