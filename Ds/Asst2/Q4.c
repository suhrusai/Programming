#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
} node;
struct Queue{

    int data; /*integer variable*/
    struct Tree *node; 
    struct Queue *next;
}*queue;
node *create()
{
	node *p;
	int x;
	printf("Enter data(-1 for no data):");
	scanf("%d",&x);
	
	if(x==-1)
		return NULL;
	
	p=(node*)malloc(sizeof(node));
	p->data=x;
	
	printf("Enter left child of %d:\n",x);
	p->left=create();
 
	printf("Enter right child of %d:\n",x);
	p->right=create();
	
	return p;
}
 
void preorder(node *t)		//address of root node is passed in t
{
	if(t!=NULL)
	{
		printf("\n%d",t->data);		//visit the root
		preorder(t->left);		//preorder traversal on left subtree
		preorder(t->right);		//preorder traversal om right subtree
	}
}
void print_top_view(struct node *temp){
    if(temp)
    {    
        struct Queue*help,*new_node=(struct Queue*)malloc(sizeof(struct Queue));
        new_node->data=0;
        new_node->next=NULL;
        new_node->node=temp;
        queue=new_node;  
        help=new_node; 
        int min_value=0,max_value=0;
        while(temp)
        {   
        
            if(temp->left_child)
            {
                new_node->next=(struct Queue*)malloc(sizeof(struct Queue));
                new_node->next->data=help->data+1;
                new_node->next->node=temp->left_child;
                new_node->next->next=NULL;
                new_node=new_node->next;
                if(help->data+1>max_value){
                    max_value=help->data+1;
                }   
            }
            if(temp->right_child)
            {
                new_node->next=(struct Queue*)malloc(sizeof(struct Queue));
                new_node->next->data=help->data-1;
                new_node->next->node=temp->right_child;

                new_node->next->next=NULL;
                new_node=new_node->next;
                if(help->data-1<min_value){
                    min_value=help->data-1;

                }
            }
            help=help->next;
            if(help){
                temp=help->node;
            }
            else{
                break;
            }
        }
        printf("\n Top View is :");
        while(min_value<=max_value){    
            help=queue;
            while(help){
                if(help->data==min_value){
                    printf(" %d",help->node->data);
                    break;
                }
                help=help->next;
            }
            //printf(" %d",min_value);
            min_value++;
        }
    }
    else
    {
        printf("\n No data in this tree\n");
    }

int main()
{	
	node *root;
	root=create();
	printf("\nThe preorder traversal of tree is:\n");
	preorder(root);
	top_view(root);
	scanf(" %s");
	return 0;
}