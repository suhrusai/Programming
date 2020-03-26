#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
} node;
node *first=NULL;
void push(int ele)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=ele;
	temp->next=first;
	if(!first)
		first=temp;
	first=temp;	
}
int pop(){
    if(!first){
        printf("Stack underlow");
    }
    else{
        int temp=first->data;
        node *tempnode=first;
        first=first->next;
        free(tempnode);
        return temp;
    }
}
void display(){
	node *p=first;
	while(p){
		printf("%d    ",p->data);
		p=p->next;
	}
}
int main(){
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	push(70);
	push(80);
	display();
	printf("\npopped element: %d\n",pop());
	display();
	return 0;
}