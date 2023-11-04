#include <stdio.h>

int main()
{
        int n_blocks, n_required, block_size[10], required_size[10], avail1[10], avail2[10], avail3[10];

        printf("Memory Blocks: ");
        scanf("%d", &n_blocks);
        printf("Required Blocks: ");
        scanf("%d", &n_required);
        printf("Memory Block Sizes: ");
        for (int i = 0; i < n_blocks; i++)
                scanf("%d", &block_size[i]);
        printf("Required Block Sizes: ");
        for (int i = 0; i < n_required; i++)
                scanf("%d", &required_size[i]);
        for (int i = 0; i < n_blocks; i++)
        {
                avail1[i] = block_size[i];

                avail2[i] = block_size[i];
                avail3[i] = block_size[i];
        }

        printf("\nWorst fit\n");
        for (int i = 0; i < n_required; i++)
        {
                int best_index = -1;
                for (int j = 0; j < n_blocks; j++)
                {
                        if (required_size[i] <= avail1[j])
                        {
                                if (best_index == -1)
                                        best_index = j;
                                else if (avail1[j] > avail1[best_index])
                                        best_index = j;
                        }
                }
                if (best_index == -1)
                        printf("%d Size Process Not Allocated\n", required_size[i]);
                else
                {
                        printf("%d Size Memory Block -> %d Size Process\n", block_size[best_index], required_size[i]);
                        avail1[best_index] -= required_size[i];
                }
        }

        printf("\nFirst fit\n");
        for (int i = 0; i < n_required; i++)
        {
                int allocated = 0;

                for (int j = 0; j < n_blocks; j++)
                {
                        if (required_size[i] <= avail2[j])
                        {
                                printf("%d Size Memory Block -> %d Size Process\n", block_size[j], required_size[i]);
                                avail2[j] -= required_size[i];
                                allocated = 1;
                                break;
                        }
                }
                if (!allocated)
                        printf("%d Size Process Not Allocated\n", required_size[i]);
        }

        printf("\nBest fit\n");
        for (int i = 0; i < n_required; i++)
        {
                int best_index = -1;

                for (int j = 0; j < n_blocks; j++)
                {
                        if (required_size[i] <= avail3[j])
                        {
                                if (best_index == -1)
                                        best_index = j;
                                else if (avail3[j] < avail3[best_index])
                                        best_index = j;
                        }
                }

                if (best_index == -1)
                        printf("%d Size Process Not Allocated\n", required_size[i]);
                else
                {
                        printf("%d Size Memory Block -> %d Size Process\n", block_size[best_index], required_size[i]);
                        avail3[best_index] -= required_size[i];
                }
        }
}
