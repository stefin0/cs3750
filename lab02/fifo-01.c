#include <stdio.h>

// Function to calculate turnaround time and response time using FIFO scheduling
void fifo(int processes[], int n, int burst_time[]) {
  int turnaround_time[n],
      response_time[n]; // Arrays for turnaround and response times
  int total_tat = 0,
      total_rt = 0; // Variables for total turnaround and response times

  // First process starts immediately
  response_time[0] = 0;
  turnaround_time[0] = burst_time[0];

  // Add first process times to totals
  total_tat += turnaround_time[0];
  total_rt += response_time[0];

  // Calculate response and turnaround times for remaining processes
  for (int i = 1; i < n; i++) {
    response_time[i] =
        response_time[i - 1] +
        burst_time[i - 1]; // Response time is the sum of previous burst times
    turnaround_time[i] =
        response_time[i] +
        burst_time[i]; // Turnaround time is response time + burst time

    total_tat += turnaround_time[i]; // Accumulate total turnaround time
    total_rt += response_time[i];    // Accumulate total response time
  }

  // Display process details
  printf("Process\tBurst\tTurnaround Time\t\tResponse Time\n");
  for (int i = 0; i < n; i++)
    printf("%d\t%d\t%d\t\t\t%d\n", processes[i], burst_time[i],
           turnaround_time[i], response_time[i]);

  // Print average times
  printf("Average turnaround time = %.2f\n", (float)total_tat / n);
  printf("Average response time = %.2f\n", (float)total_rt / n);
}

int main() {
  int processes[] = {1, 2, 3};   // Process IDs
  int burst_time[] = {10, 5, 8}; // Burst times for each process
  int n = sizeof(processes) / sizeof(processes[0]); // Number of processes

  fifo(processes, n, burst_time);

  return 0;
}
