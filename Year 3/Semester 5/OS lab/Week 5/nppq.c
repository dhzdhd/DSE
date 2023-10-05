#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int pid;
    int at;
    int bt;
    int pri;
    int wt;
    int tat;
    int comp_time;
} P;

void calcTimesNP(P *pros, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (pros[j].pri > pros[j + 1].pri)
            {
                P temp = pros[j];
                pros[j] = pros[j + 1];
                pros[j + 1] = temp;
            }
        }
    }

    int currTime = 0;
    int totalWT = 0;
    int totalTAT = 0;

    for (int i = 0; i < n; i++)
    {
        pros[i].comp_time = currTime + pros[i].bt;
        pros[i].wt = currTime - pros[i].at;
        pros[i].tat = pros[i].wt + pros[i].bt;

        currTime = pros[i].comp_time;
        totalWT += pros[i].wt;
        totalTAT += pros[i].tat;
    }

    printf("P\tAT\tBT\tPRI\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pros[i].pid, pros[i].at,
               pros[i].bt, pros[i].pri, pros[i].wt, pros[i].tat);
    }

    float avgWT = (float)totalWT / n;
    float avgTAT = (float)totalTAT / n;

    printf("\nAWT: %.2f\n", avgWT);
    printf("ATAT: %.2f\n", avgTAT);
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
    }

    calcTimesNP(pros, n);

    free(pros);
    return 0;
}

// Enter the number of processes: 3
// Enter arrival time, burst time, and priority for process 1: 0 1 1
// Enter arrival time, burst time, and priority for process 2: 1 2 3
// Enter arrival time, burst time, and priority for process 3: 3 4 5
// Process Arrival Time    Burst Time      Priority        Waiting Time    Turnaround Time
// 1               0               1               1               0               1
// 2               1               2               3               0               2
// 3               3               4               5               0               4

// Average Waiting Time: 0.00
// Average Turnaround Time: 2.33
