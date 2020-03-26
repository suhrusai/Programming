#include<stdio.h>
void selectionSort(int *a,int n){
    int i,j,minindex;
    for(i=0;i<n-1;i++)
    {
        minindex=i;
        for(j=i+1;j<n;j++)
            if(a[minindex]>a[j])
                minindex=j;
        int temp=a[minindex];
        a[minindex]=a[i];
        a[i]=temp;

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
    selectionSort(a,n);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}


