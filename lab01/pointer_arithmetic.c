#include <stdio.h>

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int *p = arr;

  // Traverse the array using pointer arithmetic
  for (int i = 0; i < 5; i++) {
    printf("Element %d: %d\n", i, *(p + i));
  }

  return 0;
}
