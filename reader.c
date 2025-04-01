#include "shm_util.h"

void read_from_shm() {
    int shmid = shmget(SHM_KEY, SHM_SIZE, 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    char *shm_ptr = shmat(shmid, NULL, 0);
    if (shm_ptr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    printf("Reader read: %s\n", shm_ptr);

    shmdt(shm_ptr);
    shmctl(shmid, IPC_RMID, NULL); 
}
