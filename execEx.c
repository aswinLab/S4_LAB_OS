#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
	char *args[] = {"/bin/ls", "-l", "/home/student/aswinBash/", NULL};
	pid_t pid = fork();
	
	if(pid < 0){
		printf("fork critical failure! Exiting...\n");
		exit(EXIT_FAILURE);
	}
	
	else if(pid > 1){
		int status;
		printf("parent process is waiting for child to terminate...\n");
		wait(&status);
		if(WIFEXITED(status)){
			printf("child process exited, confirmed by parent\n");
		}
	}
	
	else{
		printf("child process running ls command...\n");
		
		execv(args[0], args);
		
		perror("exec failed!\n");
		
		exit(EXIT_SUCCESS);
	}
	
	return 0;		
}
