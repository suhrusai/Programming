
#include<math.h>
#include <stdio.h>
int prime(int b)
{
    int j;
     for(j=2;j<=sqrt(b);j++)
         if(b%j==0)
            return 0;
     return 1;
}
int main() {
 int i,j,cnt,a[500000],c,sum=0,count=0,k=0;
 long long int n;
 for(n=0;n<10000000;n++){
    count=0;
 for(i=2;i<=n;i++)
 {
     cnt=1;
     for(j=2;j<=n/2;j++)
     {
         if(i%j==0)
         cnt=0;
     }
     if(cnt==1)
     {
        a[k]=i;
        k++;
        }
 }
 for(i=0;i<k;i++)
 {
     sum=sum+a[i];
    c= prime(sum);
    if(c==1)
    count++;
 }
 printf("%d,",count);
}
    
}
