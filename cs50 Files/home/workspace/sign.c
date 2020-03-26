#include<stdio.h>
int main(void)
{
    int a;
    printf("Enter a number");
    scanf("%d",&a);
    if(a<0)
    {
        printf("\nnegative");

    }
    else if(a>0)
    {
    printf("\n positive");
    }
    else
    {
    printf("number is zero");
    }
}