#include <stdio.h>  
#include <stdlib.h>  
typedef struct node{  
int val;  
struct node *next;  
} node;  
node *head;    
void push (int ele)  
{    
    node *p = ( node*)malloc(sizeof( node));   
    if(!p)  
    {  
        printf("Out of memory!!");   
    }  
    else   
    {  
        if(!head)  
        {         
            p->val = ele;  
            p -> next = NULL;  
            head=p;  
        }   
        else   
        {  
            p->val = ele;  
            p->next = head;  
            head=p;   
        }   
    }  
}   
void pop()  
{  
    int item;  
    node *p;  
    if (head == NULL)  
    {  
        printf("Empty");  
    }  
    else  
    {  
        item = head->val; 
        printf("popped element: %d\n",item);   
        p = head;  
        head = head->next;  
        free(p);       
    }  
}  
void display()  
{  
    int i;  
    node *p;  
    p=head;  
    if(!p)  
    {  
        printf("Stack is empty\n");  
    }  
    else  
    {  
        printf("Stack elements \n");  
        while(p)  
        {  
            printf(" %d",p->val);  
            p = p->next;  
        }  
    }  
}  
void main ()  
{    
    int n,ele;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {   
        scanf("%d",&ele); 
        push(ele);
    }
    printf("Enter the number of times to be popped: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {    
        pop();
    }
    display();
}  