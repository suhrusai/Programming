#include<stdio.h>
int main(void)

{   int a,b,c;
    b=2 ;c=10;
    printf("enter a number");
    scanf("%d",&a);
   if (a==1)
   {
       printf("1 is neither prime nor composite");
    }
       else
       {
           while(b<a  && c!=0)
    {
        c=a%b;
        b=b+1;

    }
    printf("b=%d c=%d\n",b,c);

    if (c!=0)
    {
        printf("%d is prime",a);
    }
    else
    {
        printf("%d is not prime",a);
    }
       }
}