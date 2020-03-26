#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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
        return INT_MIN;
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
int eval(char *b){
    int i=0;
    for(i=0;b[i];i++){
        if(b[i]>='0' && b[i]<='9')
            push(b[i]-'0');
        else{
            int ans2=pop();
            int ans1=pop();
            if(ans1==INT_MIN){
                printf("Invalid postfix expression");
                return INT_MIN;
            }
            int ans;
            switch(b[i]){
                case '+':ans=ans1+ans2;
                        push(ans);
                        break;
                case '-':ans=ans1-ans2;
                        push(ans);
                        break;
                case '*':ans=ans1*ans2;
                        push(ans);
                        break;
                case '/':ans=ans1/ans2;
                        push(ans);
                        break;
                case '%':ans=ans1%ans2; 
                        push(ans);
                        break;
            }
        }
    }
    return pop();
}
void main(){
    printf("%d",eval("235+/+"));
}