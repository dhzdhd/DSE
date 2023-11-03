#include <stdio.h>
#include <stdlib.h>

int *queue;
int capacity, mutex = 1, ctr = 0;

void producer()
{
        mutex = 0;
        ctr++;
        printf("Producer produces item %d\n", ctr);
        mutex = 1;
}

void consumer()
{
        mutex = 0;
        printf("Consumer consumes item %d\n", ctr);
        ctr--;
        mutex = 1;
}

int main()
{
        int choice;

        printf("Enter capacity\n");
        scanf("%d", &capacity);

        printf("Choices\n1: Produce\n2: Consume\n3: Exit\n");

        for (;;)
        {
                printf("Enter choice\n");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                        if ((mutex == 1) && (ctr != capacity))
                        {
                                producer();
                        }
                        else
                        {
                                printf("Buffer full\n");
                        };
                        break;
                case 2:
                        if ((mutex == 1) && (ctr != 0))
                        {
                                consumer();
                        }
                        else
                        {
                                printf("Buffer empty\n");
                        }
                        break;
                case 3:
                        exit(0);
                }
        }

        return 0;
}
