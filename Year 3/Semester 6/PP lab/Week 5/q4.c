#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define ll long

int main()
{
    ll a, b, sum = 0;

    printf("Enter range\n");
    scanf("%ld%ld", &a, &b);

    // Static
    double start = omp_get_wtime();

#pragma omp parallel for schedule(static) reduction(+ : sum)
    for (int i = 0; i < b - a; i++)
    {
        sum += i + b;
    }

    double end = omp_get_wtime();
    double stat = end - start;
    printf("Time taken for static scheduling: %f\n", stat);

    // Dynamic
    start = omp_get_wtime();

#pragma omp parallel for schedule(dynamic) reduction(+ : sum)
    for (int i = 0; i < b - a; i++)
    {
        sum += i + b;
    }

    end = omp_get_wtime();
    double dyn = end - start;
    printf("Time taken for dynamic scheduling: %f\n", dyn);

    // Guided
    start = omp_get_wtime();

#pragma omp parallel for schedule(guided) reduction(+ : sum)
    for (int i = 0; i < b - a; i++)
    {
        sum += i + b;
    }

    end = omp_get_wtime();
    double guided = end - start;
    printf("Time taken for guided scheduling: %f\n", guided);

    // Runtime
    start = omp_get_wtime();

#pragma omp parallel for schedule(runtime) reduction(+ : sum)
    for (int i = 0; i < b - a; i++)
    {
        sum += i + b;
    }

    end = omp_get_wtime();
    double runtime = end - start;
    printf("Time taken for runtime scheduling: %f\n", runtime);

    return 0;
}
