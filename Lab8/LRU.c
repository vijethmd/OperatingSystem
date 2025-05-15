#include <stdio.h>

void LRU(int pages[], int n, int capacity) {
    int frame[capacity], time[capacity], pageFaults = 0, pageHits = 0;

    for (int i = 0; i < capacity; i++) {
        frame[i] = -1;
        time[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int flag = 0, leastRecent = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                flag = 1;
                pageHits++;
                time[j] = i;
                break;
            }
        }

        if (flag == 0) {
            pageFaults++;
            for (int j = 0; j < capacity; j++) {
                if (frame[j] == -1) {
                    frame[j] = pages[i];
                    time[j] = i;
                    break;
                }
            }
            if (flag == 0) {
                leastRecent = 0;
                for (int j = 1; j < capacity; j++) {
                    if (time[j] < time[leastRecent]) {
                        leastRecent = j;
                    }
                }
                frame[leastRecent] = pages[i];
                time[leastRecent] = i;
            }
        }
    }

    printf("Page Faults: %d\n", pageFaults);
    printf("Page Hits: %d\n", pageHits);
}

int main() {
    int n, capacity;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter pages:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter frame capacity: ");
    scanf("%d", &capacity);

    LRU(pages, n, capacity);

    return 0;
}
