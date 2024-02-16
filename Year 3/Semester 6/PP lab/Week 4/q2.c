#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[100], R[100];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    int m;
    int arr1[100], arr2[100];

    printf("Enter the size of the array: \n");
    scanf("%d", &m);

    printf("Enter %d elements:\n", m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr1[i]);
        arr2[i] = arr1[i];
    }

    // Sequential
    double begin = omp_get_wtime();

    insertionSort(arr1, m / 2);
    qsort(arr1 + m / 2, m - m / 2, sizeof(int), cmp);

    mergeSort(arr1, 0, m - 1);

    for (int i = 0; i < m; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    double end = omp_get_wtime();
    double seq = end - begin;
    printf("Sequential time: %f\n", seq);

// Parallel
#pragma omp parallel num_threads(2)
    {
        begin = omp_get_wtime();

#pragma omp sections
        {
#pragma omp section
            {
                insertionSort(arr2, m / 2);
            }

#pragma omp section
            {
                qsort(arr2 + m / 2, m - m / 2, sizeof(int), cmp);
            }
        }

        mergeSort(arr2, 0, m - 1);

        for (int i = 0; i < m; i++)
        {
            printf("%d ", arr2[i]);
        }
        printf("\n");

        end = omp_get_wtime();
        double par = end - begin;
        printf("Parallel time: %f\n", par);

        double speedup = seq / par;
        double eff = speedup / omp_get_num_threads();

        printf("Speedup: %f\nEfficiency: %f\n", speedup, eff);
    }
    return 0;
}
