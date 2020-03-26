#include<stdio.h>
int val=1;
int gcd(int x1,int x2)
{
        int x1mod=1,x2mod=1;
        int i;
        int x;
        if(x1>1 && x2>1)
        {
                x=(x1<x2)?x1:x2;
                for( i=2; i<=x;i++)
                {
                        x1mod=x1%i;
                        x2mod=x2%i;
                        if (x1mod==0 && x2mod==0)
                        {
                                val=val*i;
                                break;
                        }


                }

        gcd((x1/x1mod),(x2/x2mod));

        }
        else
        {
                return 1;
        }
}


int main(void)
{
        int x1,x2;
        scanf("%d%d",&x1,&x2);
        printf("%d %d",x1,x2);
        printf("%d",gcd(x1,x2));
}
