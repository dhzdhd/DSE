// Matrix times vector

#include <stdio.h>
#include <omp.h>

int main()
{
    int m[100][100], v[100][100], res1[100][100], res2[100][100];
    int m1, m2, v1, v2;

    printf("Enter mat dims\n");
    scanf("%d%d", &m1, &m2);
    printf("Enter vec dims\n");
    scanf("%d%d", &v1, &v2);

    if (m2 != v1)
    {
        printf("Can't multiply\n");
        return 0;
    }

    printf("Enter matrix\n");
    int i, j, k;
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < m2; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }

    printf("Enter vec\n");
    for (i = 0; i < v1; i++)
    {
        for (j = 0; j < v2; j++)
        {
            scanf("%d", &v[i][j]);
        }
    }

    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < m2; j++)
        {
            res1[i][j] = 0;
            res2[i][j] = 0;
        }
    }

    // Sequential
    double begin1 = omp_get_wtime();
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < v2; j++)
        {
            for (k = 0; k < m2; k++)
            {
                res1[i][j] += m[i][k] * v[k][j];
            }
        }
    }

    printf("Seq Result\n");
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < v2; j++)
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

#pragma omp parallel for collapse(3)
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < v2; j++)
        {
            for (k = 0; k < m2; k++)
            {
                res2[i][j] += m[i][k] * v[k][j];
            }
        }
    }

    printf("Parallel Result\n");
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < v2; j++)
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
