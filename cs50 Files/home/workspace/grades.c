#include <stdio.h>
main()
{
     int m1,m2,m3,m4,m5,per,tot=0;

printf("enter score in subject 1 on scale of 100:        ");
scanf("%d",&m1);
printf("enter the marks in subject 2 on scale of 100:    ");
scanf("%d",&m2);
printf("enter the score in subject 3 on a scale of 100:  ");
scanf("%d",&m3);
printf("enter the score in subject 4 on a scale of 100:  ");
scanf("%d",&m4);
printf("enter the socre in subject 5 on a scale of 100:   ");
scanf("%d",&m5);
tot = m1+m2+m3+m4+m5 ;
per = tot/5;
printf("your percentage is %d \n total is %d \n",per,tot);
if(per>=90)
{
printf("Grade:A1");
}

else if(per>=80)
{
    printf("Grade:A2");

}
    else if (per>=70)
    {
        printf("Grade:B1");
    }
    else if (per>=60)
    {
        printf("Grade:B2");
    }
    else if(per>= 50)
    {
        printf("Grade:C1");
    }
    else if(per>=40)
    {
    printf("Grade:C2");
    }
    else if (per<40)
    {
        printf("FAIL!!!!!");
    }
}
