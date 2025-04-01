#include <stdio.h>
#include <unistd.h>

#define FRAMES 6
#define PAGES 8

int pages[PAGES] = {1, 1, 2, 3, 2, 5, 7, 2};

//int pages[PAGES] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int pageRef(int frames[], int page) {
    for (int i = 0; i < FRAMES; i++) {
        if (frames[i] == page)  
            return 1;
    }
    return 0;
}


void pgreplace() {
    int frames[FRAMES];
    int pageFault = 0;
    int front = 0; 

    
    for (int i = 0; i < FRAMES; i++) {
        frames[i] = -1;
    }

    printf("Page Request  |  Memory Frames  |  Page Miss?\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < PAGES; i++) {
        int page = pages[i];

       
        if (!pageRef(frames, page)) {
            frames[front] = page;  
            front = (front + 1) % FRAMES; 
            pageFault++;

            printf("%3d            | ", page);

            for (int j = 0; j < FRAMES; j++) {
                if (frames[j] == -1)
                    printf("- ");
                else
                    printf("%d ", frames[j]);
            }
            printf(" |  Yes\n");  
        } else {
            printf("%3d            | ", page);
            for (int j = 0; j < FRAMES; j++) {
                if (frames[j] == -1)
                    printf("- ");
                else
                    printf("%d ", frames[j]);
            }
            printf(" |  No\n");  
        }
    }

    printf("-------------------------------------------------\n");
    printf("Total Page Faults = %d\n", pageFault);
}

int main() {
    pgreplace();
    return 0;
}

