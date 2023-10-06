#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *tcode(void *param)
{
        int *arr = (int *)param;
        int prime[100];
        int c = 0;

        for (int i = arr[0]; i <= arr[1]; i++)
        {
                int flag = 1;
                for (int j = 2; j < i; j++)
                {
                        if (i % j == 0)
                        {
                                flag = 0;
                                break;
                        }
                }
                if (flag)
                        prime[c++] = i;
        }

        for (int i = 0; i < c; i++)
        {
                printf("%d\t", prime[i]);
        }
        printf("\n");
}

int main()
{
        pthread_t t;

        int a, b;

        printf("Enter 2 numbers\n");
        scanf("%d%d", &a, &b);

        int arr[2];
        arr[0] = a;
        arr[1] = b;

        pthread_create(&t, NULL, &tcode, (void *)arr);
        pthread_join(t, 0);

        return 0;
}
