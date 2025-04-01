#include <stdio.h>

#define MAX_BLOCKS 5
#define MAX_PROCESSES 5


struct MemoryBlock {
    int size; 
    int occupied;
};


struct Process {
    int id;
    int size;
};

void bestFit(struct MemoryBlock blocks[], struct Process processes[], int numBlocks, int numProcesses) {
    for (int i = 0; i < numProcesses; i++) {
        int bestBlockIndex = -1;
        int minRemainingSpace = 99999; 

        for (int j = 0; j < numBlocks; j++) {
            if (blocks[j].size >= processes[i].size && blocks[j].occupied == 0) {
                int remainingSpace = blocks[j].size - processes[i].size;
               
                if (remainingSpace < minRemainingSpace) {
                    minRemainingSpace = remainingSpace;
                    bestBlockIndex = j;
                }
            }
        }

        if (bestBlockIndex != -1) {
           
            blocks[bestBlockIndex].occupied = 1;
            printf("Process %d of size %d allocated to Block %d of size %d (Remaining space: %d)\n", 
                   processes[i].id, processes[i].size, bestBlockIndex+1, blocks[bestBlockIndex].size, minRemainingSpace);
        } else {
            printf("Process %d of size %d could not be allocated\n", processes[i].id, processes[i].size);
        }
    }
}

int main() {
    struct MemoryBlock blocks[MAX_BLOCKS] = {
        {200, 0},
        {500, 0}, 
        {100, 0}, 
        {300, 0},
        {600, 0} 
    };

    // Define some processes
    struct Process processes[MAX_PROCESSES] = {
        {1, 210},
        {2, 415}, 
        {3, 100}, 
        {4, 90}, 
        {5, 200}  
    };

    int numBlocks = 5;
    int numProcesses = 5;

    // Call bestFit function
    bestFit(blocks, processes, numBlocks, numProcesses);

    return 0;
}

/*Block 1: 100
Block 2: 250
Block 3: 300
Block 4: 350
Block 5: 500
Processes (Sizes):
Process 1: 200
Process 2: 150
Process 3: 100
Process 4: 80
Process 5: 120*/

