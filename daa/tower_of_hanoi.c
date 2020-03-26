#include<stdio.h>
#include<stdlib.h>
void tower_of_hanoi(int n, char from, char to, char aux){
	if(n==1){
		printf("Move disk 1 from rod %c to rod %c\n", from, to); 
	        return;
	}	
	tower_of_hanoi(n-1, from, aux, to); 
	printf("Move disk %d from rod %c to rod %c\n", n, from, to);
	tower_of_hanoi(n-1, aux, to, from); 
}
void main(){
	int n;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	tower_of_hanoi(n,'F','T','A');
}
