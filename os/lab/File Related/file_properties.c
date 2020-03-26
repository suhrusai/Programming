#include<stdio.h>
#include<sys/stat.h>
void main(){
        struct stat str;
        stat("sample1.c",&str);
        printf("\nFile mode %ld",str.st_mode);
        printf("\nDevice:  %ld",str.st_dev);
        printf("\nFile mode %ld",str.st_mode);
        printf("\nInode %ld",str.st_ino);
        printf("\nNumber of links: %ld",str.st_nlink);
        printf("\nUser id: %ld",str.st_uid);
        printf("\nGroup id: %ld",str.st_gid);
        printf("\nFile mode %ld",str.st_rdev);
        printf("\nBlock size %ld",str.st_blksize);
        printf("\nNo of blocks: %ld",str.st_blocks);
}