#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
        int age;
        char name[20];
        struct node *lc;
        struct node *rc;
} node;
node *root=NULL;
void insert(int age,char *name){
        node *pp=NULL,*p=root;
        while(p){
                pp=p;
                if(p->age>age)
                        p=p->lc;
                else if(p->age<age)
                {
                        p=p->rc;
                }
                else{
                        printf("Duplicate Age");
                        return;
                }
        }
        int i;
                node *r=(node *)malloc(sizeof(node));
                r->age=age;
                for(i=0;i<strlen(name);i++)
                        r->name[i]=name[i];
                r->lc=NULL;
                r->rc=NULL;
        if(!root){
                root=r;
        }
        else{
                if(pp->age<age){
                        pp->rc=r;
                }
                else{
                        pp->lc=r;
                }
        }

}

void search(int age){
        node *p=root;
        while(p){
        if(age<p->age) p=p->lc;
        else if(age>p->age) p=p->rc;
                else
                {
                        printf("Name: %s\n Age: %d",p->name,p->age);
                        return;
                }
        }
        printf("Element not founf");
}
void main(){
        int i,n=0;
        char name[20];
        int age;
        while(n!=3){
                printf("\n1.Insert");
                printf("\n2.search");
                printf("\n3.Exit");
                printf("\nEnter option: ");
                scanf("%d",&n);
                switch(n){
                case 1:
                printf("Enter the name: ");
                scanf(" %[^\n]s",name);
                printf("Enter the age: ");
                scanf("%d",&age);
                insert(age,name);break;
                case 2:
                printf("Enter the age of the person to be searched: ");
                scanf("%d",&age);
                search(age);break;
                case 3: return;break;
                default: printf("\nInvalid input");
                }
        }
}

