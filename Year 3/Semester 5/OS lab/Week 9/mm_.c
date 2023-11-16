#include <stdio.h>
#include <limits.h>

void firstFit(int blocks, int procs, int *blockSizes, int *procSizes)
{
    for (int i = 0; i < procs; i++)
    {
        int size = procSizes[i];

        int flag = 0;
        for (int j = 0; j < blocks; j++)
        {
            int block = blockSizes[j];

            if (block > size)
            {
                printf("%d\t%d", size, j);
                blockSizes[j] = blockSizes[j] - size;
                flag = 1;
                break;
            }
        }

        if (!flag)
        {
            printf("%d\tNot allocated", size);
        }
        printf("\n");
    }
}

void bestFit(int blocks, int procs, int *blockSizes, int *procSizes)
{
    for (int i = 0; i < procs; i++)
    {
        int size = procSizes[i];

        int flag = 0;
        int diff = INT_MAX;
        int diffSize = INT_MAX;
        for (int j = 0; j < blocks; j++)
        {
            int block = blockSizes[j];

            if ((block - size >= 0) && (block - size < diffSize))
            {
                diff = j;
                diffSize = block - size;
            }
        }

        if (diff == INT_MAX)
        {
            printf("%d\tNot allocated", size);
        }

        printf("%d\t%d", size, diff);
        blockSizes[diff] = blockSizes[diff] - size;

        printf("\n");
    }
}

void worstFit(int blocks, int procs, int *blockSizes, int *procSizes)
{
    for (int i = 0; i < procs; i++)
    {
        int size = procSizes[i];

        int flag = 0;
        int diff = -1;
        int diffSize = -1;
        for (int j = 0; j < blocks; j++)
        {
            int block = blockSizes[j];

            if ((block - size >= 0) && (block - size > diffSize))
            {
                diff = j;
                diffSize = block - size;
            }
        }

        if (diff == -1)
        {
            printf("%d\tNot allocated\n", size);
            continue;
        }

        printf("%d\t%d", size, diff);
        blockSizes[diff] = blockSizes[diff] - size;

        printf("\n");
    }
}

void main()
{
    int blocks, procs;
    int blockSizes[100], procSizes[100];

    printf("enter blocks, procs, blocksizes, procsizes\n");
    scanf("%d%d", &blocks, &procs);

    for (int i = 0; i < blocks; i++)
    {
        scanf("%d", &blockSizes[i]);
    }

    for (int i = 0; i < procs; i++)
    {
        scanf("%d", &procSizes[i]);
    }

    worstFit(blocks, procs, blockSizes, procSizes);
}
