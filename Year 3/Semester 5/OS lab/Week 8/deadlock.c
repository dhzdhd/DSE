#include <stdio.h>
#include <stdlib.h>

int i, j;
int avail[3];
int alloc[10][3];
int req[10][3];
int n;

int detect_deadlock(int n)
{
        int work[3];
        for (i = 0; i < 3; i++)
                work[i] = avail[i];

        int mark[10];
        for (i = 0; i < n; i++)
                mark[i] = 0;

        for (i = 0; i < n; i++)
        {
                int count = 0;
                for (j = 0; j < 3; j++)
                {
                        if (alloc[i][j] == 0)
                                count++;
                        else
                                break;
                }
                if (count == 3)
                        mark[i] = 1;
        }

        int canbeprocessed = 0;
        for (int k = 0; k < n; k++)
        {
                for (i = 0; i < n; i++)
                {
                        canbeprocessed = 0;
                        if (mark[i] != 1)
                        {
                                for (j = 0; j < 3; j++)
                                {
                                        if (req[i][j] <= work[j])
                                                canbeprocessed = 1;
                                        else
                                        {
                                                canbeprocessed = 0;
                                                break;
                                        }
                                }
                                if (canbeprocessed == 1)
                                {
                                        mark[i] = 1;

                                        for (j = 0; j < 3; j++)
                                                work[j] += alloc[i][j];
                                }
                        }
                }
        }

        int deadlock = 0;
        for (i = 0; i < n; i++)
                if (mark[i] != 1)
                        deadlock = 1;

        return deadlock;
}

void main()
{

        printf("Processes: \n");
        scanf("%d", &n);

        printf("Available: \n");
        for (i = 0; i < 3; i++)
                scanf("%d", &avail[i]);

        printf("\nEnter Allocated Table:\n");
        for (i = 0; i < n; i++)
        {
                for (j = 0; j < 3; j++)
                {
                        scanf("%d", &alloc[i][j]);
                }
        }

        printf("\nEnter Requested Table:\n");
        for (i = 0; i < n; i++)
        {
                for (j = 0; j < 3; j++)
                {
                        scanf("%d", &req[i][j]);
                }
        }

        int flag;
        flag = detect_deadlock(n);

        if (flag == 1)
                printf("System: No Safe!\n");
        else
                printf("System: Safe\n");
}
