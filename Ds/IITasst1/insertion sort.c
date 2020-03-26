#include<stdio.h>
#include<stdlib.h>
#include <time.h>  
/*
RUNTIMES FOR DIFFERENT SIZE OF TEST CASE(Worst time)(i.e array in descending order)
for 1 element:0.000000
for 10 elements:0.000000
for 100 elements:0.000000
for 1000 elements:2.000000
for 10000 elements:164.000000
for 100000 elements: 15859.000000
*/
void insertionSort(int a[], int n) 
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

int main(){
    int n;
    printf("Enter number of inputs:");
    scanf("%d",&n);
    int a[n];
    /*printf("Enter the number of elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }*/
    for(int i=n-1;i>=0;i--)
        a[n-i-1]=i;
    double time_spent = 0.0;
	clock_t begin = clock();
    insertionSort(a,n);
    clock_t end = clock();
    for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    time_spent += (double)(end - begin);
    printf("Time elpased is %f seconds", time_spent);
}