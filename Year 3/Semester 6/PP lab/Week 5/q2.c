#include <stdio.h>
#include <omp.h>

int main() {
  int n, vec1[100], vec2[100];
  int sum1[100], sum2[100], sum3[100], sum4[100], sum5[100];

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter elements\n");
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &vec1[i], &vec2[i]);
  }  

  #pragma omp parallel
  {
    #pragma omp critical
    for (int i = 0; i < n; i++) {
      sum1[i] = vec1[i] + vec2[i];
    }

    #pragma omp atomic
    for (int i = 0; i < n; i++) {
      sum2[i] = vec1[i] + vec2[i];
    }

    //#pragma omp critical
    //for (int i = 0; i < n; i++) {
    //  sum3[i] = vec1[i] + vec2[i];
    //}

    //#pragma omp critical
    //for (int i = 0; i < n; i++) {
    //  sum4[i] = vec1[i] + vec2[i];
    //}

    //#pragma omp critical
    //for (int i = 0; i < n; i++) {
    //  sum5[i] = vec1[i] + vec2[i];
    //}

}
  printf("Critical, Atomic, Reduction, Master, Locks\n");
  for (int i = 0; i < n; i++) {
    printf("%d %d %d %d %d", sum1[i], sum2[i], sum3[i], sum4[i], sum5[i]);
    printf("\n");
  } 

  return 0;
}

