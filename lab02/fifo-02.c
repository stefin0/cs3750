#include <stdio.h>

// Function to calculate turnaround time and response time using FIFO scheduling
void fifo(int processes[], int n, int arrival_time[], int burst_time[]) {
  int start_time[n], completion_time[n], turnaround_time[n], response_time[n];
  int total_tat = 0, total_rt = 0;

  // First process starts immediately
  start_time[0] = 0;
  completion_time[0] = burst_time[0] + start_time[0];
  turnaround_time[0] = completion_time[0] - arrival_time[0];
  response_time[0] = start_time[0] - arrival_time[0];

  // Add first process times to totals
  total_tat += turnaround_time[0];
  total_rt += response_time[0];

  // Calculate response and turnaround times for remaining processes
  for (int i = 1; i < n; i++) {
    start_time[i] = burst_time[i - 1] + start_time[i - 1];
    completion_time[i] = burst_time[i] + start_time[i];
    turnaround_time[i] = completion_time[i] - arrival_time[i];
    response_time[i] = start_time[i] - arrival_time[i];

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
  int processes[] = {1, 2, 3, 4};    // Process IDs
  int arrival_time[] = {0, 2, 4, 6}; // Arrival times for each process
  int burst_time[] = {6, 8, 7, 3};   // Burst times for each process
  int n = sizeof(processes) / sizeof(processes[0]); // Number of processes

  fifo(processes, n, arrival_time, burst_time);

  return 0;
}
