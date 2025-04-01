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

void worstFit(struct MemoryBlock blocks[], struct Process processes[], int numBlocks, int numProcesses) {
    for (int i = 0; i < numProcesses; i++) {
        int worstBlockIndex = -1;
        int maxRemainingSpace = -1;

        for (int j = 0; j < numBlocks; j++) {
            if (blocks[j].size >= processes[i].size && blocks[j].occupied == 0) {
                int remainingSpace = blocks[j].size - processes[i].size;

                if (remainingSpace > maxRemainingSpace) {
                    maxRemainingSpace = remainingSpace;
                    worstBlockIndex = j;
                }
            }
        }

        if (worstBlockIndex != -1) {
            blocks[worstBlockIndex].occupied = 1;
            printf("Process %d of size %d allocated to Block %d of size %d (Remaining space: %d)\n",
                   processes[i].id, processes[i].size, worstBlockIndex + 1, blocks[worstBlockIndex].size, maxRemainingSpace);
        } else {
            printf("Process %d of size %d could not be allocated\n", processes[i].id, processes[i].size);
        }
    }
}

int main() {
    struct MemoryBlock blocks[MAX_BLOCKS] = {
        {200, 0}, {500, 0}, {100, 0}, {300, 0}, {600, 0}};

    struct Process processes[MAX_PROCESSES] = {
        {1, 210}, {2, 415}, {3, 100}, {4, 90}, {5, 200}};

    int numBlocks = 5, numProcesses = 5;

    worstFit(blocks, processes, numBlocks, numProcesses);

    return 0;
}

