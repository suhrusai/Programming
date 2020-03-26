#include<stdio.h>
int main (void)
{
    long long int no,bin=0,a,i=1;
    label:
    bin=0;i=1;
    printf("Enter number\n");
    scanf("%lld",&no);
    if((no>0)&&(no!=999))
    {
        printf("The binary no is:\n");

    while(no!=0)
    {
        a=no%2;
        no/=2;
        bin+=(a*i);
        i*=10;
    }
    printf("%lld",bin);
    printf("\n");
    goto label;
    }
    else if(no==999)
    {
        printf("end of the program");
    }

}

