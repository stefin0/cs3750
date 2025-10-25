#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // #1 Allocating Memory for an Array of Integers
  int n = 5;
  int *arr = malloc(n * sizeof(int)); // Allocate memory for 5 integers

  if (arr == NULL) {
    printf("Memory allocation failed!\n");
    return -1;
  }

  for (int i = 0; i < n; i++) {
    arr[i] = i; // Initialize array
  }

  for (int i = 0; i < n; i++) {
    printf("arr[%d] = %d ", i, arr[i]); // Print array values
  }

  free(arr); // Free the allocated memory

  // #2 Allocating Memory for Strings
  char temp[] = "Hello"; // Length is 5, but stored as "Hello\0"

  // Allocating memory with space for null terminator '/0'
  char *str = (char *)malloc(strlen(temp) + 1);

  if (str == NULL) {
    printf("Memory allocation failed!\n");
    return 1;
  }

  strcpy(str, temp); // Copies characters + '\0' allocated space

  printf("Copied string: %s\n", str); // Will work

  char *another = (char *)malloc(10); // Allocating more memory
  strcpy(another, "World"); // Might overwrite the missing '\0' location

  printf("First string: %s\n", str); // Could print "HelloWorld" or crash
  printf("Second string: %s\n", another);

  free(str);
  free(another);

  return 0;
}
