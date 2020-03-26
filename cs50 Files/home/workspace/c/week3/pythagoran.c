#include<stdio.h>
int main(void)
{
    int a,b,c;
    printf("enter three numbers");
    scanf("%d %d %d",&a,&b,&c);
    if(a*a+b*b==c*c)
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
}
