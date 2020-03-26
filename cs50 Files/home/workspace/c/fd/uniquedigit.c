#include<stdio.h>
int main(void)
{
    int tmod,i,j;
    int num,t;
    printf("Enter the number");
    scanf("%d",&num);
    //printf("%ld",num);
    for(j=0;j<=20;j++)
    {
        t=num;
        //printf("%ld",t);

            tmod=t%10;
            if(tmod==j)
               {
               printf("%d",tmod);
               }
                t=t/10;
                i++;
        }
    }
}
