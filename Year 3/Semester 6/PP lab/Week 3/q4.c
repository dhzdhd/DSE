#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binary_to_int(char *str)
{
    int val = 0;
    int power = 1;
    int len = strlen(str);

    for (int i = 4; i >= 0; i--)
    {
        val += (str[i] - '0') * power;
        power *= 2;
    }

    return val;
}

int main()
{
    int m[100][100], res[100][100], ress[100][100];
    int m1, m2;

    printf("Enter mat dims\n");
    scanf("%d%d", &m1, &m2);

    printf("Enter matrix\n");
    int i, j, k;
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < m2; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }

    // Sequential
    double begin1 = omp_get_wtime();

    printf("Seq B\n");
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < m2; j++)
        {
            if (i == 0 || i == m1 - 1 || j == 0 || j == m2 - 1)
            {
                printf("%d ", m[i][j]);
            }
            else
            {
                char *buf = calloc(sizeof(int) * 8 + 1, sizeof(int));
                itoa(m[i][j], buf, 2);

                for (int z = 0; z < sizeof(int) * 8; z++)
                {
                    buf[z] = (buf[z] == '0') ? '1' : '0';
                };

                printf("%d ", binary_to_int(buf));
            }
        }
        printf("\n");
    }

    printf("Seq C\n");
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < m2; j++)
        {
            if (i == 0 || i == m1 - 1 || j == 0 || j == m2 - 1)
            {
                printf("%d ", m[i][j]);
            }
            else
            {
                char *buf = calloc(sizeof(int) * 2 + 1, sizeof(int));
                itoa(m[i][j], buf, 2);

                for (int z = 0; z < sizeof(int) * 8; z++)
                {
                    buf[z] = (buf[z] == '0') ? '1' : '0';
                };

                printf("%s ", buf);
            }
        }
        printf("\n");
    }

    double end1 = omp_get_wtime();
    double seq = end1 - begin1;
    printf("Sequential time: %f\n", seq);

    // Parallel
    double begin2 = omp_get_wtime();
    double num_threads = omp_get_num_threads();

    printf("Parallel B\n");
#pragma omp parallel for collapse(2)
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < m2; j++)
        {
            if (i == 0 || i == m1 - 1 || j == 0 || j == m2 - 1)
            {
                printf("%d ", m[i][j]);
            }
            else
            {
                char *buf = calloc(sizeof(int) * 8 + 1, sizeof(int));
                itoa(m[i][j], buf, 2);

                for (int z = 0; z < sizeof(int) * 8; z++)
                {
                    buf[z] = (buf[z] == '0') ? '1' : '0';
                };

                printf("%d ", binary_to_int(buf));
            }
        }
    }
    printf("\n");

    printf("Parallel C\n");
#pragma omp parallel for collapse(2)
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < m2; j++)
        {
            if (i == 0 || i == m1 - 1 || j == 0 || j == m2 - 1)
            {
                printf("%d ", m[i][j]);
            }
            else
            {
                char *buf = calloc(sizeof(int) * 2 + 1, sizeof(int));
                itoa(m[i][j], buf, 2);

                for (int z = 0; z < sizeof(int) * 8; z++)
                {
                    buf[z] = (buf[z] == '0') ? '1' : '0';
                };

                printf("%s ", buf);
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
