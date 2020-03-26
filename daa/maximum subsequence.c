#include<limits.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
int sum(int a[],int start,int end){
        int i;
        int sum=0;
        for(i=start;i<=end;i++)
                sum+=a[i];
        return sum;
}
int maxsequence(int a[],int start,int end){
        int max1,max2,max;
        if(start>=end){
                return a[start];
        }
        max1=maxsequence(a,start,end-1);
        max2=maxsequence(a,start+1,end);
        int sum1=sum(a,start,end);
        if(max1>max2)
                max=max1;
        else
                max=max2;
        if(max<sum1)
                max=sum1;
        //(max>sum1)?max=max:max=sum1;
        return max;
}
void main(){
        int n,i;
        printf("Enter the value of n: ");
        scanf("%d",&n);
        int *a=(int * )malloc(sizeof(int)*n);
        for(i=0;i<n;i++){
                scanf("%d",&a[i]);
        }
        printf("MaxSubSequence: %d",maxsequence(a,0,n-1));
}