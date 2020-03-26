#include<stdio.h>
int main(void)
{int sum=0,num=0,d=0;
        printf("enter a number to find its digits sum");
        scanf("%d",&num);
        while(num!=0)
                {
                            d=num%10;
                            sum=d+sum;
                            num=(num-d)/10;
                 }

    printf("sum of digits is%d",sum);
}
