#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main()
{
    int n, arr[100], parr[100], t, speedup, eff;

    printf("Enter number of threads\n");
    scanf("%d", &t);

    printf("Enter size of array\n");
    scanf("%d", &n);

    printf("Enter elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        parr[i] = arr[i];
    }

    // Seq
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
            if (min != i)
            {
                swap(&arr[min], &arr[i]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Par
    int min = 0;

    for (int i = 0; i < n - 1; i++)
    {
        min = i;

#pragma omp parallel for shared(min, parr) ordered
        for (int j = i + 1; j < n; j++)
        {
            if (parr[j] < parr[min])
            {
                min = j;
            }
            if (min != i)
            {
                swap(&parr[min], &parr[i]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", parr[i]);
    }
    printf("\n");
}
