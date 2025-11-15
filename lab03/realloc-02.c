#include <stdio.h>
#include <stdlib.h>

int main() {
  int *arr = malloc(sizeof(int) * 3); // Initial allocation

  if (arr == NULL) {
    printf("Memory allocation failed!\n");
    return -1;
  }

  for (int i = 0; i < 3; i++) {
    arr[i] = i + 1; // Initialize array
  }

  arr = realloc(arr, sizeof(int) * 2); // Resize array

  if (arr == NULL) {
    printf("Memory reallocation failed!\n");
    return -1;
  }

  for (int i = 0; i < 2; i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
  }

  free(arr); // Free memory

  return 0;
}
