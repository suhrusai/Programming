#include <stdio.h>  
#include <stdlib.h>  
#include<string.h>
typedef struct node{  
char val;  
struct node *next;  
} node;  
node *head;    
void push (char ele)  
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
char pop()  
{  
    char item;  
    node *p;  
    item = head->val; 
    p = head;  
    head = head->next;  
    free(p);       
    return item; 
}  
int main(void){
    char string[200];
    int i;
    scanf("%s",string);
    for(i=0;i<strlen(string);i++)
        push(string[i]);
    for(i=0;i<strlen(string)/2;i++)
        if(pop()!=string[i]){
            printf("Not a palindrome");
            return 0;}
    printf("It is a palindrome");
    
}