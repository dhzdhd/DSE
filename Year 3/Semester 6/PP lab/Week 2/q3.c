#include <stdio.h>
#include <math.h>
#include <omp.h>
#include <time.h>

int main()
{
	char str1[100], str2[100];

	printf("Enter string\n");
	gets(str1);
	int j = 0;
	for (j = 0; str1[j] != '\0'; j++)
	{
		str2[j] = str1[j];
	}

	// Sequential
	clock_t begin1 = clock();

	char i = 0;
	while (str1[i] != '\0')
	{
		str1[i] = (int)str1[i] < 91 ? (char)((int)str1[i] + 32) : (char)((int)str1[i] - 32);
		i++;
	}
	printf("%s\n", str1);

	clock_t end1 = clock();
	double seq = (double)(end1 - begin1) / CLOCKS_PER_SEC;
	printf("Sequential time: %f\n", seq);

	// Parallel
	i = 0;

	clock_t begin2 = clock();
	int num_procs;

#pragma omp parallel
	{
		num_procs = omp_get_num_threads();

#pragma omp for
		// Cannot use != or ==
		for (int j = 0; str2[j] != '\0'; j++)
		{
			str2[j] = (int)str2[j] < 91 ? (char)((int)str2[j] + 32) : (char)((int)str2[j] - 32);
		}
	}
	printf("%s\n", str2);

	clock_t end2 = clock();
	double par = (double)(end2 - begin2) / CLOCKS_PER_SEC;
	printf("Parallel time: %f\n", par / num_procs);

	double speedup = seq / par;
	printf("Speedup: %f\n", speedup);
	printf("Efficiency: %f\n", speedup / num_procs);

	return 0;
}
