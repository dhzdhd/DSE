#include <stdlib.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct
{
        int n;
        int *arr;
} Pass;

void *compEven(void *p)
{
        Pass *param = (Pass *)p;
        int n = param->n;
        int *arr = param->arr;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
                if (arr[i] % 2 == 0)
                {
                        sum += arr[i];
                }
        }

        return (void *)sum;
}

void *compOdd(void *p)
{
        Pass *param = (Pass *)p;
        int n = param->n;
        int *arr = param->arr;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
                if (arr[i] % 2 != 0)
                {
                        sum += arr[i];
                }
        }

        return (void *)sum;
}

int main()
{
        pthread_t t1, t2;
        int r1, r2;
        int n, arr[100];
        Pass pass;

        printf("Enter number of elements\n");
        scanf("%d", &n);

        printf("Enter numbers\n");
        for (int i = 0; i < n; i++)
        {
                scanf("%d", &arr[i]);
        }

        pass.n = n;
        pass.arr = arr;

        pthread_create(&t1, NULL, &compOdd, (void *)&pass);
        pthread_create(&t2, NULL, &compEven, (void *)&pass);

        pthread_join(t1, (void **)&r1);
        pthread_join(t2, (void **)&r2);

        printf("Sum of odd is %d and even is %d\n", r1, r2);

        return 0;
}
