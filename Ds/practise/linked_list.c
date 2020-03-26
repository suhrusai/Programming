#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int value;
    struct node *next;
} node;
node *first=NULL;
void insert(int ele,int k){
    /*node *p=first;
    int count=0;
    while(p && count<k){
        p=p->next;
        count++;
    }
    node *temp=(node *)malloc(sizeof(node));
    temp->next=p->next;
    p->next=temp;
    temp->value=k;*/
    node *p;int count;
    node *temp=malloc(sizeof(node));
    temp->value=ele;
    if(!temp){
        printf("No memory");
        return;
    }
    p=first;
    if(k==1)
    {
        temp->next=first;
        first=temp;
    }
    else
    {
        while(count<k-1 && p){
            p=p->next;
            count++;
        }
        if(p)
        {
            temp->next=p->next;
            p->next=temp;

        }
        else
        printf("Insertion not possible");
    }
}
void find(int k)
{

}
void search(){}
int main(void)
{    
    first=(node *)malloc(sizeof(node));
    node *p=first;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p->value);
        p->next=(node *)malloc(sizeof(node));
        p=p->next;
    }
        for(int i=0;i<n;i++)
        {printf("1 %d ",p->value);p=p->next;}
    int ele,k;
    printf("Enter ele and k");
    scanf("%d %d",ele,k);
    insert(ele,k);
    p=first;
    for(int i=0;i<n;i++)
        {printf("1 %d ",p->value);p=p->next;}
}