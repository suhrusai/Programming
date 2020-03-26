#include<stdio.h>
int main(void)
{
    int n,val,i;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        val=i*i*i;
        printf("%d,",val);
    }
}