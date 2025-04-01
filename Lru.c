#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 10

int is_page_in_frame(int frames[], int page, int frame_count) {
    for (int i = 0; i < frame_count; i++) {
        if (frames[i] == page)
            return i;
    }
    return -1;
}

void lru_page_replacement(int pages[], int num_pages) {
    int frames[MAX_FRAMES] = {-1, -1, -1}; 
    int time[MAX_FRAMES] = {0, 0, 0};     
    int page_faults = 0;
    int time_counter = 0;

    printf("Page Reference: ");
    for (int i = 0; i < num_pages; i++) {
        printf("%d ", pages[i]);
    }
    printf("\n");

    for (int i = 0; i < num_pages; i++) {
        int current_page = pages[i];
        int frame_index = is_page_in_frame(frames, current_page, MAX_FRAMES);

        if (frame_index != -1) {
            printf("\nPage %d is already in frame.\n", current_page);
            time[frame_index] = time_counter++; 
        } else {
            int empty_index = -1;
            for (int j = 0; j < MAX_FRAMES; j++) {
                if (frames[j] == -1) {
                    empty_index = j;
                    break;
                }
            }
            
            if (empty_index != -1) {
                printf("\nFilling empty frame %d with %d.\n", empty_index, current_page);
                frames[empty_index] = current_page;
                time[empty_index] = time_counter++;
            } else {
                int lru_index = 0;
                for (int j = 1; j < MAX_FRAMES; j++) {
                    if (time[j] < time[lru_index]) {
                        lru_index = j;
                    }
                }
                printf("\nReplacing page %d with %d.\n", frames[lru_index], current_page);
                frames[lru_index] = current_page;
                time[lru_index] = time_counter++;
            }
            page_faults++;
        }

        printf("Frames: ");
        for (int k = 0; k < MAX_FRAMES; k++) {
            printf("%d ", frames[k]);
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", page_faults);
}

int main() {
    int pages[MAX_PAGES] = {7, 0, 1, 2, 0, 3, 4, 2, 3, 0};
    int num_pages = 10;
    lru_page_replacement(pages, num_pages);
    return 0;
}