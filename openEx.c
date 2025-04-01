
#include<sys/wait.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main(){
	char readBuff[100];
	ssize_t buffRead;
	int fd;
	char *command = "nano";
	char *file_path = malloc(100*sizeof(char)); 
	printf("enter the file path and file name you want to create/open : ");
	fgets(file_path, 100, stdin);
	file_path[strcspn(file_path, "\n")] = '\0';
	char  *args[] = {"nano", "-M", file_path,NULL};
	fd = open(file_path, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if(fd == -1){
		perror("An error occured during opening file/creating file\n");
		return -1;
	}
	char *data = malloc(100*sizeof(char));
	printf("enter something to write\n");
	fgets(data, 100, stdin);
	data[strcspn(data, "\n")] = '\0';
	ssize_t bytewritten = write(fd, data, strlen(data));
	if(bytewritten == -1){
		perror("error writing into the file\n");
		close(fd);
		return 1;
	}
	printf("data succefullt written into file : %s\n", file_path);
	printf("opening file please wait...\n");
	pid_t pid = fork();
	if(pid == 0){
		sleep(2);
		if(execvp(command, args)){
			perror("exec failed critically\n");
		}
		exit(7);
	}
	if(pid > 0){
		int status;
		printf("waiting for the file to be opened\n");
		wait(&status);
		if(WIFEXITED(status)){
			printf("opened file with status : %d\n", status );
		}
	
	}
	close(fd);
	fd = open(file_path, O_RDONLY);
	buffRead = read(fd,readBuff, sizeof(readBuff)-1);
	readBuff[buffRead] = '\0';
	printf("read %zd bytes: \n%s\n",buffRead,readBuff);
	close(fd);
	return 0;
}
