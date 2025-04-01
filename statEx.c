#include<stdio.h>
#include<sys/stat.h>
#include<time.h>
#include<stdlib.h>
const char *file_path = "/home/student/aswinBash/isPrime.sh";


int main(){

struct stat file_info;

if(stat(file_path, &file_info) == -1){
	perror("Stat critical failure, Aborting..");
	return EXIT_FAILURE;
}

printf("size : %ld bytes\n", file_info.st_size);
printf("block size : %ld\n", file_info.st_blksize);
printf("Number of links : %lu\n", file_info.st_nlink);
printf("permissions: ");
printf((file_info.st_mode & S_IRUSR) ? "r\n" : "-\n");
printf((file_info.st_mode & S_IWUSR) ? "w\n" : "-\n");
printf((file_info.st_mode & S_IXUSR) ? "x\n" : "-\n");
printf("Last time of modification : %s", ctime(&file_info.st_mtime));
printf("Last time of Accessing : %s", ctime(&file_info.st_atime));
printf("User id : %d\n", file_info.st_uid);
if(S_ISREG(file_info.st_mode)){
	printf("regular file\n");
}
else{
	printf("Not a regular file, could be a directory\n");
}
return EXIT_SUCCESS;
}
