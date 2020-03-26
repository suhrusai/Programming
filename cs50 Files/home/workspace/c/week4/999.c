#include<stdio.h>
#include<math.h>
int main(void)
{
    int t,tmod,num,i;
    unsigned int val;
    do
    { i=0;val=0;

    label:
    printf("\n Enter a Number to convert to binary");
    scanf("%d",&num);
    t=num;
    if(num>=0)
    {
    while(t!=0)
    {
    tmod=t%2;
    val=val+tmod*pow(10,i);
    t=t/2;
    i++;
    }
    printf("\nBinary number is %u",val);
    }
    else
    {
        goto label;
    }
}while(num!=999);
}




