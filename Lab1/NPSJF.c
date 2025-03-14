#include <stdio.h>
void NPSJF(int n, int AT[], int BT[], int CT[], int TAT[], int WT[], int RT[])
{
    int completed = 0, time = 0, min_BT, shortest, finish_time;
    int remaining_BT[n];
    for (int i = 0; i < n; i++)
    {
        remaining_BT[i] = BT[i];
    }

    while (completed < n)
    {
        min_BT = 9999;
        shortest = -1;
        for (int i = 0; i < n; i++)
        {
            if (AT[i] <= time && remaining_BT[i] > 0 && BT[i] < min_BT)
            {
                min_BT = BT[i];
                shortest = i;
            }
        }
        if (shortest == -1)
        {
            time++;
            continue;
        }
        time += BT[shortest];
        remaining_BT[shortest] = 0;
        completed++;
        CT[shortest] = time;
        TAT[shortest] = CT[shortest] - AT[shortest];
        WT[shortest] = TAT[shortest] - BT[shortest];
        RT[shortest] = WT[shortest];
    }
}

void display(int n, int AT[], int BT[], int CT[], int TAT[], int WT[], int RT[])
{
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, AT[i], BT[i], CT[i], TAT[i], WT[i], RT[i]);
    }
}

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int AT[n], BT[n], CT[n], TAT[n], WT[n], RT[n];
    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter process %d AT: ", i + 1);
        scanf("%d", &AT[i]);
        printf("Enter process %d BT: ", i + 1);
        scanf("%d", &BT[i]);
    }
    NPSJF(n, AT, BT, CT, TAT, WT, RT);
    display(n, AT, BT, CT, TAT, WT, RT);
    return 0;
}
