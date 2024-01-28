#include <stdio.h>
#include <omp.h>
#include <time.h>

// Vars defined here are shared
int main()
{

	clock_t begin = clock();

// Default is thread per number of cores
#pragma omp parallel num_threads(5)
	{
		// Vars defined here are private per thread
		printf("Hi\n");
		int i = 0;

// For loop should have no dependency on other iterations
#pragma omp for
		for (i = 0; i < 10; i++)
		{
			printf("Hiiii\n");
		}
	}

	clock_t end = clock();
	double elapsed = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%f\n", elapsed);
	// An implicit barrier exists at the end of this block.
	// Child threads wait for others and then are terminated
	// Parent starts again

	return 0;
}
