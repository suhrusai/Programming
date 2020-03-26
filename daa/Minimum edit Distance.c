#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef enum direction{INSERT,REMOVE,REPLACE} DIRECTION;
int main(){
    int i,j;
    char input_string[100],dictonary[100];
    DIRECTION dir[100][100];
    int med_mat[101][101];
    printf("Input String: ");
    scanf("%s",input_string);
    printf("Dictonary: ");
    scanf("%s",dictonary);
    med_mat[0][0]=0;
    for(j=1;j<strlen(input_string)+1;j++){
        med_mat[0][j]=j;
        dir[0][j]=INSERT;
    }
    for(i=1;i<strlen(input_string)+1;i++){
        med_mat[i][0]=i;
        dir[i][0]=INSERT;
    }
    printf("\n");
    for(i=1;i<strlen(input_string)+1;i++){
        for(j=1;j<strlen(input_string)+1;j++){
                //When both the char is same then the value == diag element
                if(dictonary[i-1]==input_string[j-1]){
                        dir[i][j]=REPLACE;
                        med_mat[i][j]=med_mat[i-1][j-1];
                }
                else{
                    //Checking if horizontal element is minimum
                    if(med_mat[i][j-1]<=med_mat[i-1][j-1] && med_mat[i][j-1]<=med_mat[i-1][j]){
                        dir[i][j]=INSERT;
                        med_mat[i][j]=med_mat[i][j-1]+1;
                    }
                    //Checking if the diagonal element ins the least
                    else if(med_mat[i-1][j-1]<=med_mat[i][j-1] && med_mat[i-1][j-1]<=med_mat[i-1][j]){
                        dir[i][j]=REPLACE;
                        med_mat[i][j]=med_mat[i-1][j-1]+1;
                    }

                    //Checking if vertical is the minimum
                    else{
                        dir[i][j]=REMOVE;
                        med_mat[i][j]=med_mat[i-1][j]+1;
                    }
                }
            }
        }
    //OUTPUT CODE
        for(i=0;i<strlen(input_string)+1;i++)
            if(i)
            printf("%c  ",input_string[i-1]);
            else
            printf("       ");
        for(i=0;i<strlen(input_string)+1;i++)
            if(i)
            printf("%c  ",input_string[i-1]);
            else
            printf("\t   ");
        printf("\n");
        for(i=0;i<strlen(input_string)+1;i++){
            if(i)
            printf("%c   ",dictonary[i-1]);
            else
            printf("    ");
            for(j=0;j<strlen(input_string)+1;j++){
                printf("%d  ",med_mat[i][j]);
            }
            printf("\t");
            for(j=0;j<strlen(input_string)+1;j++){
                    printf("%d  ",dir[i][j]);
                }
            printf("\n");
        }
    //OUTPUT CODE ENDS
    //Changes to be made to input string to get output string 
    i=j=strlen(input_string);
    while(i!=0 && j!=0){
            DIRECTION val=dir[i][j];
            int ival=i,jval=j;
            // printf("i: %d j:%d   ",i,j);
            if(dir[i][j]==0){
                // printf("0\n");
                i-=1;
            }
            else if(dir[i][j]==1){
                //printf("1\n");
                j-=1;
            }
            else if(dir[i][j]==2){
                //printf("2\n");
                j-=1;
                i-=1;
            }
        
        if(input_string[ival-1]!=dictonary[jval-1])
        {
            if(dir[i][j]==2)
                printf("REPLACE  ");
            else if(dir[i][j]==1)
                printf("REMOVE   ");
            else
                printf("INSERT   ");
            printf("%c %c\n",input_string[ival-1],dictonary[jval-1]);
        }
    }
}
