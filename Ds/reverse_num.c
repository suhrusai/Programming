#include <stdio.h>  
#include <stdlib.h>  
#include<math.h>
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
int pop()  
{  
    int item;  
    node *p;  
    if (head == NULL)  
    {  
        printf("Empty");  
        return 0;
    }  
    else  
    {  
        item = head->val;    
        p = head;  
        head = head->next;
        return item;
        free(p);       
    }  
}  
int main(void){
   int i,n,digit,c=0;
   printf("Enter number:");
   scanf("%d",&n);
   while(n){
       digit=n%10;
       n=n/10;
       push(digit);
       c++;
   } 
   int x=0;
   for(i=0;i<c;i++)
        x=x+pop()*pow(10,i);
        printf("Number after reversing: %d",x);
}