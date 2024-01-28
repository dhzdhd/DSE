#include <stdio.h>
#include <math.h>
#include <omp.h>
#include <time.h>

int rev(int num)
{
	int buf = 0;
	while (num > 0)
	{
		buf = (10 * buf) + num % 10;
		num = num / 10;
	}

	return buf;
	printf("%d\n", buf);
}

int main()
{
	int arr1[100], arr2[100], n;

	printf("Enter num of elements\n");
	scanf("%d", &n);

	printf("Enter elements\n");
	int i = 0;
	for (; i < n; i++)
	{
		scanf("%d", arr1 + i);
		arr2[i] = arr1[i];
	}

	// Sequential
	clock_t begin1 = clock();

	for (i = 0; i < n; i++)
	{
		arr1[i] = rev(arr1[i]);
		printf("%d ", arr1[i]);
	}
	printf("\n");

	clock_t end1 = clock();
	double seq = (double)(end1 - begin1) / CLOCKS_PER_SEC;
	printf("Sequential time: %f\n", seq);

	// Parallel
	clock_t begin2 = clock();
	int num_procs;

#pragma omp parallel
	{
		num_procs = omp_get_num_threads();

#pragma omp for
		for (i = 0; i < n; i++)
		{
			arr2[i] = rev(arr2[i]);
			printf("%d ", arr2[i]);
		}
	}
	printf("\n");

	clock_t end2 = clock();
	double par = (double)(end2 - begin2) / CLOCKS_PER_SEC;
	printf("Parallel time: %f\n", par / num_procs);

	double speedup = seq / par;
	printf("Speedup: %f\n", speedup);
	printf("Efficiency: %f\n", speedup / num_procs);

	return 0;
}
