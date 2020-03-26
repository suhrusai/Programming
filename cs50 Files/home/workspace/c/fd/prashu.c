#include<stdio.h>
int main(void)
{
    int x,x1=0,x2=0,i=0,j=0;
    char gender;
for (int c=1;c<=5;c++)
{
    printf("Enter Age of voter and gender(M/F) respectively");
    scanf("%d %c",&x,&gender);
    if(gender=='M')
    {
        x1=x1+x;
        i++;
    }
    else
    {
        x2=x2+x;
        j++;

    }


}
printf("\n Average age of male voters is %f and female voters is %f",(float)x1/i,(float)x2/j);
printf("i=%d,j=%d",i,j);
}

