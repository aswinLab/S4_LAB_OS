
#include <stdio.h>
#define MAX_FRAMES 3
#define MAX_PAGES 10
// Function to find the index of the page in the frame
int is_page_in_frame(int frames[], int page, int frame_count) {
for (int i = 0; i < frame_count; i++) {
if (frames[i] == page)
return i;
}
return -1;
}
void lru_page_replacement(int pages[], int num_pages) {
int frames[MAX_FRAMES] = {-1, -1, -1}; // -1 means frame is empty
int time[MAX_FRAMES] = {0, 0, 0}; // Time tracking for each frame
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
// If the page is already in the frame, no page fault
if (frame_index != -1) {
printf("\nPage %d is already in frame.\n", current_page);
time[frame_index] = time_counter++;
}
else {

// Page fault, find an empty frame or replace the least recently used page
int lru_index = 0;
for (int j = 1; j < MAX_FRAMES; j++) {
if (time[j] < time[lru_index]) {
lru_index = j;}}

// Replace the least recently used page
frames[lru_index] = current_page;
time[lru_index] = time_counter++;
page_faults++;
printf("\nPage %d loaded into frame %d.\n", current_page, lru_index);
}
printf("Frames: ");
for (int j = 0; j < MAX_FRAMES; j++) {
if (frames[j] != -1) {
printf("%d ", frames[j]);
}
else {
printf("Empty ");}}
printf("\n");
}

printf("\nTotal Page Faults: %d\n", page_faults);
}
int main() {
int pages[MAX_PAGES] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3};
int num_pages = 10; // Number of pages in the reference string
lru_page_replacement(pages, num_pages);
return 0;
}