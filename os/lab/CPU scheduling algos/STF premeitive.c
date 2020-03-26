#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct process{
        int pid;
        int bt;
        int at;
} process;
void sort_small_bus(process a[],int start,int n,int firsttime,int time){
        int i,j;
        for(i=start;i<n;i++)
                for(j=start;j<n;j++){
                        if(a[i].at<a[j].at && firsttime){
                                process temp=a[i];
                                a[i]=a[j];
                                a[j]=temp;
                        }
                        else if(a[i].bt<a[j].bt && a[i].at>=a[i].at){
                                process temp=a[i];
                                a[i]=a[j];
                                a[j]=temp;
                        }
                }
}
float avg(int wt[],int n){
        int i;
        int sum=0;
        for(i=0;i<n;i++){
                sum+=wt[i];
        }
        return (float)sum/n;
}
void main(){
        int n,i;
        process a[MAX];
        int pid,at,bt;
        printf("Enter the number of proesses");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                //printf("Enter pid: ");
                //scanf("%d",&a[i].pid);
                a[i].pid=i;
                printf("Enter bt:");
                scanf("%d",&a[i].bt);
                printf("Enter at:");
                scanf("%d",&a[i].at);
        }
        sort_small_bus(a,0,n,1);
        int time=0;
        i=0;
        int wt[MAX]={0};
        int tat[MAX]={0};
        while(i<n){
                if(a[i].at<=time)
                {
                    if(wt[i]==0){
                        wt[i]=time-a[i].at;
                    }
                    a[i].bt-=1;
                    if(a[i].bt==0){
                        tat[i]=time-a[i].at;
                        printf("\npid : %d at: %d bt: %d wt: %d tat:%d \n",a[i].pid,a[i].at,a[i].bt,wt[i],tat[i]);
                        i++;                        
                        }
                        sort_small_bus(a,0,n,1);
                }
                time++;
        }
        printf("\nWaiting time avg: %lf ,Turn around time: %lf",avg(wt,n),avg(tat,i));

}
