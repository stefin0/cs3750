#include <setjmp.h>
#include <stdio.h>
#include <time.h>

jmp_buf buf; // Define a global variable to hold the jump buffer
clock_t start_time;
double task_times[3] = {0.0, 0.0, 0.0};

void switch_task(int current_task_id, int next_jump_val) {
  // 1. Stop the timer and calculate elapsed time
  clock_t end_time = clock();
  double elapsed = (double)(end_time - start_time) / CLOCKS_PER_SEC;
  task_times[current_task_id] += elapsed;
  printf("-> Task %d ran for %f seconds.\n\n", current_task_id + 1, elapsed);

  // 2. If this isn't the last task, reset the timer and jump
  if (next_jump_val > 0) {
    start_time = clock();
    longjmp(buf, next_jump_val);
  }
}

void func1() {
  printf("In func1\n");
  switch_task(0, 1); // End task 0, jump to trigger case 1
}

void func2() {
  printf("In func2\n");
  switch_task(1, 2); // End task 1, jump to trigger case 2
}

void func3() {
  printf("In func3\n");
  switch_task(2, 0); // End task 2, don't jump (next_jump_val is 0
}

int main() {
  start_time = clock();
  int val = setjmp(buf); // Save the current execution context in buf

  if (val == 0) {
    func1(); // Initially, jump to func1
  } else if (val == 1) {
    func2(); // Return here after jumping from func1
  } else if (val == 2) {
    func3(); // Return here after jumping from func2
  }

  printf("--- Simulation Complete ---\n");
  printf("Total execution time for Task 1: %f seconds\n", task_times[0]);
  printf("Total execution time for Task 2: %f seconds\n", task_times[1]);
  printf("Total execution time for Task 3: %f seconds\n", task_times[2]);

  return 0;
}
