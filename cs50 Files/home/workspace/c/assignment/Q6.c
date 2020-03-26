#include<stdio.h>
int main(void)
{
    int i,num,j;
    printf("enter value on n");
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        printf("a");
    }
    printf("\n");
    for(i=1;i<=num-2;i++)
    {
        for(j=1;j<=num;j++)
        {
            if(j==1)
            {printf("a");}
            else if(j==num)
            {
                printf("a\n");
            }
            else
            {
                printf(" ");
            }
        }
    }
     for(i=1;i<=num;i++)
    {
        printf("a");
    }
}