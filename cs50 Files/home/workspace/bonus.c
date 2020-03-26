#include <stdio.h>
int main()
{
int bonus=0,yoj=0,cy=0,yos=0,yom=0;
printf("enter current year");
scanf("%d",&cy);
printf("enter year of joining");
scanf ("%d",&yoj);
yos=cy-yoj;
yom=3-yos;
if(yos>3)
{
    bonus=2500;
    printf("Bonus=Rs.%d",bonus);
}
else
{bonus=0;
printf("%d years to go for bonus",yom);

}
}