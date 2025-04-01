#include "shm_util.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <write|read>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "write") == 0) {
        write_to_shm();
    } else if (strcmp(argv[1], "read") == 0) {
        read_from_shm();
    } else {
        printf("Invalid argument. Use 'write' or 'read'.\n");
        return 1;
    }

    return 0;
}
