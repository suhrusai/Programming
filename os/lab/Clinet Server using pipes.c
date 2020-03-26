#include<stdio.h>
#include<string.h>
void main(){
        int pipe1[2],pipe2[2];
        if(pipe(pipe1)<0 || pipe(pipe2)<0){
                printf("Pipes out of stock");
                return;
        }
        if(fork()){
                //Parent processs
                //close(pipe1[1]);
                //close(pipe2[0]);
                //Clienr side
                char buff[1000]={};
                read(0,buff,100);
                write(pipe2[1],buff,100);
                wait(NULL);
                read(pipe1[0],buff,100);
                //printf("Server Response: ");
                write(1,buff,100);
        }
        else
        {
                //Parent processs
                //close(pipe1[1]);
                //close(pipe2[0]);
                //Server side
                char buff[1000];
                read(pipe2[0],buff,100);
                printf("Server Response: ");
                write(pipe1[1],buff,100);
        }
}