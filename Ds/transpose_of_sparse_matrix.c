#include <stdio.h>

void main()
{
   int n,k,i,j,s;
   int *p,r;
   p=(int *)malloc(((r*(r-1))/2)*sizeof(int));
   printf("No.of rows in the tridiagonal matrix: ");
   scanf("%d",&r);
   n=3*r-2;
   for(k=0;k<n;k++)
   {
      printf("\nEnter the postion row and column of element:");
      scanf("%d %d",&i,&j);
      if(j<i-1||i>=r||j>i+1)
      {
             printf("\nwrong position of element.");
             k=k-1;
             continue;
      }
      printf("\nEnter the value: ");
               scanf("%d",&p[k]);
   }
   for(i=0;i<r;i++)
     {
      printf("\n");
      for(s=0;s<i-1;s++)
       printf("0 ");
      for(j=i-1;j<=i+1;j++)
      {
       if(j==-1||j==r)
         continue;
       k=2*i+j;
       printf("%d ",p[k]);
      }
      for(int m=0;j<n-j;j++)
        printf("0 ");
      }
}