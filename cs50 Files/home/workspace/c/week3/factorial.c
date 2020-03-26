#include<stdio.h>
int main(void)
{
    int num=0,fact=1,i=1;
    printf("Enter a number\n");
    scanf("%d",&num);
    while(i<=num && i!=0)
    {
        fact=fact*i;
        i++;
    }

    printf("\nfactorial=%d",fact);
}
