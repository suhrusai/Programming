#include<stdio.h>
#include<stdlib.h>
int main()
{
int i,j,n;
printf("enter value of n: ");
scanf("%d",&n);
i = (n*(n+1))/2;
int *a = (int*)malloc(sizeof(int)*i);
for(i=0;i<n;i++)
{
for(j=i;j<n;j++)
{
printf("Enter element %d %d: ",i+1,j+1);
scanf("%d",&a[(j*(j+1)/2)+i]);
}
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(i>j)
{
printf("00 ");
}
else
{
printf("%02d ",a[(j*(j+1)/2)+i]);
}
}
printf("\n");
}
return 0;
}