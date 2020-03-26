#include<stdio.h>
int main(void)
{
    int n,i,j;
    printf("Enter the number of rows");
    scanf("%d",&n);
    int size=4+(n-2)*3;
    int *a=(int *) malloc(sizeof(int)*size);
    printf("Enter 1 1: ");
    scanf("%d",&a[0]);
    printf("Enter 1 2: ");
    scanf("%d",&a[1]);
    for(i=1;i<n-1;i++)
        {
            for( j=1;j<=3;j++)
            {printf("Enter element %d %d: ",i+1,j+i-1);
            scanf("%d",&a[3*i+j-2]);}
        }
    printf("Enter %d %d: ",n,n-1);
    scanf("%d",&a[size-2]);
    printf("Enter %d %d: ",n,n);
    scanf("%d",&a[size-1]);
    printf("%02d %02d ",a[0],a[1]);
    for( i=0;i<n-2;i++)
        printf("00 ");
    printf("\n");
    for( i=1;i<n-1;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j==i-1)
            {
                printf("%02d %02d %02d ",a[3*i-1],a[3*i],a[3*i+1]);
                j+=2;
            }
            else
            printf("00 ");
        }
        printf("\n");
    }
    for( i=0;i<n-2;i++)
        printf("00 ");
    printf("%02d %02d",a[size-2],a[size-1]);
   
}

