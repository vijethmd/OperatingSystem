#include <stdio.h>

int findOptimal(int frame[], int capacity, int pages[], int current, int n) {
    int farthest = -1, index = -1;
    for (int i = 0; i < capacity; i++) {
        int j;
        for (j = current + 1; j < n; j++) {
            if (frame[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        if (j == n) {
            return i;
        }
    }
    return index;
}

void Optimal(int pages[], int n, int capacity) {
    int frame[capacity], pageFaults = 0, pageHits = 0;

    for (int i = 0; i < capacity; i++) {
        frame[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                flag = 1;
                pageHits++;
                break;
            }
        }

        if (flag == 0) {
            pageFaults++;
            int replaceIndex = findOptimal(frame, capacity, pages, i, n);
            frame[replaceIndex] = pages[i];
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

    Optimal(pages, n, capacity);

    return 0;
}
