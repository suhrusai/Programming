#include<stdio.h>
main()
/*hello this is a program which tells to give a employee bonu or not*/
{
    int qty,dis=0;
    float rate,tot;
    printf("enter qty");
    scanf("%d",&qty);
    printf("enter rate");
    scanf("%f",&rate);
    if(qty>1000)
    dis=10;
    tot=(qty*rate)-(qty*rate*dis/100);
    printf("Total expenses=Rs.%f,tot");
}