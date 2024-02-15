// Pattern

#include <stdio.h>
#include <omp.h>

int main()
{
	int n;
	printf("Enter num\n");
	scanf("%d", &n);

	char str[] = "PCBD";

	// Sequential
	double begin1 = omp_get_wtime();

	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j <= i; j++)
		{
			printf("%c", str[i % 4]);
		}
	}
	printf("\n");

	double end1 = omp_get_wtime();
	double seq = end1 - begin1;
	printf("Sequential time: %f\n", seq);

	// Parallel
	double begin2 = omp_get_wtime();
	double num_threads = omp_get_num_threads();

#pragma omp parallel for
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j <= i; j++)
		{
			printf("%c", str[i % 4]);
		}
	}
	printf("\n");

	double end2 = omp_get_wtime();
	double par = end2 - begin2;
	printf("Parallel time: %f\n", par);

	double speedup = seq / par;
	printf("Speedup: %f\n", speedup);
	printf("Efficiency: %f\n", speedup / num_threads);
}
