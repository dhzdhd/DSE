#include <stdio.h>
#include <math.h>
#include <omp.h>
#include <string.h>

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
	double begin1 = omp_get_wtime();

	char i = 0;
	while (str1[i] != '\0')
	{
		str1[i] = (int)str1[i] < 91 ? (char)((int)str1[i] + 32) : (char)((int)str1[i] - 32);
		i++;
	}
	printf("%s\n", str1);

	double end1 = omp_get_wtime();
	double seq = end1 - begin1;
	printf("Sequential time: %f\n", seq);

	// Parallel
	int len = strlen(str2);

	double begin2 = omp_get_wtime();
	int num_threads;

#pragma omp parallel
	{
		num_threads = omp_get_num_threads();

#pragma omp for
		for (int j = 0; j < len; j++)
		{
			str2[j] = (int)str2[j] < 91 ? (char)((int)str2[j] + 32) : (char)((int)str2[j] - 32);
		}
	}
	printf("%s\n", str2);

	double end2 = omp_get_wtime();
	double par = end2 - begin2;
	printf("Parallel time: %f\n", par / num_threads);

	double speedup = seq / par;
	printf("Speedup: %f\n", speedup);
	printf("Efficiency: %f\n", speedup / num_threads);

	return 0;
}
