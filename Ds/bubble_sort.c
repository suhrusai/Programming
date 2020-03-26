#include<stdio.h>
void bubbleSort(int *a,int n){
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(a[i]<a[j])
            {
                //swapping elements
                a[i]=a[i]+a[j];
                a[j]=a[i]-a[j];
                a[i]=a[i]-a[j];
            }
}
int main(void){
    int a[10],n,i;
    printf("Number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("sorted array: ");
    bubbleSort(a,n);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

