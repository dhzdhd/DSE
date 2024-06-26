// Arithmetic operations

#include <stdio.h>
#include <math.h>
#include <omp.h>

int main()
{
	int a, b;

	printf("Enter num1, num2\n");
	scanf("%d%d", &a, &b);

	// Sequential
	double begin1 = omp_get_wtime();

	printf("Sum %d\n", a + b);
	printf("Difference %d\n", a - b);
	printf("Product %d\n", a * b);
	printf("Quotient %d\n", a / b);

	double end1 = omp_get_wtime();
	double seq = end1 - begin1;
	printf("Sequential time: %f\n", seq);

	// Parallel
	double begin2 = omp_get_wtime();
	int num_threads;

#pragma omp parallel num_threads(4)
	{
		num_threads = omp_get_num_threads();

#pragma omp sections
		{

#pragma omp section
			{
				printf("Sum %d\n", a + b);
			}
#pragma omp section
			{
				printf("Difference %d\n", a - b);
			}
#pragma omp section
			{
				printf("Product %d\n", a * b);
			}
#pragma omp section
			{
				printf("Quotient %d\n", a / b);
			}
		}
	}
	double end2 = omp_get_wtime();
	double par = end2 - begin2;
	printf("Parallel time: %f\n", par / num_threads);

	double speedup = seq / par;
	printf("Speedup: %f\n", speedup);
	printf("Efficiency: %f\n", speedup / num_threads);

	return 0;
}
