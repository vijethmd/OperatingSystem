#include <stdio.h>
void preemptiveSJF(int n, int AT[], int BT[], int CT[], int TAT[], int WT[], int RT[])
{
    int remaining_BT[n];
    int completed = 0, time = 0, min_BT, shortest;
    int flag[n];
    for (int i = 0; i < n; i++)
    {
        remaining_BT[i] = BT[i];
        flag[i] = 0;
    }

    while (completed < n)
    {
        min_BT = 9999;
        shortest = -1;
        for (int i = 0; i < n; i++)
        {
            if (AT[i] <= time && remaining_BT[i] > 0 && remaining_BT[i] < min_BT && flag[i] == 0)
            {
                min_BT = remaining_BT[i];
                shortest = i;
            }
        }
        if (shortest == -1)
        {
            time++;
            continue;
        }
        remaining_BT[shortest]--;
        if (remaining_BT[shortest] == 0)
        {
            completed++;
            flag[shortest] = 1;
            CT[shortest] = time + 1;
            TAT[shortest] = CT[shortest] - AT[shortest];
            WT[shortest] = TAT[shortest] - BT[shortest];
            RT[shortest] = WT[shortest];
        }
        time++;
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
        printf("Enter process %d  Arrival Time: ", i + 1);
        scanf("%d", &AT[i]);
        printf("Enter process %d  Burst Time: ", i + 1);
        scanf("%d", &BT[i]);
    }
    preemptiveSJF(n, AT, BT, CT, TAT, WT, RT);
    display(n, AT, BT, CT, TAT, WT, RT);

    return 0;
}
