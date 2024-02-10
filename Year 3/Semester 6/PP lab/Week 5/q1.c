#include <stdio.h>
#include <omp.h>


int main() {
  int vec1[100];
  int vec2[100];
  int sum[100], diff[100], mul[100], div[100];
  int n;

  printf("Enter size of vec\n");
  scanf("%d", &n);

  printf("Enter corresponding elements\n");
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &vec1[i], &vec2[i]);
  }

  #pragma omp parallel shared(n) num_threads(4) 
  #pragma omp sections
  {  

    #pragma omp section
    for (int i = 0; i < n; i++) {
       sum[i] = vec1[i] + vec2[i];
    }  
    
    #pragma omp section
    for (int i = 0; i < n; i++) {
       diff[i] = vec1[i] - vec2[i];
    }
    
    #pragma omp section
    for (int i = 0; i < n; i++) {
       mul[i] = vec1[i] * vec2[i];
    }

    #pragma omp section
    for (int i = 0; i < n; i++) {
       div[i] = vec1[i] / vec2[i];
    }
  }

  printf("Sum, Diff, Mul, Div\n");
  for (int i = 0; i < n; i++) {
    printf("%d %d %d %d", sum[i], diff[i], mul[i], div[i]);
    printf("\n");
  }

  return 0;
}
