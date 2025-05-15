#include <stdio.h>

void FIFO(int pages[], int n, int capacity) {
    int frame[capacity];
    int pageFaults = 0;
    int pageHits = 0;

    for (int i = 0; i < capacity; i++) {
        frame[i] = -1;
    }

    int front = 0;

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
            frame[front] = pages[i];
            front = (front + 1) % capacity;
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

    FIFO(pages, n, capacity);

    return 0;
}
