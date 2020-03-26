#include<stdio.h>
#include<math.h>
int main(void)
{
    int v1,v2,n;
    float time2,time1;//Time1 for walkingt and other for car
    char output[4];
    printf("Enter the value of v1(velocity of amit) v2(velocity of car) and N(Distance)\n");
    scanf("%d %d %d",&v1,&v2,&n);
    time1=n*1.414/v1;
    time2=2*(float)n/v2;
    if(time1>time2)
        printf("Walk");
    else
        printf("Taxi");
}