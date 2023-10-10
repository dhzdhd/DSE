#include <stdio.h>
#include <pthread.h>

void *tcode(void *param)
{
        printf("Greetings from thread\n");
}

int main()
{
        pthread_t t;
        pthread_create(&t, NULL, &tcode, NULL);
        printf("Greetings from main thread\n");

        return 0;
}
