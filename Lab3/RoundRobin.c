#include <stdio.h>

void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum) {
    int remaining_bt[n];
    for (int i = 0; i < n; i++) {
        remaining_bt[i] = bt[i];
    }

    int time = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_bt[i] > 0) {
                done = 0;
                if (remaining_bt[i] > quantum) {
                    time += quantum;
                    remaining_bt[i] -= quantum;
                } else {
                    time += remaining_bt[i];
                    wt[i] = time - bt[i];
                    remaining_bt[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }
}

void roundRobin(int processes[], int n, int bt[], int quantum) {
    int wt[n], tat[n];

    for (int i = 0; i < n; i++) {
        wt[i] = 0;
    }

    findWaitingTime(processes, n, bt, wt, quantum);
    findTurnaroundTime(processes, n, bt, wt, tat);

    int total_wt = 0, total_tat = 0;
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f", (float)total_tat / n);
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], bt[n];

    printf("Enter the burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d burst time: ", i + 1);
        scanf("%d", &bt[i]);
        processes[i] = i + 1;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    roundRobin(processes, n, bt, quantum);

    return 0;
}
