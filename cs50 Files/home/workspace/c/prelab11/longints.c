#include<stdio.h>
int main(void)
{
        FILE *ptr=fopen("longint.txt","r");
        char ch=fgetc(ptr);
        int num=0;
        long double sum=0;
        while(ch!=EOF)
        {
                if(ch==' ' || ch=='\n')
                        num++;
                ch=fgetc(ptr);
        }
        fclose(ptr);
        FILE *ptr1=fopen("longint.txt","a+");
        long long int arr;
        int i=0;
        sum=0;
     while(fscanf(ptr,"%lld ",&(arr))!=EOF)
        {
                sum=sum+arr;
              //  printf("%lld \n",arr[i]);


        }
        printf("%lld",sum);
        //printf("%lf",arr[1]);
}