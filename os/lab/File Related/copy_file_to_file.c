#include<stdio.h>
#include<sys/stat.h>
#include <fcntl.h> 
void main(){
        int fid1,fid2;
        struct stat str;
        stat("file type.c",&str);
        char bf[1];
        int i=0;
        fid1 = open("name.txt",0);
        creat("sample.c",S_IRWXU);
        fid2=open("sample.c",2);
        read(fid1,bf,1);
        while(i<str.st_size){
                read(fid1,bf,1);
                write(fid2,bf,1);
                i++;
        }
        // write(1,buff,1000);
        close(fid1);
        close(fid2);
}