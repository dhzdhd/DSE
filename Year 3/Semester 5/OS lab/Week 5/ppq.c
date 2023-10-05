#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int pid;
    int at;
    int bt;
    int pri;
    int rem_time;
    int wt;
    int tat;
    int comp_time;
} P;

void calcTimesPreemptive(P *pros, int n)
{
    int currTime = 0;
    int comp = 0;
    int totalWT = 0;
    int totalTAT = 0;

    while (comp < n)
    {
        int highestPri = INT_MAX;
        int highestPriIndex = -1;

        for (int i = 0; i < n; i++)
        {
            if (pros[i].at <= currTime && pros[i].pri < highestPri && pros[i].rem_time > 0)
            {
                highestPri = pros[i].pri;
                highestPriIndex = i;
            }
        }

        if (highestPriIndex == -1)
        {
            currTime++;
            continue;
        }

        pros[highestPriIndex].rem_time--;
        currTime++;

        if (pros[highestPriIndex].rem_time == 0)
        {
            comp++;
            pros[highestPriIndex].comp_time = currTime;
            pros[highestPriIndex].tat = pros[highestPriIndex].comp_time - pros[highestPriIndex].at;
            pros[highestPriIndex].wt = pros[highestPriIndex].tat - pros[highestPriIndex].bt;
            totalWT += pros[highestPriIndex].wt;
            totalTAT += pros[highestPriIndex].tat;
        }
    }

    printf("Proc\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pros[i].pid, pros[i].at,
               pros[i].bt, pros[i].pri, pros[i].wt, pros[i].tat);
    }

    float avgWT = (float)totalWT / n;
    float avgTAT = (float)totalTAT / n;

    printf("\nAverage Waiting Time: %.2f\n", avgWT);
    printf("Average Turnaround Time: %.2f\n", avgTAT);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    P *pros = (P *)malloc(n * sizeof(P));

    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time, burst time, and priority for process %d: ", i + 1);
        scanf("%d%d%d", &pros[i].at, &pros[i].bt, &pros[i].pri);
        pros[i].pid = i + 1;
        pros[i].rem_time = pros[i].bt;
    }

    calcTimesPreemptive(pros, n);

    free(pros);
    return 0;
}

// Enter the number of processes: 3
// Enter arrival time, burst time, and priority for process 1: 0 1 1
// Enter arrival time, burst time, and priority for process 2: 1 2 3
// Enter arrival time, burst time, and priority for process 3: 3 3 4
// Proc    Arrival Time    Burst Time      Priority        Waiting Time    Turnaround Time
// 1               0               1               1               0               1
// 2               1               2               3               0               2
// 3               3               3               4               0               3

// Average Waiting Time: 0.00
// Average Turnaround Time: 2.00
