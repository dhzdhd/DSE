#include <stdio.h>

struct process
{
    int wt, at, bt, tat, pt;
};
struct process a[10];

int main()
{
    int n, temp[10], t, count = 0, short_p;
    float total_wt = 0, total_tat = 0, avg_wt, avg_tat;

    printf("No. of Processes: \n");
    scanf("%d", &n);
    printf("AT bt pt\n");

    int i;

    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &a[i].at, &a[i].bt, &a[i].pt);
        temp[i] = a[i].bt;
    }

    a[9].pt = 10000;

    for (t = 0; count != n; t++)
    {
        short_p = 9;
        for (i = 0; i < n; i++)
        {
            if (a[short_p].pt > a[i].pt && a[i].at <= t && a[i].bt > 0)
            {
                short_p = i;
            }
        }
        a[short_p].bt = a[short_p].bt - 1;
        if (a[short_p].bt == 0)
        {
            count++;
            a[short_p].wt = t + 1 - a[short_p].at - temp[short_p];
            a[short_p].tat = t + 1 - a[short_p].at;
            total_wt = total_wt + a[short_p].wt;
            total_tat = total_tat + a[short_p].tat;
        }
    }

    avg_wt = total_wt / n;
    avg_tat = total_tat / n;

    printf("ID WT tat\n");

    for (i = 0; i < n; i++)
    {
        printf("%d %d\t %d\n", i + 1, a[i].wt, a[i].tat);
    }

    printf("Avg Waiting Time: %f\n", avg_wt);
    printf("Avg Turnaround Time: %f\n", avg_tat);

    return 0;
}
