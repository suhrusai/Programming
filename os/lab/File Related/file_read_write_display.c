#include<stdio.h>
#include<sys/stat.h>
void main(){
        int fid1,fid2,i;
        char buff[1000];
        fid1 = open("add.c",0);
        creat("sample1.c",S_IRWXU);
        fid2=open("sample1.c",2);
        read(0,buff,10);
        write(fid2,buff,10);
        write(1,buff,10);
        close(fid1);
        close(fid2);
}
//Qestion 1
