#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

void odd_even_sort(int *a, int n)
{
    int phase, temp;

    for (phase = 0; phase < n; ++phase)
    {
        if (phase % 2 == 0)
        {

#pragma omp parallel for private(temp)
            for (int i = 1; i < n - 1; i += 2)
            {
                if (a[i] > a[i + 1])
                {
                    temp = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = temp;
                }
            }
        }
        else
        {

#pragma omp parallel for private(temp)
            for (int i = 0; i < n - 1; i += 2)
            {
                if (a[i] > a[i + 1])
                {
                    temp = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = temp;
                }
            }
        }
    }
}

int main()
{
    int arr1[1000], arr2[1000], n;
    int sizes[] = {100, 200, 300, 500, 1000};
    int threads[] = {2, 3, 4, 5};

    for (int size = 0; size < 5; size++)
    {
        printf("\n\nInput size: %d\n", sizes[size]);
        n = sizes[size];

        for (int i = 0; i < n; i++)
        {
            arr1[i] = rand() % 10 + 1;
            arr2[i] = arr1[i];
        }

        // Sequential
        double start = omp_get_wtime();

        // !selectionSort(arr1, n);

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

            //! parallelSelectionSort(arr2, n);

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
