#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void lru(int pages[],int no_of_pages,int pagetable[],int len_page_table,int current_index){
  int i=0,j;
  int *recently_used=(int *)malloc(sizeof(recently_used)*len_page_table);
  for(i=0;i<len_page_table;i++)
  {
      //Checking the least recent use of a frame in the page table
      for(j=current_index-1;j>-1;j--){
          if(pages[j]==pagetable[i]){
              recently_used[i]=j;
              break;
          }
      }
      if(j==-1)
        recently_used[i]=INT_MIN;
  }
  int min_index,min=INT_MAX;
  for(i=0;i<len_page_table;i++)
  {
      if(min>recently_used[i]){
          min_index=i;
          min=recently_used[i];
      }
  }
  pagetable[min_index]=pages[current_index];
  printf("\n");
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
            lru(pages,no_of_pages,pagetable,len_page_table,i);
            pagefault++;
            if(i>len_page_table)
                pagereplacement++;
        }
    }
    printf("\nPage faults: %d page replacements: %d",pagefault,pagereplacement);
}
void main(){
    int no_of_pages,no_of_frames,i;
    printf("Enter the value of n(Length og page replacement string):");
    scanf("%d",&no_of_pages);
    int *pageinfo=(int *)malloc(sizeof(int)*no_of_pages);
    printf("Enter the pages info:\n");
    for(i=0;i<no_of_pages;i++)
        scanf("%d",&pageinfo[i]);
    printf("Enter the No of frames:");
    scanf("%d",&no_of_frames);
    int pagetable=(int *)malloc(sizeof(int)*no_of_frames);
    logic(pageinfo,no_of_pages,pagetable,no_of_frames);
}