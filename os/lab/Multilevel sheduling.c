#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct process{
        int pid;
        int bt;
        int at;
        int rt;
        int queue_num;
} process;
int time=0;
float total_tat=0,total_wt=0;
float avg(int [],int );
void RoundRobinAlgo(process a[],int n,int time_quantum){
    int *rt=(int *)malloc(sizeof(int)*n);
    int *wt=(int *)malloc(sizeof(int)*n);
    int *tat=(int *)malloc(sizeof(int)*n);
    int remaining=n;
    int i=0;
    for(i=0;i<n;i++)
        rt[i]=a[i].bt;
    while(remaining){
        i=i%n;
        if(a[i].at<=time){
            if(rt[i]<=time_quantum && rt[i]>0){
                time+=rt[i];
                rt[i]=0;
                remaining--;
                tat[i]=time-a[i].at;
                wt[i]=time-a[i].bt-a[i].at;
            }
            else{
                time+=time_quantum;
                rt[i]-=time_quantum;
            }
        }
        i++;
    }
    printf("\nTAT avg: %lf Avg WT: %lf",avg(tat,n),avg(wt,n));
    total_tat+=avg(tat,n);
    total_wt+=avg(wt,n);
}
 
void sort_arrival(process a[],int n){
        int i,j;
        for(i=0;i<n;i++)
                for(j=0;j<n;j++){
                    int cmp1=a[i].at,cmp2=a[j].at;
                        if(cmp1<cmp2){
                                process temp=a[i];
                                a[i]=a[j];
                                a[j]=temp;
                        }
                        else if(cmp1==cmp2 && a[i].pid<a[j].pid){
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
float * fcfs(process a[],int n){
        sort_arrival(a,n);
        int i=0;
        int wt[MAX]={0};
        int tat[MAX]={0};
        while(i<n){
                if(a[i].at<=time)
                {
                        time+=a[i].bt;
                        wt[i]=time-a[i].at-a[i].bt;
                        tat[i]=time-a[i].at;
                        printf("\npid : %d at: %d bt: %d wt: %d tat:%d \n",a[i].pid,a[i].at,a[i].bt,wt[i],tat[i]);
                        i++;
                        continue;
                }
                time++;
        }
        printf("\nTAT avg: %lf Avg WT: %lf",avg(tat,n),avg(wt,n));
    total_tat+=avg(tat,n);
    total_wt+=avg(wt,n);
}

void main(){
        int n,i;
        process a[MAX];
        int pid,at,bt,queues,queueslen[MAX]={};
        printf("Enter the number of proesses");
        scanf("%d",&n);
        printf("enter the number of queues");
        scanf("%d",&queues);
        process **b=(process **)malloc(queues*sizeof(process *));
        for(i=0;i<queues;i++){
            b[i]=(process  *)malloc(MAX*sizeof(process));
        }
        for(i=0;i<n;i++)
        {
                printf("Enter pid: ");
                scanf("%d",&a[i].pid);
                printf("Enter bt:");
                scanf("%d",&a[i].bt);
                printf("Enter at:");
                scanf("%d",&a[i].at);
                while(1){
                printf("Enter queue num:");
                scanf("%d",&a[i].queue_num);
                if(a[i].queue_num<=queues){
                    break;
                }
                printf("\n ENter a valid queue num");
                }
                b[a[i].queue_num-1][queueslen[a[i].queue_num-1]++]=a[i];
        }
        printf("\n1.FCFS\n2.RoundRobin");
        for(i=0;i<queues;i++){
            label:
            printf("Type of scheduling algorithm for %d: ",i+1);
            int opt;
            scanf("%d",&opt);
            switch(opt){
                int time_quantum;
                case 1: sort_arrival(b[i],queueslen[i]);fcfs(b[i],queueslen[i]);break;
                case 2: printf("Enter time_quantum");
                        scanf("%d",&time_quantum);
                        RoundRobinAlgo(b[i],queueslen[i],time_quantum);break;
            }
        }  
    printf("\ntotal_wt: %lf total_tat:%lf",total_wt/queues,total_tat/queues);        
        }