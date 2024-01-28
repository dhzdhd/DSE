#include <stdio.h>
#include <omp.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int sizes[] = {200, 400, 600, 800, 1000};
	int threads[] = {2, 4, 6, 8};

	for (int n = 0; n < 5; n++)
	{
		int size = sizes[n];

		int **mat1 = (int *)calloc(size, sizeof(int));
		int **mat2 = (int *)calloc(size, sizeof(int));
		int **mat3 = (int *)calloc(size, sizeof(int));

		for (int i = 0; i < size; i++)
		{
			mat1[i] = calloc(size, sizeof(int));
			mat2[i] = calloc(size, sizeof(int));
			mat3[i] = calloc(size, sizeof(int));

			for (int j = 0; j < size; j++)
			{
				int r = rand() % 10 + 1;
				mat1[i][j] = r;
				r = rand() % 10 + 1;
				mat2[i][j] = r;
			}
		}

		for (int t = 0; t < 4; t++)
		{
			double start = clock();
			omp_set_num_threads(threads[t]);

			int sum = 0;
#pragma omp parallel for collapse(3) shared(sum)
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					sum = 0;
					for (int k = 0; k < n; k++)
					{
						sum += mat1[i][k] * mat2[k][j];
					}
					mat3[i][j] = sum;
				}
			}

			//			mul(mat1, mat2, mat3, size);
			double end = clock();

			printf("Size: %d | Thread: %d | Time: %f\n", size, threads[t], end - start);
		}
	}

	return 0;
}
