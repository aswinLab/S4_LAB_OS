#include "shm_util.h"

void write_to_shm() {
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    char *shm_ptr = shmat(shmid, NULL, 0);
    if (shm_ptr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    char message[] = "Hello from System V shared memory!";
    strcpy(shm_ptr, message);
    printf("Writer wrote: %s\n", message);

    shmdt(shm_ptr);
}
