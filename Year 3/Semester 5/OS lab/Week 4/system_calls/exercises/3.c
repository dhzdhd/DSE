#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    pid_t pid = fork();

    if (pid == 0)
    {
        qsort(arr, n, sizeof(int), compare);
        printf("Sorted array: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        exit(0);
    }
    else
    {
        wait(NULL);
    }

    return 0;
}

// Enter the number of elements in the array: 3
// Enter the elements of the array: 5
// 2
// 3
// Unsorted array: 5 2 3
// Sorted array: 2 3 5
