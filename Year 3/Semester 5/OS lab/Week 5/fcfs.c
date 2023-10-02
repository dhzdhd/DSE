#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min_index(int *arr, int n)
{
        int min = INT_MAX;
        int index = -1;
        for (int i = 0; i < n; i++)
        {
                if (arr[i] < min)
                {
                        min = arr[i];
                        index = i;
                }
        }
        if (min == INT_MAX)
                return -1;
        return index;
}

float calc_awt(int *wt, int *ft, int *at, int n)
{
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
                wt[i] = ft[i] - at[i];
                sum = sum + wt[i];
        }
        return (float)sum / n;
}

float calc_atat(int *tat, int *bt, int *wt, int n)
{
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
                tat[i] = bt[i] + wt[i];
                sum = sum + tat[i];
        }
        return (float)sum / n;
}

int main()
{
        int n;
        printf("Enter number of processes\n");
        scanf("%d", &n);

        int *at = malloc(n * (int)(sizeof(int)));
        int *bt = malloc(n * (int)(sizeof(int)));
        int *buf = malloc(n * (int)(sizeof(int)));
        int *ft = malloc(n * (int)(sizeof(int)));
        int *wt = malloc(n * (int)(sizeof(int)));
        int *tat = malloc(n * (int)(sizeof(int)));

        printf("Enter arrival and burst times\n");
        for (int i = 0; i < n; i++)
        {
                scanf("%d", &at[i]);
                buf[i] = at[i];
                scanf("%d", &bt[i]);
        }

        int total_b = 0;
        for (int i = 0; i < n; i++)
        {
                int min_at = min_index(buf, n);
                printf("Process %d, Start %d, End %d\n", min_at, total_b, total_b + bt[min_at]);
                ft[min_at] = total_b;
                total_b = total_b + bt[min_at];
                buf[min_at] = INT_MAX;
        }

        printf("AWT: %g\n", calc_awt(wt, ft, at, n));
        printf("ATAT: %g\n", calc_atat(tat, bt, wt, n));

        return 0;
}
