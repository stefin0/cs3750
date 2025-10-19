#include <setjmp.h>
#include <stdio.h>

jmp_buf buf; // Define a global variable to hold the jump buffer

void func1() {
  printf("In func1\n");
  longjmp(buf, 1); // Jump to the location saved by setjmp with value 1
}

void func2() {
  printf("In func2\n");
  longjmp(buf, 2); // Jump to the location saved by setjmp with value 2
}

void func3() { printf("In func3\n"); }

int main() {
  int val = setjmp(buf); // Save the current execution context in buf

  if (val == 0) {
    func1(); // Initially, jump to func1
  } else if (val == 1) {
    func2(); // Return here after jumping from func1
  } else if (val == 2) {
    func3(); // Return here after jumping from func2
  }

  return 0;
}
