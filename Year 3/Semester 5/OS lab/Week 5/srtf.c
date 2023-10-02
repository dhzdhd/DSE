#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
} Process;

void calculateTimes(Process *processes, int n)
{
    int currentTime = 0;
    int completed = 0;
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    // Continue until all processes are completed
    while (completed < n)
    {
        int shortest = INT_MAX;
        int shortestIndex = -1;

        // Find the process with the shortest remaining burst time
        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrival_time <= currentTime && processes[i].remaining_time < shortest && processes[i].remaining_time > 0)
            {
                shortest = processes[i].remaining_time;
                shortestIndex = i;
            }
        }

        // No suitable process found, move to the next arrival time
        if (shortestIndex == -1)
        {
            currentTime++;
            continue;
        }

        // Execute the process for one unit of time
        processes[shortestIndex].remaining_time--;
        currentTime++;

        // If the process is completed
        if (processes[shortestIndex].remaining_time == 0)
        {
            completed++;
            processes[shortestIndex].completion_time = currentTime;
            processes[shortestIndex].turnaround_time = processes[shortestIndex].completion_time - processes[shortestIndex].arrival_time;
            processes[shortestIndex].waiting_time = processes[shortestIndex].turnaround_time - processes[shortestIndex].burst_time;
            totalWaitingTime += processes[shortestIndex].waiting_time;
            totalTurnaroundTime += processes[shortestIndex].turnaround_time;
        }
    }

    // Display process details
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].arrival_time,
               processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    // Calculate and display average waiting time and average turnaround time
    float avgWaitingTime = (float)totalWaitingTime / n;
    float avgTurnaroundTime = (float)totalTurnaroundTime / n;

    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process *processes = (Process *)malloc(n * sizeof(Process));

    // Input process details
    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d%d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].process_id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    calculateTimes(processes, n);

    free(processes);
    return 0;
}
