#include<stdio.h>
int main(void)
{
    int c;
    for(c=0;c<=100;c++)
    {
        if(c%2!=0 && c%3!=0)
        {
        printf("%d    ",c);
        }
    }
}