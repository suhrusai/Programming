#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct process{
        int pid;
        int bt;
        int at;

} process;
void sort_arrival(process a[],int n){
        int i,j;
        for(i=0;i<n;i++)
                for(j=0;j<n;j++){
                        if(a[i].at<a[j].at){
                                process temp=a[i];
                                a[i]=a[j];
                                a[j]=temp;
                        }
                        else if(a[i].at==a[j].at && a[i].pid<a[j].pid){
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
                printf("Enter pid: ");
                scanf("%d",&a[i].pid);
                printf("Enter bt:");
                scanf("%d",&a[i].bt);
                printf("Enter at:");
                scanf("%d",&a[i].at);
        }
        sort_arrival(a,n);
        int time=0;
        i=0;
        int wt[MAX]={0};
        int tat[MAX]={0};
        while(i<n){
                if(a[i].at<=time)
                {
                        wt[i]=time-a[i].at;
                        time+=a[i].bt;
                        tat[i]=time-a[i].at;
                        printf("\npid : %d at: %d bt: %d wt: %d tat:%d \n",a[i].pid,a[i].at,a[i].bt,wt[i],tat[i]);
                        i++;
                        continue;
                }
                time++;
        }
        printf("\nWaiting time avg: %lf ,Turn around time: %lf",avg(wt,n),avg(tat,i));

}
