#include<stdio.h>
#include<math.h>
int main(void)
{
    char opt1;
    long long int bnum,bmod,i,val;
    val=0;
    bnum=1;
    i=0;

    pro:
    printf("What conversion do you want to make");
    scanf("%c",&opt1);
    if(opt1=='b')
    {
        printf("\n Enter the normal number");
        scanf("%lld",&bnum);
        while(bnum!=0)
       {
        bmod=bnum%2;
        //printf("\n%lld\n",bmod);
        bnum=bnum/2;
        val=val+pow(10,i)*bmod;
        //printf("\nbnum=%d",bnum);
        i++;
        }
        printf("%lld",val);
    }
    else if(opt1=='n')
    {
        printf("\n Enter the binary number");
        scanf("%lld",&bnum);
        while(bnum!=0)
        {
            bmod=pow(2,i)*(bnum%10);
            val=val+bmod;
            bnum=bnum/10;
            i++;

        }
        printf("%lld",val);

    }
    else
    {
        goto pro;
    }

}