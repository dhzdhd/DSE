#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        if (min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

struct Compare
{
    int val;
    int index;
};
#pragma omp declare reduction(maximum : struct Compare : omp_out = omp_in.val > omp_out.val ? omp_in : omp_out)

void parallelSelectionSort(int arr[], int size)
{
    for (int i = size - 1; i > 0; --i)
    {
        struct Compare max;
        max.val = arr[i];
        max.index = i;
#pragma omp parallel for reduction(maximum : max)
        for (int j = i - 1; j >= 0; --j)
        {
            if (arr[j] > max.val)
            {
                max.val = arr[j];
                max.index = j;
            }
        }
        int tmp = arr[i];
        arr[i] = max.val;
        arr[max.index] = tmp;
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

        selectionSort(arr1, n);

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

            parallelSelectionSort(arr2, n);

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
