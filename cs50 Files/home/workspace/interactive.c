
#include<stdio.h>
#include<math.h>
int main(void)
{

long int num,count=0,bmod,i=0,t;
do
{
long int val;
retry:printf("\nEnter a number: ");
scanf("%ld",&num);
t=num;
if(num==999)
{
}
else if(num>0){
while(num!=0)
{
bmod=num%2;
val=val+pow(10,i)*bmod;
num=num/2;
i++;
}
printf("\n binary number");
while(val!=0)
{