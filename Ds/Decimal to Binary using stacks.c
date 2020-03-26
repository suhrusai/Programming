#include<stdio.h>
#include<stdlib.h>
typedef struct node{
        int data;
        struct node *next;
} node;
node *head=NULL;
int pop()
{
                int val;
                node *temp=head;
                val=head->data;
                head=head->next;
               free(temp);
                return val;
}
void push(int ele)
{
        node *p=(node *)malloc(sizeof(node));
        p->data=ele;
        if(!head){
                head=p;
                head->next=NULL;
        }
        else{
                p->next=head;
                head=p;
        }

}
void decimal_to_binary(int n){
        while(n){
                push(n%2);
                n=n/2;
        }
        while(head){
                printf("%d\a",pop());
        }
}
int main(void){
int n;
printf("Enter value of n:");
scanf("%d",&n);
printf("Binary Equivalent: ");
decimal_to_binary(n);
}

