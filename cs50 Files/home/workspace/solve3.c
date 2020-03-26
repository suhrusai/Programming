#include<stdio.h>
int main(void)
{
    char x1,x2,x3;
    int a,b,c,d,e,f,g,h,i,j,d1,d2,d3;
    float det1,det2,det3,det4,ans1,ans2,ans3;
    printf("Enter the variable names\n");
    scanf("%c %c %c",&x1,&x2,&x3);
    printf("enter coefficinets as in carmers rule (serperated by commas)\n");
    printf("x1\tx2\tx3\td\n");
    scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",&a,&b,&c,&d1,&e,&f,&g,&d2,&h,&i,&j,&d3);
    det1=a*((e*i)-(h*f))-b*((d*i)-(g*f))+c*(d*h-g*e);
    det2=d1*((e*i-f*h))-b*((d2*i-d3*f))+c*((d2*h-d3*e));
    det3=a*((d2*i)-(d3*f))-d1*((d*i)-(g*f))+c*(d*d3-g*d2);
    det4=a*((e*d3)-(h*d2))-b*((d*d3)-(g*d2))+d1*(d*h-g*e);
    ans1=det2/det1;
    ans2=det3/det1;
    ans3=det4/det1;
    printf("value of det1=%4.0f\n",det1);
    printf("value of det2=%4.0f\n",det2);
    printf("value of det3=%4.0f\n",det3);
    printf("value of det4=%4.0f\n",det4);
    printf("%c=%5.2f\n",x1,ans1);
    printf("%c=%5.2f\n",x2,ans2);
    printf("%c=%5.2f\n",x3,ans3);


}