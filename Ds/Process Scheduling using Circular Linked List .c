#include<stdio.h>
#include<stdlib.h>
typedef struct process{
        int id;
        int bustime;
        struct process *next;
} process;
process *first=NULL;
void delete(int k){
        process *p=first;
        int count=0;
/*
        if(k==1)
        {
                if(first->next=first)
                {
                        free(first);
                        first=NULL;
                }
                else
                {
                        process *temp=first;
                        first=first->next;
                        free(temp);
                        p=first;
                        while(p->next!=first)
                        {
                                p=p->next;
                        }
                        p->next=first;
                }
        }
        else{*/
                process *temp;
                while(count<k-1 && p->next!=first)
                {
                        p=p->next;
                        count++;
                }
                if(p==first && k==1)
                {
                        while(p->next!=first)
                                p=p->next;
                        p->next=first->next;
                        //free(first);
                        first=first->next;
                }
                else
                {
                        if(p->next==first)
                        {
                                p=p->next;

                        p->next=temp;
                        temp->next=first;
                        p->next=NULL;
                        //free(p);
                        }
                        else
                        {
                                temp->next=p->next;//free(p);
                        }

                }
int processor(int time_splice)
{
        process *p=first;
        int count=0;
        if(first->next=first)
        {
                printf("All processes complete");
                return 0;
        }
        do{
                count++;
                p->bustime=p->bustime-time_splice;
                if(p->bustime<=0)
                {
                        delete(count);
                        printf("%d",count);
                }
                p=p->next;
        }while(p!=first);
        return 1;
}
void display()
{
        process *p=first;
        do{
                printf("Id: %d time remaining: %d\n",p->id,p->bustime);
                p=p->next;
        }while(p!=first);
        printf("\n");
}
void main(){
        int i,n;
int processor(int time_splice)
{
        process *p=first;
        int count=0;
        if(first->next=first)
        {
                printf("All processes complete");
                return 0;
        }
        do{
                count++;
                p->bustime=p->bustime-time_splice;
                if(p->bustime<=0)
                {
                        delete(count);
                        printf("%d",count);
                }
                p=p->next;
        }while(p!=first);
        return 1;
}
void display()
{
        process *p=first;
        do{
                printf("Id: %d time remaining: %d\n",p->id,p->bustime);
                p=p->next;
        }while(p!=first);
        printf("\n");
}
void main(){
        int i,n;
        printf("Enter the numbers of processes: ");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                process *temp=(process *)malloc(sizeof(process));
                process *prev;
                scanf("%d ",&temp->id);
                scanf("%d",&temp->bustime);
                printf("Input taken");
                if(i==0)
                {
                        first=temp;
                        first->next=temp;
                        prev=first;
                }
                else
                {
                        prev->next=temp;
                        temp->next=first;
                        prev=temp;
                }
        }
        display();
    while(processor(10)!=0)
                display();
}