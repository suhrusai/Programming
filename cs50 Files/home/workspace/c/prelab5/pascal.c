#include<stdio.h>
int main(void)
{
    int i,j,n,k;
    printf("enter value of n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=n-i;j++)
        {
            printf(" ");
        }
        for(k=0;k<=i;k++)
        {
            if(k==0 || i==1)
            {
                printf("1  ");
            }
            else
            {
                printf("%d  ",((i+k+1)/i));
            }
        }
        printf("\n");
    }
}
