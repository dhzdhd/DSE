// Matrix times vector

#include <stdio.h>
#include <omp.h>
#include <malloc.h>
#include <stdlib.h>

int main()
{
    int m[300][300], v[300][300], res1[300][300], res2[300][300];
    int sizes[3] = {100, 200, 300};

    for (int size = 0; size < 3; size++)
    {
        int m1 = sizes[size];
        int m2 = m1;
        int v2 = m1 / 10;

        printf("Size: %d\n", sizes[size]);
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < m2; j++)
            {

                res1[i][j] = 0;
                res2[i][j] = 0;
                m[i][j] = rand() % 10 + 1;
                v[i][j] = rand() % 10 + 1;
            }
        }

        // Sequential
        double begin1 = omp_get_wtime();
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < v2; j++)
            {
                for (int k = 0; k < m2; k++)
                {
                    res1[i][j] += m[i][k] * v[k][j];
                }
            }
        }

        double end1 = omp_get_wtime();
        double seq = end1 - begin1;
        printf("Sequential time: %f\n", seq);

        // Parallel
        double begin2 = omp_get_wtime();
        double num_threads = omp_get_num_threads();

#pragma omp parallel for collapse(3)
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < v2; j++)
            {
                for (int k = 0; k < m2; k++)
                {
                    res2[i][j] += m[i][k] * v[k][j];
                }
            }
        }

        double end2 = omp_get_wtime();
        double par = end2 - begin2;
        printf("Parallel time: %f\n", par);

        double speedup = seq / par;
        printf("Speedup: %f\n", speedup);
        printf("Efficiency: %f\n", speedup / num_threads);

        printf("\n\n");
    }

    return 0;
}
