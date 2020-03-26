#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} node;
node *first=NULL;

void insert_beg()
{
    int num;
    node *p=(node *)malloc(sizeof(node));
    scanf("%d",&num);
    p->data=num;
 
    if(first==NULL)        //If list is empty
    {
        p->next=NULL;
        first=p;
    }
    else
    {
        p->next=first;
        first=p;
    }
}
 
void insert_end()
{
    int num;
    node *temp=(node *)malloc(sizeof(node)),*p=first;
    scanf("%d",&num);
    temp->data=num;
    temp->next=NULL;
 
    if(!p)        //If list is empty
    {
        first=temp;
    }
    else
    {
        p=first;
        while(p->next)
        p=p->next;
        p->next=temp;
    }
} 
void delete_beg()
{
    node *temp;
    if(!first)
    {
        printf("The list is empty!!");
    }
    else
    {
        node *temp=first;
        first=first->next;
        printf("Deleted element is %d",temp->data);
        free(temp);
    }
}
int main()
{
    int i,n;
    node *p=first;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        insert_beg();
    }
    //insert_end();
    delete_beg();
    p=first;
    printf("\n");
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
}