#include <stdio.h>
int main ()
{
  int i, j,n;
  printf("Enter the value of n: ");
  scanf("%d",&n);
  i=n*(n+1)/2;
  int *a=(int *)malloc(sizeof(int)*i);
  for (i = 0; i < n; i++)
    for (j = 0; j <= i; j++)
      {
printf ("Enter %d %d element:", i, j);
scanf("%d",&a[(i*(i+1))/2+j]);
//printf ("%d\n", (i * (i + 1)) / 2 + j);
      }
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j<5; j++)
        {
            if(j<=i)
           printf("%02d ",a[(i*(i+1))/2+j]);
       else
           printf("00 ");
        }
    printf("\n");
    }
  return 0;
}
