#include <stdio.h>

int main(void)
{
	int sum=0,d=0,t=1,a=1;
	printf("Enter a number");
	scanf("%d",&a);
	t=a;
	while(t>0)
	{
		d=t%10;
		sum=sum+d*d*d;
		t=t/10;
	}
	printf("\nSum of cubes of digits=%d",sum);
	if(a==sum)
	{
		printf("\nIt is a Armstrong number");
	}
	else
	{
		printf("\nIt isn't a Armstrong number");
	}
}
