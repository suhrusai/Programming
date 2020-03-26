#include<stdio.h>
int main (void)
{
    int a,b,c,n,i;
    a=0;
    b=1;
        printf("enter number of terms(n>2):");
        scanf("%d",&n);
        printf("\n 0 1");
        for(i=0;i<n-2;i++)
        {
                c=a+b;
                printf(" %d",c);
                a=b;
                b=c;
                //printf("a=%d,b=%d",a,b);
        }
}
