#include<stdio.h>
void insertionSort(int *a, int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = a[i]; 
        j = i - 1; 
        while (j >= 0 && a[j] > key) { 
            a[j + 1] = a[j]; 
            j = j - 1; 
        } 
        a[j + 1] = key; 
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
    insertionSort(a,n);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}