#include<stdio.h>
#include<math.h>
int main(void)
{
    double x,val,cal,z;
    int i,n,fact,num_of_terms,t;
    n=1;
    fact=1;
     printf("enter value of x in sin(x)");
    scanf("%lf",&x); // x is x in sin(x)
    x=(x*3.14/180);// converting to radians
    printf("%lf in radians \n",x);

    printf("accuracy to how many terms");
    scanf("%d",&num_of_terms);
    for(i=1;i<=num_of_terms;i++)
    {
        printf("i=%d\n",i);
        for(t=1;t<=n;t++)
        {
            fact=fact*t;//fact is factorial value
            printf("t=%d\n",t);
        }
        printf("fact %d\n",fact);
        val=x*pow(-1,(n+1)/2)/fact;
        printf("%lf\n",val);
        cal=cal+val;
        n=n+2;
        x*=(x*x);

    }
    printf("n=%d\n",n);
    printf("%lf",val);
    printf("%f",sin(x));
}
