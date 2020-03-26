#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct task{
        int st;
        int ft;
} task;
task* sort(task a[],int n){
         int i,j;
         for(i=0;i<n-1;i++){
                for(j=0;j<n-1;j++)
                {
                        if(a[j].ft>a[j+1].ft){
                                task temp=a[j];
                                a[j]=a[j+1];
                                a[j+1]=temp;
                        }
                }
        }
        return a;
}
int isfree(int isbusy[] ,int st,int ft){
        int i;
        for(i=st;i<ft;i++)
                if(isbusy[i])
                        return 0;
        return 1;
}
void greedy_single_cpu(task a[],int n){
        int isbusy[100]={0};
        int taskdone[100]={0};
        int i,j;
        for(i=0;i<n;i++)
        {
                if(isfree(isbusy,a[i].st,a[i].ft))
                {
                        for(j=a[i].st;j<a[i].ft;j++)
                                isbusy[j]=1;
                        taskdone[i]=1;
                }
        }
        for(i=0;i<n;i++){
                if(taskdone[i])
                        printf("\npid: %d st: %d ft: %d",i,a[i].st,a[i].ft);
        }
}
int main(){
        int i,n;
        printf("Enter the of n:");
        scanf("%d",&n);
        task *a=(task *)malloc(sizeof(task)*n);
        for(i=0;i<n;i++){
                printf("Enter start time and end time: ");
                scanf("%d %d",&a[i].st,&a[i].ft);
        }
        sort(a,n);
        greedy_single_cpu(a,n);

}