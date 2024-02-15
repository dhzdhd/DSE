// Diagonal matrix manipulation

#include <stdio.h>
#include <omp.h>

int main()
{
    int m[100][100], res1[100][100], res2[100][100];
    int max[100], min[100];
    int m1 = 5, m2 = 5;

    printf("Enter matrix\n");
    int i, j;
    for (i = 0; i < m1; i++)
    {
        int maxx = 0;
        int minn = 9999999;
        for (j = 0; j < m2; j++)
        {
            scanf("%d", &m[i][j]);
            if (m[i][j] > maxx)
            {
                maxx = m[i][j];
            }
            if (m[i][j] < minn)
            {
                minn = m[i][j];
            }
        }
        max[i] = maxx;
        min[i] = minn;
    }

    // Sequential
    double begin1 = omp_get_wtime();
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < m2; j++)
        {
            if (i == j)
            {
                res1[i][j] = 0;
            }
            else if (i < j)
            {
                res1[i][j] = min[i];
            }
            else
            {
                res1[i][j] = max[i];
            }
        }
    }

    printf("Seq Result\n");
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < m2; j++)
        {
            printf("%d ", res1[i][j]);
        }
        printf("\n");
    }

    double end1 = omp_get_wtime();
    double seq = end1 - begin1;
    printf("Sequential time: %f\n", seq);

    // Parallel
    double begin2 = omp_get_wtime();
    double num_threads = omp_get_num_threads();

#pragma omp parallel for collapse(2)
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < m2; j++)
        {
            if (i == j)
            {
                res2[i][j] = 0;
            }
            else if (i < j)
            {
                res2[i][j] = min[i];
            }
            else
            {
                res2[i][j] = max[i];
            }
        }
    }

    printf("Parallel Result\n");
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < m2; j++)
        {
            printf("%d ", res2[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    double end2 = omp_get_wtime();
    double par = end2 - begin2;
    printf("Parallel time: %f\n", par);

    double speedup = seq / par;
    printf("Speedup: %f\n", speedup);
    printf("Efficiency: %f\n", speedup / num_threads);

    return 0;
}
