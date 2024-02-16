#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int main()
{
    int arr[100], n, target;

    printf("Enter num of elements\n");
    scanf("%d", &n);

    printf("Enter elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter target\n");
    scanf("%d", &target);

    // Sequential
    double start = omp_get_wtime();

    int res = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            res = i;
        }
    }

    if (res == -1)
    {
        printf("Not found\n");
    }
    else
    {
        printf("Found at %d index\n", res);
    }

    double end = omp_get_wtime();
    double seq = end - start;
    printf("Sequential time: %f\n", seq);

    // Parallel
    start = omp_get_wtime();
    res = -1;

#pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            res = i;
        }
    }

    if (res == -1)
    {
        printf("Not found\n");
    }
    else
    {
        printf("Found at %d index\n", res);
    }

    end = omp_get_wtime();
    double par = end - start;
    printf("Parallel time: %f\n", par);

    double speedup = seq / par;
    double eff = speedup / omp_get_num_threads();

    printf("Speedup: %f, Efficiency: %f\n", speedup, eff);

    return 0;
}
