#include<stdio.h>
#include<math.h>
int main(void)
{
    int ni,fact,i,n;
    long double x,sinx;
    fact=1;
    printf("Enter the value of x in sin(x)");
    scanf("%Lf",&x);
    x=x*3.14/180;
    printf("how many terms accuracy do you want");
    scanf("%d",&n);
    for(i=1;i<=n;)
    {
        for(ni=1;ni<=i;ni++)
        {

            fact=ni*fact;
            printf("fact=%d\n",fact);
        }

    sinx=sinx+(pow(x,i)/fact)*(pow(-1,((i+1)/2)));
    i=i+2;
    printf("i=%d\n",i);
    }
    printf("%Lf",sinx);

    }
