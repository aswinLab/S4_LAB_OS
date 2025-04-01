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

void firstFit(struct MemoryBlock blocks[], struct Process processes[], int numBlocks, int numProcesses) {
    for (int i = 0; i < numProcesses; i++) {
        int j;
       
        for (j = 0; j < numBlocks; j++) {
            if (blocks[j].size >= processes[i].size && blocks[j].occupied == 0) {
              
                blocks[j].occupied = 1;
                printf("Process %d of size %d allocated to Block %d of size %d\n", 
                       processes[i].id, processes[i].size, j+1, blocks[j].size);
                break;
            }
        }
        if (j == numBlocks) {
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

    
    firstFit(blocks, processes, numBlocks, numProcesses);

    return 0;
}

/*1	200
2	500
3	100
4	300
5	600
Processes:
Process ID	Process Size
1	210
2	415
3	100
4	90
5	200*/

