#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int coef;
    int degree;
    struct node *next;
} node;
node * create(){
    int n,i,coef,degree;
    printf("Number of elements: ");
    scanf("%d",&n);
    node *first=NULL;
    node *p;
    for(i=0;i<n;i++){

                if(!first)
            {
                        p=(node *)malloc(sizeof(node));
        p->next=NULL;
            first=p;
        }
        else{
            p->next=(node *)malloc(sizeof(node));
            p=p->next;
            p->next=NULL;
        }
        printf("Enter degree and coef: ");
        scanf("%d %d",p->degree,p->coef);
    }
    return first;
}
node * add(node *p1,node *p2){
    node *first;
    node *p;
    while(p1->next && p2->next)
    {
        p=(node *)malloc(sizeof(node));
        p->next=NULL;
        if(!first){
            first=p;
        }
        if(p1->degree<p2->degree){
            p->coef=p1->coef;
            p->degree=p1->degree;
            p1=p1->next;
        }
        else if(p1->degree>p2->degree){
            p->coef=p2->coef;
            p->degree=p2->degree;
            p2=p2->next;            
        }
        else
        {
            p->coef=p2->coef+p1->coef;
            p->degree=p2->degree;
            p2=p2->next;
            p1=p1->next;  
        }
        
    }
    if(!p1){

        p=(node *)malloc(sizeof(node));
        p->next=NULL;
                if(!first){
            first=p;
        }
        p->coef=p1->coef;
        p->degree=p1->degree;
        p1=p1->next;       
    }
    else if(!p2){

        p=(node *)malloc(sizeof(node));
        p->next=NULL;
                if(!first){
            first=p;
        }   
        p->coef=p2->coef;
        p->degree=p2->degree;
        p2=p2->next;     
    }
    return first;
}
void display(node *p){
    while(p){
        printf("%d %d",p->coef,p->degree);
        p=p->next;
    }
}
void main(){
    node *p1=create();
    node *p2=create();
    node *p3=add(p1,p2);
    display(p3);
}