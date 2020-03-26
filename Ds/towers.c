#include <stdio.h>  
#include <math.h>  
#include <stdlib.h>  
  
// A structure to represent a stack  
typedef struct node
{  
int capacity;  
int top;  
int *array;  
} node;  
  
// function to create a stack of given capacity.  
node* create(int capacity)  
{  
    node* stack=  
        (node*) malloc(sizeof(node));  
    stack -> capacity = capacity;  
    stack -> top = -1;  
    stack -> array =  
        (int*) malloc(stack -> capacity * sizeof(int));  
    return stack;  
}  
  
// Stack is full when top is equal to the last index  
int isFull(node* stack)  
{  
return (stack->top == stack->capacity - 1);  
}  
  
// Stack is empty when top is equal to -1  
int isEmpty(node* stack)  
{  
return (stack->top == -1);  
}  
  
// Function to add an item to stack. It increases  
// top by 1  
void push(node *stack, int item)  
{  
    if (stack->top == stack->capacity - 1)  
        return;  
    stack -> array[++stack -> top] = item;  
}  
  
// Function to remove an item from stack. It  
// decreases top by 1  
int pop(node* stack)  
{  
    if (stack->top == -1)  
        return 0;     
    return stack -> array[stack -> top--];  
}  
  
//Function to show the movement of disks  
void moveDisk(char from, char to, int disk)  
{  
    printf("Move disk %d from %c to %c\n",  
        disk, from, to);  
} 
  
// Function to implement legal movement between  
// two poles  
void move(node *src,  
            node *dest, char s, char d)  
{  
    int pole1 = pop(src);  
    int pole2 = pop(dest);  
  
    // When pole 1 is empty  
    if (pole1 == 0)  
    {  
        push(src, pole2);  
        moveDisk(d, s, pole2);  
    }  
  
    // When pole2 pole is empty  
    else if (pole2 == 0)  
    {  
        push(dest, pole1);  
        moveDisk(s, d, pole1);  
    }  
  
    // When top disk of pole1 > top disk of pole2  
    else if (pole1 > pole2)  
    {  
        push(src, pole1);  
        push(src, pole2);  
        moveDisk(d, s, pole2);  
    }  
  
    // When top disk of pole1 < top disk of pole2  
    else
    {  
        push(dest, pole2);  
        push(dest, pole1);  
        moveDisk(s, d, pole1);  
    }  
}  
  
//Function to implement TOH puzzle  
void toh(int n, node  
            *src, node *aux,  
            node *dest)  
{  
    int i, total_num_of_moves;  
    char s = 'S', d = 'D', a = 'A';  
  
    //If number of disks is even, then interchange  
    //destination pole and auxiliary pole  
    if (n % 2 == 0)  
    {  
        char temp = d;  
        d = a;  
        a = temp;  
    }  
    total_num_of_moves = pow(2, n) - 1;  
  
    //Larger disks will be pushed first  
    for (i = n; i >= 1; i--)  
        push(src, i);  
  
    for (i = 1; i <= total_num_of_moves; i++)  
    {  
        if (i % 3 == 1)  
        move(src, dest, s, d);  
  
        else if (i % 3 == 2)  
        move(src, aux, s, a);  
  
        else if (i % 3 == 0)  
        move(aux, dest, a, d);  
    }  
}  
int main()  
{  
    int n = 3;  
    node *src, *dest, *aux;  
    src = create(n);  
    aux = create(n);  
    dest = create(n);  
  
    toh(n, src, aux, dest);  
    return 0;  
}  