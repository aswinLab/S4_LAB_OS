#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
	
	pid_t pid = fork();
	if(pid == 0){
		printf("child process %d running \n", getpid());
		sleep(4);
		printf("child process %d has ended \n", getpid());
		exit(5);
	}
	if(pid > 0){
		printf("parent process %d waiting for child process to terminate..\n", getpid());
		int status;
		wait(&status);
		printf("parent process %d confirms that child process is over\n", getpid());
		if(WIFEXITED(status)){
			printf("child process has completed exicuting..status : %d\n", WIFEXITED(status));
		}
		else{
			printf("child process cant be terminated normally\n");
		}
	}
	else{
		printf("fork failed..terminating operation\n");
		exit(EXIT_FAILURE);
	}
	
}
