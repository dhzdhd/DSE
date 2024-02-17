#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define ll long

int main()
{
    double arr[] = {1.3, 2.9, 0.4, 0.3, 1.3, 4.4, 1.7, 0.4, 3.2, 0.3, 4.9, 2.4, 3.1, 4.4, 3.9, 0.4, 4.2, 4.5, 4.9, 0.9};
    int histogram[100] = {0};

    double max = arr[0];
    double min = arr[0];

    for (int i = 1; i < 20; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    double binSize = (max - min) / 10;

#pragma omp parallel for
    for (int i = 0; i < 20; i++)
    {
        int bin = (int)((arr[i] - min) / binSize);

#pragma omp critical
        {
            histogram[bin]++;
        }
    }

    printf("[Start, End) - Frequency\n");
    for (int i = 0; i < 10; i++)
    {
        double start = min + i * binSize;
        double end = start + binSize;
        printf("[%0.1f, %0.1f) - %d\n", start, end, histogram[i]);
    }
}
