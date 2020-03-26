#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<limits.h>
typedef struct node{
    int data;
    struct node *lchild;
    struct node *rchild;    
} node;
void postorder(node *p)
{
        if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}
void preorder(node *p)
{
        if(p){
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
    
}
void inorder(node *p)
{
        preorder(p->lchild);
        printf("%d ",p->data);
        preorder(p->rchild);
    
}
void insert(node **root,int x){
    node *pp=NULL;
    node *p=*root;
    while(p){
        pp=p;
        if(p->data>x)
            p=p->lchild;
        else if(p->data<x){
            p=p->rchild;
        }
        else{
            printf("Duplicate");
            return;
        }
    }
    node *r=(node *) malloc(sizeof(node));
    r->data=x;
    if(*root){
        if(x<pp->data)
            pp->lchild=r;
        else
            pp->rchild=r;
        
    }
    else
    {
        *root=r;
    }
    
}
void delete(node **s,int k)
{
    root=*s;
    node *p=root;
    node *pp=NULL;
    while(p && p->data!=k){
        pp=p;
        if(k<p->data)
            p=p->lchild;
        else
            p=p->rchild;
    }
    if(!p){
        printf("No data");
        return ;}
    node *ps=NULL;
    if(p->lchild && p->rchild){
        s=p->lchild;
        ps=p;
        while (s->rchild)
        {
            ps=s;
            s=s->rchild;
        }
        p->data=s->data;
        p=s;
        pp=ps;    
    }
    node *c=NULL;
    if(p->lchild){
        c=p->lchild;
    }
    else{
        c=p->rchild;
    }
    if(p==*root)
        *root=c;
    else{
        if (p==pp->lchild)
        {
            pp->lchild=c;
        }
        else
        {
            pp->rchild=c;
        }
        free(p);
    }
    
}
void main(){
    int n=2;
    node *root=NULL;
    while(n!=80){
        scanf("%d",&n);
        insert(&root,n);
    }
    printf("Inorder: ");
    inorder(root);
    printf("Postorder: ");
    postorder(root);
    printf("Preorder: ");
    preorder(root);
    delete(&root,80);
    preorder(root);
}