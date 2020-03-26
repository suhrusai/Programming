#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} node; 
node *first=NULL;
int delete(int k)
{
	int count=0;
	node *temp=NULL;
	node *p = first;
	if(k<1 || !first)
	{
		printf("Can't Delete\n");
	}
	else
	{
		while(count<k-1 && p->next!= first)
		{
			temp= p;
			p = p->next;
			count++;
		}
		if(!p)
		{
			printf("No kth position\n");
		}
		else
		{
			if(p==first && k==1)
            {
                while(p->next!=first)
                {
                    p=p->next;
                }
                p->next=first->next;
                free(first);
                first=p->next;
			}
			else
			{
				if(p->next==first)
				{
                 while(p->next!=first)
                {
                    p=p->next;
                }
                    p->next=temp;
					temp->next =first;
					p->next = NULL;
					free(p);
				}
				else{
				temp->next = p->next;
				free(p);
				}
			}
		}
	}
	return 0;
}
void insert(int k,int ele){
    node *p=first;
    int c=0;
    node *temp=(node *)malloc(sizeof(node));
    if(!temp)
        printf("Out of memory");
    else if(k<0)
        printf("Give a valid index");
    else if(k==1){
        if(!first){
            temp->data=ele;
            first=temp;
            temp->next=temp;
        }
        else{
            temp->data=ele;
            while(p->next!=first){
                p=p->next;
            }
            temp->next=first;
            first=temp;
            p->next=first;
        }
    }
    else{
        while(c<k-1 && p->next!=first){
            p=p->next;
        }
        temp->data=ele;
        temp->next=p->next;
        p->next=temp;
    }
}
void display(){
    node *p=first;
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=first);
    printf("\n");
}
int main(void){
    int i;
    for(i=0;i<6;i++){
        insert(i+1,i+1);
    }
    display();
    delete(1);
    delete(3);
    delete(4);
    display();
}