#include<stdio.h>
#include<math.h>
int main(void)
{
    int a,b,c;
    float d,x,x1;
    printf("Enter value of a,b,c in ax^2+bx+c=0");
    scanf("%d %d %d",&a,&b,&c);
    d=(b*b)-(4*a*c);
    if(d<0)
    {
        printf("\nNo real roots");
    }
    else if(a==0)
    {
        printf("\nx=%f",-(float)c/b);
    }

    else if(d==0)
    {
        printf("\n Both roots are equal to %f",(-(float)b/(2*a)));
    }
    else
    {
        x=(-b+sqrt(d))/2*a;
        x1=(-b-sqrt(d))/2*a;
        printf("\n x1=%f\n x2=%f\n",x,x1);

    }
}