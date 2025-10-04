#include <stdio.h>
#include <unistd.h>

int main() {
  printf("Using a system call to read from standard input...\n");

  char buffer[100];
  ssize_t bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer));

  if (bytes_read > 0) {
    printf("Read %zd bytes: %s\n", bytes_read, buffer);
  } else {
    printf("Failed to read.\n");
  }

  return 0;
}
