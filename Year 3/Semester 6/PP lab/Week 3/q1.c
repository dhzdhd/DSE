#include <stdio.h>
#include <omp.h>
#include <malloc.h>
#include <stdlib.h>

int main()
{
	int sizes[] = {200, 400, 600, 800, 1000};
	int threads[] = {2, 4, 6, 8};
	int times[5];

	// Sequential
	for (int n = 0; n < 5; n++)
	{
		int size = sizes[n];

		int *mat1 = (int *)calloc(size * size, sizeof(int));
		int *mat2 = (int *)calloc(size * size, sizeof(int));
		int *res = (int *)calloc(size * size, sizeof(int));

		for (int j = 0; j < size * size; j++)
		{
			int r = rand() % 10 + 1;
			mat1[j] = r;
			r = rand() % 10 + 1;
			mat2[j] = r;
			res[j] = 0;
		}

		double begin = omp_get_wtime();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					res[i * n + j] += mat1[i * n + k] * mat2[k * n + j];
				}
			}
		}
		double end = omp_get_wtime();
		times[n] = end - begin;
	}

	// Parallel
	for (int n = 0; n < 5; n++)
	{
		int size = sizes[n];

		int *mat1 = (int *)calloc(size * size, sizeof(int));
		int *mat2 = (int *)calloc(size * size, sizeof(int));
		int *res = (int *)calloc(size * size, sizeof(int));

		for (int j = 0; j < size * size; j++)
		{
			int r = rand() % 10 + 1;
			mat1[j] = r;
			r = rand() % 10 + 1;
			mat2[j] = r;
			res[j] = 0;
		}

		for (int t = 0; t < 4; t++)
		{
			double start = omp_get_wtime();
			omp_set_num_threads(threads[t]);

#pragma omp parallel for collapse(3)
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					for (int k = 0; k < n; k++)
					{
						res[i * n + j] += mat1[i * n + k] * mat2[k * n + j];
					}
				}
			}

			double end = omp_get_wtime();
			double time = end - start;
			double speedup = times[n] / time;
			double eff = speedup / (int)omp_get_num_threads();

			printf("Size: %d | Thread: %d | Time: %f | Speedup: %f | Efficiency: %f\n", size, threads[t], time, speedup, eff);
		}
	}

	return 0;
}
