#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node{
  int blksize;
  int pid;
} memblk;
typedef struct process{
  int size;
  int pid;
} process;
int best_fit(memblk memory[],int memblks,process processes[],int no_of_process){
  int i,j,k,tottal_int_frag=0;
  for(i=0;i<no_of_process;i++){
    int min_intfrag=INT_MAX;
    int minindex=-1;
    for(j=0;j<memblks;j++){
      if(memory[j].pid==-1 && processes[i].size<=memory[j].blksize){
        int int_frag=memory[j].blksize-processes[i].size;
        if(min_intfrag>int_frag){
        minindex=j;
        min_intfrag=int_frag;
        }
      } 
    if(minindex!=-1)
      memory[minindex].pid=processes[i].pid;
      tottal_int_frag+=min_intfrag;
    }
  }
    printf("Internal frag= %d",tottal_int_frag);
} 
void main(){
  int no_of_process,no_of_blocks,i;
  printf("Enter the number of blocks:");
  scanf("%d",&no_of_blocks);
  memblk *memory=(memblk *)malloc(sizeof(memblk)*no_of_blocks);
  for(i=0;i<no_of_blocks;i++){
    scanf("%d",&memory[i].blksize);
    memory[i].pid=-1;
  }
  printf("Enter the procssnum: ");
  scanf("%d",&no_of_process);
  process *processes=(process *)malloc(sizeof(process)*no_of_process);
  for(i=0;i<no_of_process;i++){
      scanf("%d",&processes[i].size); 
      processes[i].pid=i+1;
  }
  printf("Best Fit\n");
  int sum=0;
  best_fit(memory,no_of_blocks,processes,no_of_process);
  for(i=0;i<no_of_blocks;i++){
    int num=(memory[i].pid==-1)?-1:processes[memory[i].pid-1].size;
    sum+=(num==-1)?0:memory[i].blksize-processes[memory[i].pid-1].size;
    printf("\nMemorysize: %d pid: %d pidsize: %d",memory[i].blksize,memory[i].pid,num);
  }
  printf("\nInternal Frag: %d",sum);
}