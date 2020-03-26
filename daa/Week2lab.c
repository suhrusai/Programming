#include <stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    int height;
    int actheight;
    struct node *l;
    struct node *r;
} node;
node *root=NULL;
int visited[100]={0};
node *traversed[100];
int len=0;
void preorder(node *root);
int indexval(int data){
    if(data<0){
        return (data*-1)+50;
    }
    return data;
}
void insert(int data){
        int h=0;
        int ah=0;
        node *p=root;
        node *temp=(node *)malloc(sizeof(node));
        temp->l=NULL;
        temp->r=NULL;
        temp->data=data;
        if(!root){
                root=temp;
                temp->height=0;
                temp->actheight=0;
        }else{
                node *pp=NULL;
                while(p){
                pp=p;
                if(p->data<data){
                        p=p->r;
                        h++;
                        ah++;
                }
                else if(p->data>data){
                        p=p->l;
                        h--;
                        ah++;
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
            temp->height=h;
            temp->actheight=ah;
        }
        printf("Data : %d  Height: %d Acttual Height: %d\n",temp->data,temp->height,temp->actheight);
}
void sort(int mul,int height){
    int i=0;int j=0;
    int cmp1,cmp2;
        for(i=0;i<len;i++)
        for(j=0;j<len;j++){
            if(height==1){
                cmp1=mul*traversed[i]->height;
                cmp2=mul*traversed[i]->height;
            }else{
               cmp1=mul*traversed[i]->actheight;
               cmp2=mul*traversed[j]->actheight;
            }
            if(cmp1<cmp2){
                node *temp=traversed[i];
                traversed[i]=traversed[j];
                traversed[j]=temp;
            }
        }
}
void leftview(node *root){
    sort(1,1);
    int i=1;
    printf("Left View: ");
    for(i=0;i<len;i++){
        if(!visited[indexval(traversed[i]->actheight)]){
            printf("%d ",traversed[i]->data);
            visited[indexval(traversed[i]->actheight)]=1;
        }
    }
}
void rightview(node *root){
    sort(-1,1);
    int i=1;
    printf("Right View: ");
    for(i=0;i<len;i++){
        if(!visited[indexval(traversed[i]->actheight)]){
            printf("%d ",traversed[i]->data);
            visited[indexval(traversed[i]->actheight)]=1;
        }
    }  
}
void topview(node *root){
    sort(1,-1);
    int i=1;
    printf("Top View: ");
    for(i=0;i<len;i++){
        if(!visited[indexval(traversed[i]->height)]){
            printf("%d ",traversed[i]->data);
            visited[indexval(traversed[i]->height)]=1;
        }
    }
}
void display(){
    int i=0;
        for(i=0;i<len;i++){
            printf("\nData: %d Height: %d actheight: %d",traversed[i]->data,traversed[i]->height,traversed[i]->actheight);
        }
}
void bottomview(node *root){
        int i,j;
    sort(-1,-1);
    printf("Bottom View: ");
    for(i=0;i<len;i++){
        if(!visited[indexval(traversed[i]->height)]){
            printf("%d ",traversed[i]->data);
            visited[indexval(traversed[i]->height)]=1;
        }
    }
}
void inorder(node *root){
        if(root){
                inorder(root->l);
                printf("%d ",root->data);
                inorder(root->r);
        }
}
void preorder(node *root){
            if(root){
                traversed[len++]=root;
                //printf("%d ",root->data);
                preorder(root->l);
                preorder(root->r);
        }
}
int main()
{
        int opt=1;
        int ele;
        int i;
        printf("1.insert,2.top view,3.Bottom view,4. Right View,5. Left View ,6.Exit");
        while(1){
                for(i=0;i<100;i++)
                    visited[i]=0;
                    len=0;
                    preorder(root);
                printf("Enter an option: ");
                scanf("%d",&opt);
                switch(opt){
                        case 1: printf("Enter element: ");scanf("%d",&ele);
                                insert(ele);
                                printf("Tree :");
                                inorder(root);break;
                        case 2: topview(root);break;
                        case 3: bottomview(root);break;
                        case 4: rightview(root);display();break;
                        case 5: leftview(root);display();break;
                        case 6: preorder(root);return;break;
                }
    }
}