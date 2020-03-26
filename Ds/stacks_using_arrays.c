#include<stdio.h>
#include<stdlib.h>
int top=0;
int *a=NULL;
void pop(){
    if(top!=0)
    {printf("popped element: %d\n",*(a+top-1));
    top--;}
    //a=(int *)realloc(a,sizeof(int)*(top-1));  
}
void push(int ele){
    a=(int *)realloc(a,sizeof(int)*(top+1));
    a[top++]=ele;
}
int main(void){
    int n,ele;
    printf("Enter the number of elements to be pushed: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        {
            scanf("%d",&ele);
            push(ele);
        }
    printf("Number of times to be popped: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        pop();
    printf("After operations\n");
    for(int i=0;i<top;i++)
    {
        printf("%d ",a[i]);
    }
}