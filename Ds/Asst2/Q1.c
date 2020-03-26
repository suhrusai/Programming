//Write a program to implement Towers of Hanoi... Show the
//working of this concept using stack.
#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 
#include <limits.h>  
typedef struct Stack 
{ 
int capacity; 
int top; 
int *array; 
} stack;  
stack *createStack(int capacity) 
{ 
	stack *s = (stack *) malloc(sizeof(stack)); 
	s -> capacity = capacity; 
	s -> top = -1; 
	s -> array = (int*) malloc(s -> capacity * sizeof(int)); 
	return s; 
}  
int isFull(stack *stack) 
{ 
return (stack->top == stack->capacity - 1); 
}  
int isEmpty(stack *stack) 
{ 
return (stack->top == -1); 
}
void push(stack  *stack, int item) 
{ 
	if (isFull(stack)) 
		return; 
	stack -> array[++stack -> top] = item; 
}  
int pop(stack *s) 
{ 
	if (isEmpty(s)) 
		return INT_MIN; 
	return s -> array[s -> top--]; 
} 

//Function to show the movement of disks 
void move(char fromPeg, char toPeg, int disk) 
{ 
	printf("Move the disk %d from %c to %c\n", 
		disk, fromPeg, toPeg); 
} 
void movedisk(stack  *src,stack  *dest, char s, char d) 
{ 

	int pole1TopDisk = pop(src); 
	int pole2TopDisk = pop(dest); 
	if (pole1TopDisk == INT_MIN) 
	{ 
		push(src, pole2TopDisk); 
		move(d, s, pole2TopDisk); 
	}
	else if (pole2TopDisk == INT_MIN) 
	{ 
		push(dest, pole1TopDisk); 
		move(s, d, pole1TopDisk); 
	} 
	else if (pole1TopDisk > pole2TopDisk) 
	{ 
		push(src, pole1TopDisk); 
		push(src, pole2TopDisk); 
		move(d, s, pole2TopDisk); 
	}  
	else
	{ 
		push(dest, pole2TopDisk); 
		push(dest, pole1TopDisk); 
		move(s, d, pole1TopDisk); 
	} 
} 
void toh(int num_of_disks, struct Stack 
			*src, stack  *aux, 
			stack  *dest) 
{ 
	int i, total_num_of_moves; 
	char s = 'S', d = 'D', a = 'A'; 

	//If number of disks is even, then interchange 
	//destination pole and auxiliary pole 
	if (num_of_disks % 2 == 0) 
	{ 
		char temp = d; 
		d = a; 
		a = temp; 
	} 
	total_num_of_moves = pow(2, num_of_disks) - 1; 

	//Larger disks will be pushed first 
	for (i = num_of_disks; i >= 1; i--) 
		push(src, i); 

	for (i = 1; i <= total_num_of_moves; i++) 
	{ 
		if (i % 3 == 1) 
		movedisk(src, dest, s, d); 

		else if (i % 3 == 2) 
		movedisk(src, aux, s, a); 

		else if (i % 3 == 0) 
		movedisk(aux, dest, a, d); 
	} 
} 
int main() 
{ 
	// Input: number of disks 
	int num_of_disks = 2; 
	stack  *src, *dest, *aux;  
	src = createStack(num_of_disks); 
	aux = createStack(num_of_disks); 
	dest = createStack(num_of_disks); 

	toh(num_of_disks, src, aux, dest); 
	return 0; 
} 
