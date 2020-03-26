#include<stdio.h>
#include<stdlib.h>
typedef struct dnode{
    int val;
    struct dnode *llink;
    struct dnode *rlink;
} dnode;
dnode *first=NULL;
void delete(int k){
    dnode *p=first;
    if(!first)
        printf("No element to delete");
    else
    {
        if(k==1)
        {
            first=p->rlink;
            free(p->llink);
            first->llink=NULL;
        }
        else
        {
            int c=0;
            while(c<k-1 && p->rlink)
            {
                p=p->rlink;
                c++;
            }
            if(!p->rlink->rlink){
                free(p->rlink);
                p->rlink=NULL;
            }
            else
            {
                dnode *temp=p->rlink;
                p->rlink=temp->rlink;
                temp->rlink->llink=p;   
            }
            
        }
    }
}
void insert(int ele, int k)
{
    dnode *temp=(dnode *)malloc(sizeof(dnode)),*p=first;
    if(!temp)
            printf("System out of memory");
    else
    {
        if(k==1)
        {if(!first)
        {
            temp->val=ele;
            temp->llink=NULL;
            temp->rlink=NULL;
            first=temp;
        }
        else
            {
            temp->val=ele;
            temp->rlink=first;
            temp->llink=NULL;
            first=temp;
            }
        }
        else{
            int c=0;
            while(c<k-1 &&p->rlink)
            {
                p=p->rlink;
                c++;
            }
            if(!p->rlink){
                temp->val=ele;
                p->rlink=temp;
                temp->llink=p;
                temp->rlink=NULL;
            }
            else{
                temp->rlink=p->rlink;
                temp->llink=p;
                p->rlink->llink=temp;
                p->rlink=temp;
            }
        }
    }
}
void display()
{
    dnode *p=first;
    while(p){
        printf("%d ",p->val);
        p=p->rlink;
    }
}
int main(){
    int i,n,ele;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the %d elements: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&ele);
        insert(ele,i+1);
        }
    delete(1);
    delete(3);
    delete(n-3);
    display();
}
/*
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int coef;
	int deg;
	struct node *link;
}node;
node *first=NULL;
void insert_at_end();
void display ();
void main()
{
	int n;
	int degree,coeff,i;
	printf("enter the number of terms\n");
	scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			printf("enter the degree nad coeff:\n");
			scanf("%d %d",&degree,&coeff);
			insert_at_end(degree,coeff);
		}
	display();
}
void insert_at_end(int degree,int coeff)
	{		
			node *temp;
		    temp=(node*)malloc(sizeof(node));
		    temp->deg=degree;
		    temp->coef=coeff;
		    node *p=NULL;
		    temp->link=NULL;;
		    if(first==NULL)
		    {
			    first=temp;
			    
		    }
			else
		    { 
		        p=first;
			    while(!p)
			    {
				    p=p->link;
			    }
			    p->link=temp;
	    	}
		
		
	}
void display()
{
	
	    node *temp;
	    temp=NULL;
		temp=first;
		int c=0;
		while(temp)
		{
			printf("%d %d->",temp->coef,temp->deg);
			temp=temp->link;
		}

	
}*/