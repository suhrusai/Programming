#include<stdio.h>
int main()
{
    int number[15];
    int i,j,n,temp;
    printf("enter no of nos:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n enter a number:");
        scanf("%d",&number[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(number[i]>number[j])
            {
                temp=number[j];
                number[j]=number[i];
                number[i]=temp;
            }
        }


    }
    printf("the numbers in ascending order are: ");
        for(i=1;i<n;i++)
        {
             printf(" %d ",number[i]);
        }
        if(n%2==1)
        {
          printf("median is %d",number[(n-1)/2]);
        }
        if(n%2==0)
        {
            printf("median is %d",(number[n/2-1]+number[n/2])/2);
        }

}