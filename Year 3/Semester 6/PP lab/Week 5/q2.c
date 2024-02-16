#include <stdio.h>
#include <omp.h>

int main()
{
  int n, vec[100];
  int sum1, sum2, sum3, sum4, sum5;
  omp_lock_t lock;

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter elements\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &vec[i]);
  }

#pragma omp parallel for
  for (int i = 0; i < n; i++)
  {
#pragma omp critical
    sum1 += vec[i];
  }

#pragma omp parallel for
  for (int i = 0; i < n; i++)
  {
#pragma omp atomic
    sum2 += vec[i];
  }

#pragma omp parallel for reduction(+ : sum3)
  for (int i = 0; i < n; i++)
  {
    sum3 += vec[i];
  }

#pragma omp parallel
  for (int i = 0; i < n; i++)
  {
#pragma omp master
    sum4 += vec[i];
  }

#pragma omp parallel
  {
    omp_init_lock(&lock);

#pragma omp for
    for (int i = 0; i < n; i++)
    {
      omp_set_lock(&lock);
      sum5 += vec[i];
      omp_unset_lock(&lock);
    }
    omp_destroy_lock(&lock);
  }

  printf("Critical, Atomic, Reduction, Master, Locks\n");
  printf("%d %d %d %d %d", sum1, sum2, sum3, sum4, sum5);
  printf("\n");

  return 0;
}
