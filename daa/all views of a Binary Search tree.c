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
        //printf("Data : %d  Height: %d Acttual Height: %d\n",temp->data,temp->height,temp->actheight);
}
void sort(int mul,int height){
    int i=0;int j=0;
    int cmp1,cmp2,cmp3,cmp4;
        for(i=0;i<len;i++)
        for(j=0;j<len;j++){
                if(height==1){
                    cmp1=traversed[i]->height;
                    cmp2=traversed[j]->height;
                }
                else{
               cmp1=traversed[i]->actheight;
               cmp2=traversed[j]->actheight;
                }
                if(mul*cmp1<mul*cmp2){
                    node *temp=traversed[i];
                    traversed[i]=traversed[j];
                    traversed[j]=temp;
                }
    }
}
void view(node *root,int key,int vertical){
    sort(key,vertical);
    int i=1;
    int cmpval;
    for(i=0;i<len;i++){
        cmpval= (vertical==-1)?traversed[i]->height:traversed[i]->actheight;
        if(!visited[indexval(cmpval)]){
            printf("%d ",traversed[i]->data);
            visited[indexval(cmpval)]=1;
        }
    }
}
// void inorder(node *root){
//         if(root){
//                 inorder(root->l);
//                 printf("%d ",root->data);
//                 inorder(root->r);
//         }
// }
void preorder(node *root){
            if(root){

                //printf("%d ",root->data);
                traversed[len++]=root;
                preorder(root->l);
                preorder(root->r);
        }
}
int main()
{
        int opt=1;
        int ele;
        int i;
        printf("1.insert,2.top view,3.Bottom view,4. Left View,5. Right View ,6.Exit");
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
                                break;
                        case 2: printf("Top View: ");view(root,1,-1);break;
                        case 3: printf("Bottom View: ");view(root,-1,-1);;break;
                        case 4: printf("Left View: ");view(root,1,1);break;
                        case 5: printf("Right View: ");view(root,-1,1);break;
                        case 6: preorder(root);return;break;
                }
    }
}