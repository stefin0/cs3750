#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  printf("location of code: %p\n", (void *)main);

  void *heap_memory = malloc(sizeof(int)); // Allocate memory
  printf("location of heap: %p\n", heap_memory);

  int x = 3;
  printf("location of stack: %p\n", (void *)&x);

  // Free the allocated memory
  free(heap_memory);

  return 0;
}
