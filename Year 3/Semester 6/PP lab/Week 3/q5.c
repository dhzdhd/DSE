#include <stdio.h>
#include <math.h>
#include <omp.h>

int rev(int num)
{
    int buf = 0;
    while (num > 0)
    {
        buf = (10 * buf) + num % 10;
        num = num / 10;
    }

    return buf;
    printf("%d\n", buf);
}

int main()
{
    int arr[9] = {18, 523, 301, 1234, 2, 14, 108, 150, 1928};

    // Sequential
    double begin1 = omp_get_wtime();

    for (int i = 0; i < 9; i++)
    {
        printf("%d ", rev(arr[i]));
    }
    printf("\n");

    double end1 = omp_get_wtime();
    double seq = end1 - begin1;
    printf("Sequential time: %f\n", seq);

    // Parallel
    double begin2 = omp_get_wtime();
    int num_threads;

#pragma omp parallel
    {
        num_threads = omp_get_num_threads();

#pragma omp for
        for (int i = 0; i < 9; i++)
        {
            printf("%d ", rev(arr[i]));
        }
    }
    printf("\n");

    double end2 = omp_get_wtime();
    double par = end2 - begin2;
    printf("Parallel time: %f\n", par / num_threads);

    double speedup = seq / par;
    printf("Speedup: %f\n", speedup);
    printf("Efficiency: %f\n", speedup / num_threads);

    return 0;
}
