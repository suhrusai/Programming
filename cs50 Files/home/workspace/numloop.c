#include<stdio.h>
int main(void)
{
    int x=2147483001;
    printf("%d\n",x);
    while(x>0)
    {
        x=x+1;
        printf("%d\n",x);
    }

}