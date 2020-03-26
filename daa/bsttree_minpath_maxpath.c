#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define STACK_LENGTH 100
typedef struct node{
        int data;
        struct node *l;
        struct node *r;
} node;
int top=0;
int a[100]={0};
node *root;
int pop(){
    if(top!=0)
    {int temp=*(a+top-1);
    top--;
    return temp;
    }
    //a=(int )realloc(a,sizeof(int)(top-1));  
}
void push(int ele){
    a[top++]=ele;
}
void insert(int data){
        node *p=root;
        node *temp=(node *)malloc(sizeof(node));
        temp->l=NULL;
        temp->r=NULL;
        temp->data=data;
        if(!root){
                root=temp;
        }else{
                node *pp=NULL;
                while(p){
                pp=p;
                if(p->data<data)
                        p=p->r;
                else if(p->data>data){
                        p=p->l;
                        }
                else{
                        printf("\nDuplicate elements");
                        return ;
                }
                }
        if(pp->data<data)
                pp->r=temp;
        else if(pp->data>data){
                pp->l=temp;
                }
        }
}
int height(node *root){
        if(root){
                int h1=height(root->l)+1;
                int h2=height(root->r)+1;
        if(h1>h2){
                return h1;
        }
        else{
                return h2;
        }
        }
        return 0;
}
int minheight(node *root){
        if(root){
                int i;
                /*printf("\n Element: ");
                for(i=0;i<top;i++)
                    printf("%d ",a[i]);*/
        if(root->r && root->l){
                int h1=minheight(root->l)+1;
                int h2=minheight(root->r)+1;
                
                if(h1<h2){

                        int i;
                        for(i=0;i<h2-1;i++)
                            pop();
                        push(root->data);
                        return h1;
                    
                }
                else{
                        int i;
                        int temp[h2];                        
                        for(i=0;i<h2-1;i++)
                            temp[i]=pop();
                        while(top!=0)
                            pop();
                        for(i=0;i<h2-1;i++)
                            push(temp[i]);
                        push(root->data);
                        return h2;
                }

        }
        if(root->r==NULL && root->l){ push(root->data);return minheight(root->l)+1;}
        else if(root->l==NULL && root->r){push(root->data);return minheight(root->r)+1;}
        else if(!(root->l) && !(root->r)) {push(root->data);return 1;}
        }
        return 0;
}
void inorder(node *root){
        if(root){
                inorder(root->l);
                printf("%d ",root->data);
                inorder(root->r);
        }
}
void main(){
        int opt=1;
        int ele;
        printf("1.insert,2.min and max depth,3.Exit");
        while(1){
                printf("Enter an option: ");
                scanf("%d",&opt);
                switch(opt){
                        case 1: printf("Enter element: ");scanf("%d",&ele);
                                insert(ele);
                                // printf("Tree :");
                                // inorder(root);
                                break;
                        case 2:printf("\nmin: %d max: %d",minheight(root),height(root));
                                            int i;
                                printf("\n Minimum Element: ");
                                                while(top!=0)
                                                    printf("%d ",pop());
                            break;
                        case 3: return;
                }
        }
}