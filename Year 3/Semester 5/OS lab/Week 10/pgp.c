#include <stdio.h>

void fifo(int frames, int pages, int *str, int *res)
{
    int frameC = 0, faults = 0;

    for (int i = 0; i < pages; i++)
    {
        int cur = str[i];
        int flag = 0;
        for (int j = 0; j < frames; j++)
        {
            if (cur == res[j])
            {
                flag = 1;
            }
        }

        if (!flag)
        {
            res[frameC] = cur;
            frameC = (frameC + 1) % 3;
            faults++;
        }

        for (int j = 0; j < frames; j++)
        {
            printf("%d\t", res[j]);
        }
        printf("\n");
    }
}

void lru(int frames, int pages, int *str, int *res)
{
    int frameC = 0, faults = 0;
    int used[100];

    for (int i = 0; i < frames; i++)
    {
        used[i] = 0;
    }

    for (int i = 0; i < pages; i++)
    {
        int cur = str[i];

        if (res[frameC] == -1)
        {
            res[frameC] = cur;
            frameC = (frameC + 1) % frames;
            faults++;
        }
        else
        {
            int flag = 0;
            for (int j = 0; j < frames; j++)
            {
                if (cur == res[j])
                {
                    flag = 1;
                    used[j] = 0;
                }
            }

            if (!flag)
            {
                int max = 0;
                for (int j = 0; j < frames; j++)
                {
                    if (used[j] > used[max])
                    {
                        max = j;
                    }
                }

                res[max] = cur;
                faults++;
                used[max] = 0;
            }
        }

        for (int j = 0; j < frames; j++)
        {
            if (res[j] != -1)
            {
                used[j]++;
            }
            printf("%d\t", res[j]);
        }
        printf("\n");
    }
}

void optimal(int frames, int pages, int *str, int *res)
{
    int frameC = 0, faults = 0;

    for (int i = 0; i < pages; i++)
    {
        int cur = str[i];

        if (res[frameC] == -1)
        {
            res[frameC] = cur;
            frameC = (frameC + 1) % frames;
            faults++;
        }
        else
        {
            int flag = 0;
            for (int j = 0; j < frames; j++)
            {
                if (cur == res[j])
                {
                    flag = 1;
                }
            }

            if (!flag)
            {
                int optimal = -1;
                int dist = 0;
                int maxDist = -1;

                int f = 0;
                for (int k = 0; k < frames; k++)
                {
                    for (int j = i + 1; j < pages; j++)
                    {
                        if (res[k] == str[j])
                        {
                            break;
                        }
                        dist++;
                    }
                    if (dist > maxDist)
                    {
                        maxDist = dist;
                        optimal = k;
                    }
                    dist = 0;
                }

                res[optimal] = cur;
                faults++;
            }
        }

        for (int j = 0; j < frames; j++)
        {
            printf("%d\t", res[j]);
        }
        printf("\n");
    }
}

int main()
{
    int frames, pages, str[100];
    int res[100];

    printf("Enter frames, pages\n");
    scanf("%d%d", &frames, &pages);

    for (int i = 0; i < pages; i++)
    {
        scanf("%d", &str[i]);
    }

    for (int i = 0; i < frames; i++)
    {
        res[i] = -1;
    }

    lru(frames, pages, str, res);
}
