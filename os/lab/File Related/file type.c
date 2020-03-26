 #include<stdio.h>
#include<sys/stat.h>
void main(int argc, char * argv[]){
	struct stat str;
	stat(argv[1],&str);
	if(S_ISDIR(str.st_mode))
		printf("Directrory");
	else if(S_ISCHR(str.st_mode))
		printf("Chjaracter file");
	else if(S_ISBLK(str.st_mode))
		printf("Block file");
	else if(S_ISFIFO(str.st_mode))
		printf("FIFO file");
	else
		printf("Unknown");
}