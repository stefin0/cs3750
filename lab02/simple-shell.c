#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  char command[100];
  pid_t pid;

  while (1) {
    printf("my-simple-shell> ");
    fgets(command, sizeof(command), stdin);

    // Remove newline character
    command[strcspn(command, "\n")] = 0;

    pid = fork();
    if (pid == 0) {
      execlp(command, command, (char *)NULL); // Execute command
      perror("execlp failed");
      exit(1);
    } else if (pid > 0) {
      waitpid(pid, NULL, 0); // Wait for child process to finish
    } else {
      perror("fork failed");
    }
  }

  return 0;
}
