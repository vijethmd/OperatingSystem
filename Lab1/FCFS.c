#include <stdio.h>
void main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int AT[n], BT[n], WT[n], TAT[n], CT[n], RT[n];
    printf("Enter AT and BT for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter AT and BT for the process %d: ", i + 1);
        scanf("%d %d", &AT[i], &BT[i]);
    }
    int currentTime = 0;
    float totalWT = 0, totalTAT = 0;
    printf("\nProcess\tAT\tBT\tWT\tTAT\tRT\n");
    for (int i = 0; i < n; i++) {
         if (currentTime < AT[i])
            currentTime = AT[i];
        CT[i] = currentTime + BT[i];
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
        RT[i] = CT[i] - AT[i];
        totalWT += WT[i];
        totalTAT += TAT[i];
        printf("%d\t%d\t%d\t%d\t%d\t\t%d\n", i + 1, AT[i], BT[i], WT[i], TAT[i], RT[i]);
        currentTime = CT[i];
    }
    printf("\nAverage Waiting Time: %.2f", totalWT / n);
    printf("\nAverage Turnaround Time: %.2f\n", totalTAT / n);
}
