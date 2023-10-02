#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int p;
    int a;
    int b;
    int r;
    int w;
    int t;
    int c;
} P;

void calcSJF(P *p, int n)
{
    int cur = 0;
    int comp = 0;
    int totalW = 0;
    int totalT = 0;

    while (comp < n)
    {
        int shortest = INT_MAX;
        int shortestIndex = -1;

        for (int i = 0; i < n; i++)
        {
            if (p[i].a <= cur && p[i].r < shortest && p[i].r > 0)
            {
                shortest = p[i].r;
                shortestIndex = i;
            }
        }

        if (shortestIndex == -1)
        {
            cur++;
            continue;
        }

        p[shortestIndex].r--;
        cur++;

        if (p[shortestIndex].r == 0)
        {
            comp++;
            p[shortestIndex].c = cur;
            p[shortestIndex].t = p[shortestIndex].c - p[shortestIndex].a;
            p[shortestIndex].w = p[shortestIndex].t - p[shortestIndex].b;
            totalW += p[shortestIndex].w;
            totalT += p[shortestIndex].t;
        }
    }

    printf("P\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].p, p[i].a, p[i].b, p[i].w, p[i].t);
    }

    float avgW = (float)totalW / n;
    float avgT = (float)totalT / n;

    printf("\nAWT: %.2f\n", avgW);
    printf("ATAT: %.2f\n", avgT);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    P *p = (P *)malloc(n * sizeof(P));

    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d%d", &p[i].a, &p[i].b);
        p[i].p = i + 1;
        p[i].r = p[i].b;
    }

    calcSJF(p, n);

    free(p);
    return 0;
}

// Enter the number of processes: 3
// Enter arrival time and burst time for process 1: 0 1
// Enter arrival time and burst time for process 2: 1 2
// Enter arrival time and burst time for process 3: 3 3
// Proc    Arrival Time    Burst Time      Waiting Time    Turnaround Time
// 1               0               1               0               1
// 2               1               2               0               2
// 3               3               3               0               3

// Average Waiting Time: 0.00
// Average Turnaround Time: 2.00
