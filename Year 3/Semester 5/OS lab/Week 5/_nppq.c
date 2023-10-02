#include <stdlib.h>
#include <stdio.h>

void main()
{
    int pn = 0;
    int cpu = 0;

    printf("No. of Processes: ");
    scanf("%d", &pn);

    int at[100];
    int att[100];
    int nop = pn;
    int pt[100];
    int PP[100];
    int ppt[100];
    int wt[100];
    int tat[100];
    int i = 0;

    for (i = 0; i < pn; i++)
    {
        printf("\nBurst Time P%d: ", i + 1);
        scanf("%d", &pt[i]);

        printf("Priority P%d: ", i + 1);
        scanf("%d", &PP[i]);

        ppt[i] = PP[i];

        printf("Arrival Time P%d: ", i + 1);
        scanf("%d", &at[i]);
        att[i] = at[i];
    }

    int lat = 0;
    for (i = 0; i < pn; i++)
        if (at[i] > lat)
            lat = at[i];

    int max_p = 0;

    for (i = 0; i < pn; i++)
        if (ppt[i] > max_p)
            max_p = ppt[i];

    int ati = 0;
    int P1 = ppt[0];
    int P2 = ppt[0];
    int j = -1;

    while (nop > 0 && cpu <= 1000)
    {
        for (i = 0; i < pn; i++)
        {
            if ((att[i] <= cpu) && (att[i] != (lat + 10)))
            {
                if (ppt[i] != (max_p + 1))
                {
                    P2 = ppt[i];
                    j = 1;
                    if (P2 < P1)
                    {
                        j = 1;
                        ati = i;
                        P1 = ppt[i];
                        P2 = ppt[i];
                    }
                }
            }
        }

        if (j == -1)
        {
            cpu = cpu + 1;
            continue;
        }
        else
        {
            wt[ati] = cpu - att[ati];
            cpu = cpu + pt[ati];
            tat[ati] = cpu - att[ati];
            att[ati] = lat + 10;
            j = -1;
            ppt[ati] = max_p + 1;
            ati = 0;
            P1 = max_p + 1;
            P2 = max_p + 1;
            nop = nop - 1;
        }
    }

    printf("\nPN\tPT\tPP\tAT\tWT\tTT\n\n");

    for (i = 0; i < pn; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, pt[i], PP[i], at[i], wt[i],
               tat[i]);
    }

    int avgwt = 0;
    int avgtat = 0;

    for (i = 0; i < pn; i++)
    {
        avgwt = wt[i] + avgwt;
        avgtat = tat[i] + avgtat;
    }

    printf("Avg Waitting Time = %d\nAvg Turnaround Time = %d\n", avgwt / pn, avgtat / pn);
    return 0;
}
