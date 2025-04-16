#include <stdio.h>
#include <stdlib.h>


int mutex = 1;
int full = 0;
int empty = 3;
int x = 0;


int wait(int s);
int signal(int s);
void producer();
void consumer();

int main() {
    int choice;

    printf("Producer-Consumer Problem using Semaphores (Buffer size = 3)\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Produce\n");
        printf("2. Consume\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if ((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("Buffer is full! Cannot produce.\n");
                break;

            case 2:
                if ((mutex == 1) && (full != 0))
                    consumer();
                else
                    printf("Buffer is empty! Cannot consume.\n");
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}


int wait(int s) {
    return (--s);
}


int signal(int s) {
    return (++s);
}


void producer() {
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);

    x++; 
    printf("Producer produced item %d\n", x);

    mutex = signal(mutex);
}


void consumer() {
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);

    printf("Consumer consumed item %d\n", x);
    x--;

    mutex = signal(mutex);
}
