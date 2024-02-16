#include <stdio.h>
#include <omp.h>

int main()
{
  int vec1[100];
  int vec2[100];
  int sum[100], diff[100], mul[100];
  int n;

  printf("Enter size of vec\n");
  scanf("%d", &n);

  printf("Enter corresponding elements\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d%d", &vec1[i], &vec2[i]);
  }

  // Sequential
  double start = omp_get_wtime();

  for (int i = 0; i < n; i++)
  {
    sum[i] = vec1[i] + vec2[i];
    diff[i] = vec1[i] - vec2[i];
    mul[i] = vec1[i] * vec2[i];
  }

  printf("Sum, Diff, Mul\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d %d %d", sum[i], diff[i], mul[i]);
    printf("\n");
  }

  double end = omp_get_wtime();
  double seq = end - start;
  printf("Seq time: %f\n", seq);

  // Parallel
  start = omp_get_wtime();

#pragma omp parallel num_threads(3)
#pragma omp sections
  {

#pragma omp section
    for (int i = 0; i < n; i++)
    {
      sum[i] = vec1[i] + vec2[i];
    }

#pragma omp section
    for (int i = 0; i < n; i++)
    {
      diff[i] = vec1[i] - vec2[i];
    }

#pragma omp section
    for (int i = 0; i < n; i++)
    {
      mul[i] = vec1[i] * vec2[i];
    }
  }

  printf("Sum, Diff, Mul\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d %d %d", sum[i], diff[i], mul[i]);
    printf("\n");
  }

  end = omp_get_wtime();
  double par = end - start;
  printf("Parallel time: %f\n", par);

  double speedup = seq / par;
  double eff = speedup / omp_get_num_threads();

  printf("Speedup: %f, Efficiency: %f\n", speedup, eff);

  return 0;
}
