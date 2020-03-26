#include<stdio.h>
int main(void)
{
    int i,j,k,n;
    printf("Enter a number ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("  ");
        for(j=n;j>=i;j--)
        {
            printf(" ");
        }
        for(k=1;k<=i;k++)
        {
            printf("*  ");
        }
        printf("\n");
    }

    for(i=n-1;i>=0;i--)
    {
        printf("    ");
        for(j=n-1;j>i;j--)
        {
            printf("  ");
        }
        for(k=1;k<=i;k++)
        {
            printf("*  ");
        }
        printf("\n");
    }

}