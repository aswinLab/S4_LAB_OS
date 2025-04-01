#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<string.h>

#define SHM_KEY 1234
#define SHM_SIZE 1024

void write_to_shm(){
	int shmid = shmget(SHM_KEY,SHM_SIZE, IPC_CREAT | 0666);
	if(shmid==-1){
		perror("shmget");
		exit(1);
	}

char *shm_ptr = shmat(shmid, NULL,0);
if(shm_ptr == (char *) -1){
	perror("shmat");
	exit(1);
}

char message[] = "hello from shared memory";
strcpy(shm_ptr, message);
printf("writer wrote: %s\n", message);
shmdt(shm_ptr);
}

void read_from_shm(){

int shmid = shmget(SHM_KEY, SHM_SIZE, 0666);
if(shmid == -1){
	perror("shmget");
	exit(1);
}

char *shm_ptr = shmat(shmid, NULL, 0);

if(shm_ptr == (char *)  -1){
	perror("shmat");
	exit(1);
}

printf("Reader Read: %s\n", shm_ptr);

shmdt(shm_ptr);

shmctl(shmid, IPC_RMID, NULL);
}


int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Usage : %s <write|read>", argv[0]);
		return 1;
	}
	if(strcmp(argv[1], "write")==0){
		write_to_shm();
	}
	else if(strcmp(argv[1], "read")==0){
		read_from_shm();
	}
	else{
		printf("invalid argument, use write or read\n");
		return 1;
	}
	return 0;
}


