#include<stdio.h>
int primecheck(int n)
{

    int k ,mod;
    for(k=2;k<n;k++)

    {
        mod=n%k;
        if(mod==0)
        {
         break;
        }
       // printf("k=%d mod=%d",k,mod);
    }

    if(mod==0)
    {
        return 0;
    }

    return 1;
}


void primefact(int num)
{
    int i=2;
    while (num!=0 && num!=1)
    {
      //  printf("num = %d , i=%d\n",num,i);
        //printf("(primecheck(i)==1 && num%i==0)=%d\n",(primecheck(i)==1 && num%i==0));
       if(primecheck(i)==1 && num%i==0)
        {
            printf("%d *",i);
            num=num/i;
            i=2;
        }
        else
        {
            i++;
        }
    }
}


int main()
{
    int num;
    scanf("%d",&num);
    primefact(num);
    printf("1=%d",num);
    return 0;
}