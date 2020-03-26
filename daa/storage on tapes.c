#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void quicksort(int a[],int first,int last){
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
void tapestorage(int tapes[MAX][MAX],int a[],int n,int total){
    int i,j;
    for(i=0;i<MAX;i++)
        for(j=0;j<MAX;j++)
            tapes[i][j]=-1;
    quicksort(a,0,total-1);
    for(i=0;i<total;i++)
        tapes[i%n][i/n]=a[i];
}
void main(){
    int n,i,j,m,tapes[MAX][MAX];
    printf("Enter the value of n:");
    scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    printf("Enter the files length: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the number of tapes:");
    scanf("%d",&m);
    tapestorage(tapes,a,m,n);
    for(i=0;i<m;i++){
        int acesstime=0;
        int sum=0;
        int cnt=0;
        for(j=0;j<n/m+1;j++){
            if(tapes[i][j]!=-1){
                printf("%d ",tapes[i][j]);
                acesstime+=sum+tapes[i][j];
                sum+=tapes[i][j];
                cnt+=1;
            }
        }
        printf("\tAccess Time: %f\n",acesstime/(float)cnt);
    }           
}