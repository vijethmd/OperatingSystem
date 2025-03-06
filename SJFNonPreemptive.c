#include <stdio.h>
#include <limits.h>

typedef struct {
    int id, arrival, burst, remaining, waiting, turnaround, completion, response, started;
} Process;

void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

void sortByArrival(Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival > p[j + 1].arrival) {
                swap(&p[j], &p[j + 1]);
            }
        }
    }
}


void sjfNonPreemptive(Process p[], int n) {
    int completed = 0, time = 0;

    while (completed < n) {
        int minIndex = -1, minBurst = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time && p[i].completion == 0) {
                if (p[i].burst < minBurst || (p[i].burst == minBurst && p[i].arrival < p[minIndex].arrival)) {
                    minBurst = p[i].burst;
                    minIndex = i;
                }
            }
        }

        if (minIndex == -1) {
            time++;
            continue;
        }

        p[minIndex].response = time - p[minIndex].arrival;
        time += p[minIndex].burst;
        p[minIndex].completion = time;
        p[minIndex].turnaround = p[minIndex].completion - p[minIndex].arrival;
        p[minIndex].waiting = p[minIndex].turnaround - p[minIndex].burst;
        completed++;
    }
}

void displayResults(Process p[], int n, const char *title) {
    printf("\n--- %s ---\n", title);
    printf("\nPID\tAT\tBT\tCT\tTAT\n");

    float totalWT = 0, totalTAT = 0, totalRT = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t\n", p[i].id, p[i].arrival, p[i].burst, p[i].turnaround, p[i].waiting);
        totalWT += p[i].waiting;
        totalTAT += p[i].turnaround;
        totalRT += p[i].response;
    }

    printf("Average WT: %.2f\n", totalWT / n);
    printf("Average TAT : %.2f\n", totalTAT / n);
    printf("Average RT: %.2f\n", totalRT / n);
}

int main() {
    int n, choice;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n], temp[n];

    printf("Enter Arrival Time and Burst Time:\n");
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        scanf("%d %d", &p[i].arrival, &p[i].burst);
        p[i].remaining = p[i].burst;
        p[i].waiting = p[i].turnaround = p[i].completion = p[i].response = p[i].started = 0;
        temp[i] = p[i];
    }

        for (int i = 0; i < n; i++) p[i] = temp[i];


        sjfNonPreemptive(p, n);
        displayResults(p, n, "SJF (Non-Preemptive)");

    }
