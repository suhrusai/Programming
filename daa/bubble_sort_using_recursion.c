#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int i,int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
void bubblesort(int a[],int n){
    int i;
    for(i=0;i<n-1;i++)
        if(a[i]>a[i+1])
            swap(a,i,i+1);
    //Base Condition
    if(n==1){
        return ;
    }
    else{
        return bubblesort(a,n-1);
    }
}
int main(){
    int i=0;
    int n;
    //Taking number of elements as input
    printf("Enter the value of n: ");
    scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    //Taking Input
    printf("Enter the array elements: ");
    for(i=0;i<n;i++)
        scanf("%d ",&a[i]);
    //Fuction call
    bubblesort(a,n);
    //Printing of sorted array
    printf("Sorted elements: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
