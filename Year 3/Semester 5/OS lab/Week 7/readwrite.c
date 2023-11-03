#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex;
int rc = 0;

void *writer(void *a)
{
    int arg = (int)a;

    pthread_mutex_lock(&mutex);

    printf("W - %d operating\n", arg);
    printf("W - %d done\n", arg);

    pthread_mutex_unlock(&mutex);
}

void *reader(void *a)
{
    int arg = (int)a;

    pthread_mutex_lock(&mutex);

    rc++;
    printf("R - %d operating\n", arg);
    rc--;
    printf("R - %d done\n", arg);

    pthread_mutex_unlock(&mutex);
}

int main()
{
    int r, w;

    printf("Enter number of readers and writers: ");
    scanf("%d %d", &r, &w);

    pthread_t readers[r], writers[w];
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < r || i < w; i++)
    {
        if (i < r)
            pthread_create(&readers[i], NULL, reader, (void *)i + 1);
        if (i < w)
            pthread_create(&writers[i], NULL, writer, (void *)i + 1);
        i++;
    }

    for (int i = 0; i < r || i < w; i++)
    {
        if (i < r)
            pthread_join(readers[i], NULL);
        if (i < w)
            pthread_join(writers[i], NULL);
        i++;
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}
