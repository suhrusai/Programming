#include<stdio.h>
int main(void)
{
    int i,num;
    start:
    printf("\nEnter a number b/w 1 to 10");
    scanf("%d",&num);
    if(num>=1 && num<=10)
    {
        switch(num%2)
        {
            case 0: printf("\n Even number");break;
            case 1: printf("\n Odd number");break;
        }
    }
    else
    {
        printf("\nEnter number between 1 and 10 only ");
        goto start;
    }
}
