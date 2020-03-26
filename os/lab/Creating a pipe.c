#include<stdio.h>
#include<stdlib.h>
void main(){
    int pipe1[2];
    char buff[100]={0},buff1[100]={0};
    pipe(pipe1);
    read(0,buff1,100);
    write(pipe1[1],buff1,100);
    read(pipe1[0],buff,100);
    write(1,buff,100);
}