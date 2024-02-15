// Intercalate strings

#include <stdio.h>
#include <omp.h>
#include <string.h>

int main()
{
	char str1[100], str2[100];

	printf("Enter 2 strings\n");

	gets(str1);
	gets(str2);

	// Sequential
	char buf1[100];
	int i = 0;
	int ctr = 0;

	double begin1 = omp_get_wtime();
	while (str1[i] != '\0')
	{
		buf1[ctr] = str1[i];
		ctr++;
		buf1[ctr] = str2[i];
		i++;
		ctr++;
	}
	i = 0;
	printf("%s\n", buf1);

	double end1 = omp_get_wtime();
	double seq = end1 - begin1;
	printf("Sequential time: %f\n", seq);

	// Parallel
	char buf2[100];
	int ctrr = 0;

	double begin2 = omp_get_wtime();
	double num_threads = omp_get_num_threads();
	int len = strlen(str1);

#pragma omp parallel for
	for (int i = 0; i < len; i++)
	{
		buf2[ctrr] = str1[i];
		ctrr++;
		buf2[ctrr] = str2[i];
		i++;
		ctrr++;
	}
	printf("%s\n", buf2);

	double end2 = omp_get_wtime();
	double par = end2 - begin2;
	printf("Parallel time: %f\n", par);

	double speedup = seq / par;
	printf("Speedup: %f\n", speedup);
	printf("Efficiency: %f\n", speedup / num_threads);

	return 0;
}
