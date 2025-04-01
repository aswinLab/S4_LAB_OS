#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>

int main(){
	const char *dir_path = "/home";
	DIR *dir = opendir(dir_path);
		if(dir == NULL){
			perror("the given path doesnt exist or there is a spelling mistake\n");
			return EXIT_FAILURE;
		}
	printf("content of dir :  %s \n", dir_path);
	struct dirent *entry;
	while((entry = readdir(dir)) != NULL){
		printf("%s\n", entry->d_name);
	}
	if(closedir(dir) == -1){
		perror("close dir failed\n");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
