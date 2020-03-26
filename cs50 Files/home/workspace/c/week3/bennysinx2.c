#include <stdio.h>
#include <math.h>
int main()
{
	int j,k,n,fact,sign=1;
	double i=0,x;
	printf("Enter x in radian to find sin(x) ");
	scanf("%lf",&x);
	printf("Enter no of terms: ");
	scanf("%d",&n);
	for(j=1;j<2*n;j+=2){
	fact = 1;
		for(k=1;k++<j;fact*=k);
	i += sign*(pow(x,j))/fact;
	//printf("%d %d %d %g\n",sign,j,fact,i);
	sign *= -1;
	}
	printf("Approximate Value of sin(%g) is %g\n",x,i);
	printf("Math Value of sin(%g) is %g\n",x,sin(x));
	return 0;
}
