
#include <stdio.h> 
#include <stdlib.h> 
#include<string.h>
typedef struct node { 
	int salary; 
    char name[20];
    char id[8];	
	struct node* next; 
} node; 
struct Queue { 
    struct node *front, *rear; 
} Queue; 
node *front=NULL,*rear=NULL; 
node* newNode(int k,char empid[],char name[]) 
{ 
	node* temp = (node*)malloc(sizeof(struct node)); 
	temp->salary = k;
    strcpy(temp->id,empid);
    strcpy(temp->name,name); 
	temp->next = NULL; 
	return temp; 
} 
void enQueue(int k,char empid[],char name[]) 
{ 
	// Create a new LL node 
	node* temp = newNode(k,empid,name); 

	// If queue is empty, then new node is front and rear both 
	if (rear == NULL) { 
		front = rear = temp; 
		return; 
	} 
	rear->next = temp; 
	rear = temp; 
}  
node* deQueue() 
{ 
	// If queue is empty, return NULL. 
	if (front == NULL) 
		return NULL; 

	// Store previous front and move front one node ahead 
	node* temp = front;  
	front = front->next;  
	if (front == NULL) 
		rear = NULL; 
	return temp; 
}  
void swap(struct node *a, struct node *b) 
{ 
    int temp = a->salary; 
    a->salary = b->salary; 
    b->salary = temp;
    char tempname[20];
    strcpy(tempname,a->name);
    strcpy(a->name,b->name);
    strcpy(b->name,tempname);
    strcpy(tempname,a->id);
    strcpy(a->id,b->id);
    strcpy(b->id,tempname);
} 
void bubbleSort(struct node *start) 
{ 
    int swapped, i; 
    struct node *ptr1; 
    struct node *lptr = NULL; 
  
    /* Checking for empty list */
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->salary > ptr1->next->salary) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 
  
/* function to swap salary of two nodes a and b*/

int main() 
{ 
	int n,i,salary;
	char name[20],id[8];
    node *popped=NULL;
    printf("1.New entry\n2.Delete\n3.For sorting\n4.Display\n5.Exit\n");
	do{
	    printf("Enter option: ");
		scanf("%d",&n);
		switch(n){
			case 1: 		printf("Enter the details: \n");
		printf("Enter the name: ");
		scanf(" %s",name);
		printf("Enter the employee id: ");
		scanf(" %s",id);
		printf("Enter his/her salary: ");
		scanf("%d",&salary);
		enQueue(salary,name,id);break;
		case 2: popped=deQueue();if(popped){
			printf("Removed record is Empid: %s\nName: %s\nSalary: %d\n",popped->id,popped->name,popped->salary);free(popped);
		};break;
		case 3: bubbleSort(front);break;
		case 4:
		popped=front;
		while(popped){
			printf("Empid: %s\nName: %s\nSalary: %d\n\n\n",popped->id,popped->name,popped->salary);
			popped=popped->next;
		}break;
		case 5: return 0;break;
		
		}
	}while(n!=5);
	/*printf("Enter the number of inputs: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the details: \n");
		printf("Enter the name: ");
		scanf(" %s ",name);
		printf("Enter the employee id: ");
		scanf(" %s",id);
		printf("Enter his/her salary: ");
		scanf("%d",&salary);
		enQueue(salary,name,id);
	}
	node *popped=deQueue(); 
	if (popped!= NULL) 
		printf("Dequeued item is %d", popped->salary);*/
	 
	return 0; 
} 
