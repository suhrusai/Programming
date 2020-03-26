#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} node;
node *first=NULL;
//Normal Linked list insert function
void insert(int ele,int k){
    if(k<0){
        printf("negative index untadha chepandi"); 
        }
    else{
        node *temp=(node *)malloc(sizeof(node));
        temp->data=ele;
        //if the element is the first element
        if(k==0){
                temp->next=first;
                first=temp;
        }
        else{
            node *p=first;
            int counter=0;
            while(p && counter<k-1){
                p=p->next;counter++;
            }
            if(p){
                temp->next=p->next;
                p->next=temp;
            }
            else{
                printf("\nIndex ledhu ra");
            }
        }
    }
}
void sortedinsert(int ele){
    node *p=first;
    int counter=0;
    if(!first){
        insert(ele,0);
        return;
    }
    while(p && p->data<ele){
        p=p->next;
        counter++;
    }
    insert(ele,counter);
}
void display(){
	node *p=first;
	printf("\n");
	while(p){
		printf("%d    ",p->data);
		p=p->next;
	}

}
void main(){
    int i=0;
    sortedinsert(10);
    sortedinsert(340);
    sortedinsert(20);
    sortedinsert(10);
    sortedinsert(-10);
    sortedinsert(-110);
    sortedinsert(200);
    sortedinsert(202);
    sortedinsert(100);
    sortedinsert(20);
    sortedinsert(220);
    sortedinsert(320);
    sortedinsert(-20);
    sortedinsert(-210);
    sortedinsert(-2000);
    display();
}