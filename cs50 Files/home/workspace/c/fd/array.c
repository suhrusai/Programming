#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
   long long int i,n,sum=0,num[100000000];
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&num[i]);
        sum=sum+num[i];
    }
     printf("%lld",sum);

}