#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *tcode(void *param)
{
        int id = (int)param;
        printf("Start thread %i\n", id);
        printf("Greetings from thread\n");

        return (void *)id;
}

int main()
{
        pthread_t t[3];
        int r_val[3];

        for (int i = 0; i < 3; i++)
        {
                pthread_create(&t[i], NULL, &tcode, (void *)i);
        }

        for (int i = 0; i < 3; i++)
        {
                pthread_join(t[i], (void **)&r_val[i]);
                printf("End thread %i\n", r_val[i]);
        }

        return 0;
}
