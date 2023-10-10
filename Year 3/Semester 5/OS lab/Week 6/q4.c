#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct
{
        int n;
        int *arr;
} Arr;

void *tcode(void *param)
{
        int arr[100];
        Arr *res = (Arr *)param;

        arr[0] = 0;
        arr[1] = 1;

        for (int i = 2; i < res->n; i++)
        {
                arr[i] = arr[i - 1] + arr[i - 2];
        }

        res->arr = arr;
        return (void *)res;
}

int main()
{
        pthread_t t;
        Arr r;
        int n;

        printf("Enter the number\n");
        scanf("%d", &n);

        r.n = n;

        pthread_create(&t, NULL, &tcode, (void *)&r);
        pthread_join(t, (void **)&r);

        for (int i = 0; i < n; i++)
        {
                printf("%d\t", r.arr[i]);
        }
        printf("\n");

        return 0;
}
