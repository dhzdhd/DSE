#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int main()
{
    int arr[1000], n, target;
    int sizes[] = {100, 200, 300, 500, 1000};
    int threads[] = {2, 3, 4, 5};

    for (int size = 0; size < 5; size++)
    {
        printf("\n\nInput size: %d\n", sizes[size]);
        n = sizes[size];

        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % 10 + 1;
        }
        target = rand() % 10 + 1;

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
        for (int t = 0; t < 4; t++)
        {
            int thread = threads[t];
            omp_set_num_threads(thread);
            printf("Threads: %d\n", thread);

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
        }
    }

    return 0;
}