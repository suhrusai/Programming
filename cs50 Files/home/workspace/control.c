#include<stdio.h>

int main()
{
int num    ;
printf ("hello select a number and see the outcome");
scanf("%d",&num);
if(num<10)
printf("choosen number is a single digit number");
if(num<100)
printf("choosen number is a double didgit number ");
if (num<1000)
printf("choosen number is a 3 didgit number ");
if (num<10000)
printf("its a four didgit number");
if (num>10000)
printf("please stop u r imagination cuz i can't write more code");

}