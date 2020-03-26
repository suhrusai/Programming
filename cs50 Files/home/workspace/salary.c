#include<stdio.h>
int main()
{
    char g, qual;
    int cy,yoj,yos,sal,id;
    printf("Enter you ID please: ");
    scanf("%d",&id);
    printf("\nEnter Your QUALIFICATION\nP(postgraduate)\nG(graduate)\n ");
    scanf("%s",&qual);     // use %s instead of %c
    printf("\nEnter your GENDER. M or F  ");
    scanf("%s",&g);
    printf("\nEnter your YEAR OF JOINING  ");
    scanf("%d",&yoj);
    printf("\nEnter CURRENT YEAR  ");
    scanf("%d",&cy);
    yos=cy-yoj;

    if ((g =='M') && (yos>=10) && (qual=='P'))
        sal=15000;
    else if(((g=='M')&&(yos>=10)&&(qual=='G'))|| ((g=='M')&&(yos<10)&&(qual=='P')))
    sal=10000;
    if((g=='F')&&(yos>=10)&&(qual=='P'))
    sal=12000;
    if((g=='F')&&(yos<10)&&(qual=='P'))
    sal=10000;
    if((g='M')&&(yos<10)&&(qual=='G'))
    sal=7000;
    if((g='F')&&(yos>=10)&&(qual=='G'))
    sal=9000;
    if((g='F')&&(yos<10)&&(qual=='G'))
    sal=6000;


    printf("Employee with ID: %d \n Your SALARY is :Rs.%d \n Thanks for yout service for %d years ",id,sal,yos); //in printf it will be id not &id

}