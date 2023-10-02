#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int p;
    int a;
    int b;
    int w;
    int t;
    int c;
} P;

void calcRR(P *p, int n, int q)
{
    int cur = 0;
    int comp = 0;
    int totalW = 0;
    int totalT = 0;

    while (comp < n)
    {
        int flag = 0;

        for (int i = 0; i < n; i++)
        {
            if (p[i].b > 0)
            {
                flag = 1;

                int e = (p[i].b < q) ? p[i].b : q;
                p[i].b -= e;
                cur += e;

                if (p[i].b == 0)
                {
                    comp++;
                    p[i].c = cur;
                    p[i].t = p[i].c - p[i].a;
                    p[i].w = p[i].t - p[i].b;
                    totalW += p[i].w;
                    totalT += p[i].t;
                }
            }
        }

        if (flag == 0)
            cur++;
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
    int n, q;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum for Round Robin: ");
    scanf("%d", &q);

    P *p = (P *)malloc(n * sizeof(P));

    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d%d", &p[i].a, &p[i].b);
        p[i].p = i + 1;
    }

    calcRR(p, n, q);

    free(p);
    return 0;
}

// Wrong
// Enter the number of processes: 3
// Enter the time quantum for Round Robin: 1
// Enter arrival time and burst time for process 1: 0 1
// Enter arrival time and burst time for process 2: 1 2
// Enter arrival time and burst time for process 3: 3 3
// Process Arrival Time    Burst Time      Waiting Time    Turnaround Time
// 1               0               1               0               1
// 2               1               2               1               3
// 3               3               3               0               3

// Average Waiting Time: 0.33
// Average Turnaround Time: 2.33
