#include <stdio.h>
int main()
{
    int n;
    printf("Enter the size of the diagonal matrix: ");
    scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the %d %d value: ",i+1,i+1);
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    printf("%02d ",a[i]);
                else
                    printf("00 ");
            }
            printf("\n");
        }
}

