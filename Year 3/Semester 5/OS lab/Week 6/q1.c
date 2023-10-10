#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *tcode(void *param)
{
        int *arr = (int *)param;
        int sum = 0;
        int n = arr[101];

        for (int i = 0; i < n; i++)
        {
                sum += arr[i];
        }

        return (void *)sum;
}

int main()
{
        pthread_t t;
        int r_val;
        int n;

        printf("Enter number of elements\n");
        scanf("%d", &n);

        int arr[101];

        printf("Enter elements\n");
        for (int i = 0; i < n; i++)
        {
                scanf("%d", &arr[i]);
        }
        arr[101] = n;

        pthread_create(&t, NULL, &tcode, (void *)arr);
        pthread_join(t, (void **)&r_val);

        printf("Sum is %d\n", r_val);

        return 0;
}
