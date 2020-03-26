#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,j,n;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int max =  a[n-1];
    a[n-1] = -1; 
    for(int i = n-2; i >= 0; i--)
    {
        int temp = a[i];
        a[i] = max;
        if(max < temp)
            max = temp;
    }

    for(i=0;i<n;i++)
        printf("%d ",a[i]);

}