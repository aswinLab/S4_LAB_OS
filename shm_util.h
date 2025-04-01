#ifndef SHM_UTIL_H
#define SHM_UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>

#define SHM_KEY 1234
#define SHM_SIZE 1024

void write_to_shm();
void read_from_shm();

#endif
