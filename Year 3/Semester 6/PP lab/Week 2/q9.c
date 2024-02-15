// Matrix pattern

#include <stdio.h>

int main()
{
    int m[100][100];
    char c[100][100];
    char s[1000];
    int m1, m2;

    printf("Enter mat dims\n");
    scanf("%d%d", &m1, &m2);

    printf("Enter matrix\n");
    int i, j, k;
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < m2; j++)
        {
            getchar();
            scanf("%c ", &c[i][j]);
            scanf("%d", &m[i][j]);
        }
    }

    // Sequential
    double begin1 = omp_get_wtime();

    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < m2; j++)
        {
            for (k = 0; k < m[i][j]; k++)
            {
                printf("%c", c[i][j]);
            }
        }
    }
    printf("\n");

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
            for (k = 0; k < m[i][j]; k++)
            {
                printf("%c", c[i][j]);
            }
        }
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
