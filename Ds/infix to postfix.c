#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
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
int prcd(char ch)
{
    if(ch=='*'|| ch=='/')
        return 3;
    else if(ch=='+' ||ch=='-')
        return 2;
    else if(ch=='(')
        return 1;
    else 
        return 0;
}
char top(){
    if(head==NULL){
        return 0;
    }
    else
        return head->data;
}
char* infix_to_postfix(char *a, char *b){
    int j=0,i=0;
    char ch;
    for(i=0;a[i];i++){
        if(isalpha(a[i]) || isdigit(a[i])) 
            b[j++]=a[i];
        else if(a[i]=='(')
            push(a[i]);
        else if(a[i]==')')
            while(top()!='(')
                b[j++]=ch;
        else if(a[i]=='+' ||a[i]=='-'|| a[i]=='/' || a[i]=='*')
        {
            char ch=pop();
            while(prcd(ch)>=prcd(a[i]))
                {
                    b[j++]=pop();
                    ch=pop();
                }
                push(ch);
                push(a[i]);
        }
        else
        {
            printf("Invalid Expression");
        }
        i++;
    }
    while(top()!='#')
    {
        b[j++]=pop();
    }
    b[j]='#';
    return b;
}
int main(){
    char b[100];
    printf("%s",infix_to_postfix("2+3+5",b));
}