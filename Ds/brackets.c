#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    char data;
    struct node *next;
} node;
node *head=NULL;
void push (char ele)  
{    
    node *p = ( node*)malloc(sizeof( node));   
        if(!head)  
        {         
            p->data = ele;  
            p -> next = NULL;  
            head=p;  
        }   
        else   
        {  
            p->data = ele;  
            p->next = head;  
            head=p;   
        }     
}   
int pop()  
{  
    int item;  
    node *p;  
    if (head == NULL)  
    {  
        //printf("Empty");  
        return 0;
    }  
    else  
    {  
        item = head->data;    
        p = head;  
        head = head->next;
        return item;
        free(p);       
    }  
}
char top()
{
    return head->data;
}

void paranthesis_check(char s[]){
    int i,count=0;
    for(i=0;s[i];i++){
        if(s[i]=='(' || s[i]=='[' ||s[i]=='{')
            push(s[i]);
        else if(s[i]==')' || s[i]==']' ||s[i]=='}')
        {
            if(top()=='(' && s[i]==')')
            {
                pop();
            }
            else if(top()=='[' && s[i]==']')
            {
                pop();
            }
            else if(top()=='{' && s[i]=='}')
            {
                pop();
            }
            else{
                count++;
            }
        }
    }
    if(!pop() && !count)
        printf("Matched");
    else
        printf("Not matched");
}
//{[}]{}
int main(){
    char s[100];
    scanf("%[^\n]s",s);
    paranthesis_check(s);
}