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

  arr = realloc(arr, sizeof(int) * 6); // Resize array

  if (arr == NULL) {
    printf("Memory reallocation failed!\n");
    return -1;
  }

  // The first 3 elements are preserved
  // The additional elements (indices 3 to 5) will contain garbage values
  for (int i = 0; i < 6; i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
  }

  for (int i = 3; i < 6; i++) {
    arr[i] = i + 1; // Initialize new elements
  }

  for (int i = 0; i < 6; i++) {
    printf("%d ", arr[i]); // Print resized array
  }

  free(arr); // Free memory

  return 0;
}
