#include<stdio.h>
int main(void)
{
    int x[1200],i,j,t,m,median,n;
    char opt;
    printf("ENt1 the number of terms: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
         printf("ENter the %d value: ",i);
         scanf("%d",&x[i]);
        //printf("do you want to continue(Y/N): ");
         //scanf("%c",&opt);
         //if(opt=='N' || opt=='n')
         //{
         //  break;
         //}
    }

    for(m=0;m<=n;m++)
    {
        for(j=0;j<n;j++)
        {
            if(x[j]>x[j+1])
            {
                t=x[j+1];
                x[j+1]=x[j];
                x[j]=t;
            }
        }
    }
       printf("Number in ascending order:\t");
    for(i=0;i<n;i++)
    {
        printf("%d \t",x[i]);
    }
    if((n)%2==1)
        {
          printf("median is %d",x[(n-1)/2]);
        }
        if((n)%2==0)
        {
            printf("median is %d",(x[n/2-1]+x[n/2])/2);
        }
}

