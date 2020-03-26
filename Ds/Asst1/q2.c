#include<stdio.h>
#include<stdlib.h>
int * moveneg(int *a,int n){
int *b=(int *)malloc(sizeof(int)*n),j=0,i;
for(i=0;i<n;i++)
{   
    if(a[i]>0)
        b[j++]=a[i];
}
for(i=0;i<n;i++)
{   
    if(a[i]<0)
        b[j++]=a[i];
}
a=b;
return a;
}
int main(){
    int i,n;
    printf("Enter the value of n: ");
    scanf("%d ",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    a=moveneg(a,n);
    for(i=0;i<n;i++)
        printf("%d ",*(a+i));
}