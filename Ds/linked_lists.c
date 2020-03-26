#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int  data;
    struct node* link;
} node;
node *first;
void create(int ele)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = ele;
	temp->link = first;
	first = temp;
}
void insert(int k,int ele)
{
    node *temp=(node*)malloc(sizeof(node));
    node *p;
	p = first;
    int c=0;
    while(p && c<k)
    {
        p=p->link;
        c++;
    }
    if(c==k)
    {
        temp->data=ele;
        temp->link=p->link;
        p->link=temp;
    }
}
void reverse(){
    
}
void delete(int k){
    int c=0;
    node *temp=(node *)malloc(sizeof(node)),*p=first;
    while(c<k-1 && p){
        p=p->link;
        c++;
    }
    temp=p->link;
    p->link=temp->link;
    free(temp);
}
int main(){
    for(int i=0;i<5;i++)
        {
            int n;
            scanf("%d",&n);
            create(n);
        }
    insert(3,20);
    delete(2);
    node *p;
	p = first;
	printf("Elemments: ");
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p = p->link;
	}
	printf("\n");
}
