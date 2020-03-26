#include <stdio.h>
#include<stdlib.h>
void quicksort(int a[25],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(a[i]<=a[pivot]&&i<last)
            i++;
         while(a[j]>a[pivot])
            j--;
         if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
         }
      }

      temp=a[pivot];
      a[pivot]=a[j];
      a[j]=temp;
      quicksort(a,first,j-1);
      quicksort(a,j+1,last);
   }
}
//Driver Code
int main(){
    int i,a[5]={5,4,7,6,2};
    quicksort(a,0,4);
    for(i=0;i<5;i++)
    printf("%d ",a[i]);
}
