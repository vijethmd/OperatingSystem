#include <stdio.h>

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];

    
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    
    for (int i = 0; i < n; i++) {
        int worstIdx = -1;
        for (int j = 0; j < m; j++) {
            
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]) {
                    worstIdx = j;
                }
            }
        }


        if (worstIdx != -1) {
           
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i]; 
        }
    }

   
    printf("\nProcess No\tProcess Size\tBlock No\tBlock Size\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1) {
            printf("P%d\t\t%d\t\tB%d\t\t%d\n", i + 1, processSize[i],
                   allocation[i] + 1, blockSize[allocation[i]]);
        } else {
            printf("P%d\t\t%d\t\tNot Allocated\t\t-\n", i + 1, processSize[i]);
        }
    }
}

int main() {
    int m, n;

   
    printf("Enter the number of blocks: ");
    scanf("%d", &m);

    int blockSize[m];
    
    printf("Enter the size of each block:\n");
    for (int i = 0; i < m; i++) {
        printf("Block %d size: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

   
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processSize[n];
    
    printf("Enter the size of each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d size: ", i + 1);
        scanf("%d", &processSize[i]);
    }

  
    worstFit(blockSize, m, processSize, n);

    return 0;
}
