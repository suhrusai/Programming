#include<stdio.h>
int fact(int x)
{
    int i,val;
    for(i=1;i<=x;i++)
    {
        fact(i);
    }
    val*=x;
    return val;

}
int main(void)
{
    int n;
    scanf("%d",&n);
    printf("%d",(fact(n)/n));
}