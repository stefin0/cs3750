#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n = 5;
  int *heap_memory = malloc(sizeof *heap_memory * n);

  for (int i = 0; i < n; i++) {
    *(heap_memory + i) = i * 5;
    printf("i=%d, value=%d, address=%p\n", i, *(heap_memory + i),
           (void *)(heap_memory + i));
  }

  free(heap_memory);

  return 0;
}
