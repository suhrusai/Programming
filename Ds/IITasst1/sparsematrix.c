#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    int row;
    int col;
    struct node *next;
} node;
node *front=NULL,*rear=NULL;
node *front1=NULL,*rear1=NULL;
void enqueue(node **front,node **rear,int row,int col,int ele){
    node *temp=(node *)malloc(sizeof(node));
    temp->data=ele;
    temp->row=row;
    temp->col=col;
    temp->next=NULL;
    if(!(*rear)){
        *front=temp;
        *rear= temp;
    }
    else{
        (*rear)->next=temp;
        *rear=temp;
    }
}
void matrix_to_sparse(node **front,node **rear){
    int row,col,val,count=0;
    printf("Enter the number of rows and columns");
    scanf("%d %d",&row,&col);
    enqueue(front,rear,row,col,0);
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
        {
            scanf("%d",&val);
            if(val!=0){
                enqueue(front,rear,i+1,j+1,val);
                count++;
            }
        }
        (*front)->data=count;
}
node* sparse_add(node *front1,node *front2){
    node*p1=front1,*p2=front2;
    node *res=NULL,*resrear=NULL;
    int count=0;
    if(front1->col==front2->col && front1->row==front2->col){
        enqueue(&res,&resrear,p1->row,p1->col,0);
        p1=p1->next;
        p2=p2->next;
        while(p1 || p2){
            if(!p1){
                enqueue(&res,&resrear,p2->row,p2->col,p2->data);
                p2=p2->next;
            }
            else if(!p2){
                enqueue(&res,&resrear,p1->row,p1->col,p1->data);
                p1=p1->next;
            }
            else if(p1->row<p2->row){
                enqueue(&res,&resrear,p1->row,p1->col,p1->data);
                p1=p1->next;
            }
            else if(p2->row<p1->row){
                enqueue(&res,&resrear,p2->row,p2->col,p2->data);
                p2=p2->next;
            }
            else if(p2->row==p1->row){
                if(p2->col>p1->col){
                    enqueue(&res,&resrear,p1->row,p1->col,p1->data);
                    p1=p1->next;
                }
            else if(p1->col>p2->col){
                    enqueue(&res,&resrear,p2->row,p2->col,p2->data);
                    p2=p2->next;
            }
            else{
                enqueue(&res,&resrear,p2->row,p2->col,p1->data+p2->data);
                p1=p1->next;
                p2=p2->next;
            }
        }
        count++;

    }
    res->data=count;
    return res;
}
    return NULL;

}
void display(node *front){
    node *p=front;
    while(p){
        printf("%d %d %d\n",p->row,p->col,p->data);
        p=p->next;
    }
}
void main(){
    matrix_to_sparse(&front,&rear);
    //display(front);
    matrix_to_sparse(&front1,&rear1);
    printf("Resultant sparse matrix:\n");
    node *res=sparse_add(front,front1);
    if(!res){
        printf("Matrix addition not possible");
    }
    else{
        display(res);
    }
}
