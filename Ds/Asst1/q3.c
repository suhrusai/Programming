#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node *next;
} node;
node *first=NULL;
void push (int ele)  
{    
    node *p = ( node*)malloc(sizeof( node));   
    if(!p)  
    {  
        printf("Out of memory!!");   
    }  
    else   
    {  
        if(!first)  
        {         
            p->val = ele;  
            p -> next = NULL;  
            first=p;  
        }   
        else   
        {  
            p->val = ele;  
            p->next = first;  
            first=p;   
        }   
    }  
}   
node * middle(){
    node *slow=first;
    node *fast=first;
        while (fast!= NULL && fast->next != NULL)  
        {  
            fast=fast->next->next;  
            slow=slow->next;  
        }  
        return slow;
    }
    node * reverse() 
    { 
        node *mid=middle();
        node *current = mid->next; 
        node *prev = NULL, *next = NULL; 
  
        while (current != NULL) { 
            next = current->next; 
            current->next = prev;  
            prev = current; 
            current = next; 
        } 
        mid->next=prev;
    }
void display()
{
    node *p=first;
    while(p){
        printf("%d ",p->val);
        p=p->next;
    }
    printf("\n");
}
int main(void){
    int n,ele,i;
    printf("Enter the number of elements: ");
    scanf("%d ",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&ele);
        push(ele);
    }   
    printf("Enter ll: ");
    display();
    reverse();
    printf("Reversed ll: ");
    display();
}