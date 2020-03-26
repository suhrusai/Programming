#include<stdio.h>
int main(void)
{
    int num,t,l,sum;
    sum=0;

    printf("Enter a number:");
    scanf("%d",&num);
    t=num;
    while(t>0)
    {
        l=t%10;
        sum=sum+l;
        t=t/10;
    }
    printf("\nSum=%d",sum);

}
