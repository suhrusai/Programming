#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void fifo(int pages[],int no_of_pages,int pagetable[],int len_page_table,int current_index){
  pagetable[current_index%len_page_table]=pages[current_index];
  printf("\n");
  int i;
  for(i=0;i<len_page_table;i++)
    printf("%d  ",pagetable[i]);
}
void logic(int pages[],int no_of_pages,int pagetable[],int len_page_table){
    int i,j,pagefault=0,pagereplacement=0;
    for(i=0;i<no_of_pages;i++){
        for(j=0;j<len_page_table;j++){
            int flag=0;
            if(pages[i]==pagetable[j]){
                flag=1;
                break;
            }
        }
        if(j==len_page_table){
            fifo(pages,no_of_pages,pagetable,len_page_table,i);
            pagefault++;
            if(i>len_page_table)
                pagereplacement++;
        }
    }
    printf("\nPage pagefaults: %d page replacements: %d",pagefault,pagereplacement);
}
void main(){
    int no_of_pages,no_of_frames,i;
    printf("Enter the value of n(Length og page replacement string):");
    scanf("%d",&no_of_pages);
    int *pageinfo=(int *)malloc(sizeof(int)*no_of_pages);
    printf("Enter the pages info");
    for(i=0;i<no_of_pages;i++)
        scanf("%d",&pageinfo[i]);
    printf("Enter the No of frames:");
    scanf("%d",&no_of_frames);
    int pagetable=(int *)malloc(sizeof(int)*no_of_frames);
    logic(pageinfo,no_of_pages,pagetable,no_of_frames);
}