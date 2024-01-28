#include <stdio.h>
#include <math.h>
#include <omp.h>
#include <time.h>

int main()
{
	int a, b;

	printf("Enter num1, num2\n");
	scanf("%d%d", &a, &b);

	// Sequential
	clock_t begin1 = clock();

	printf("Sum %d\n", a + b);
	printf("Difference %d\n", a - b);
	printf("Product %d\n", a * b);
	printf("Quotient %d\n", a / b);

	clock_t end1 = clock();
	double seq = (double)(end1 - begin1) / CLOCKS_PER_SEC;
	printf("Sequential time: %f\n", seq);

	// Parallel
	clock_t begin2 = clock();
	int num_procs;

#pragma omp parallel num_threads(4)
	{
		num_procs = omp_get_num_threads();
		int thread = omp_get_thread_num();

		if (thread == 0)
		{
			printf("Sum %d\n", a + b);
		}
		else if (thread == 1)
		{
			printf("Difference %d\n", a - b);
		}
		else if (thread == 2)
		{
			printf("Product %d\n", a * b);
		}
		else
		{
			printf("Quotient %d\n", a / b);
		}
	}
	clock_t end2 = clock();
	double par = (double)(end2 - begin2) / CLOCKS_PER_SEC;
	printf("Parallel time: %f\n", par / num_procs);

	double speedup = seq / par;
	printf("Speedup: %f\n", speedup);
	printf("Efficiency: %f\n", speedup / num_procs);

	return 0;
}
