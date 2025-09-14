#include <stdio.h>
#include <unistd.h>

int main() {
  printf("Process PID = %d\n", getpid());

  fork();
  fork();

  printf("After two successive forks, PID = %d\n", getpid());

  return 0;
}
