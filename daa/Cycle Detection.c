#include<stdio.h>
#include<stdlib.h>
#define WHITE 0
#define GREY 1
#define BLACK 2
typedef struct node{
   int vertex;
   struct node *next;
} node;
node *g[50];
int top=0;
void insert(int u,int v){
   node *temp=(node *)malloc(sizeof(node));
   temp->vertex=v;
   temp->next=g[u];
   g[u]=temp;
}
int stack[50];
int visited[50]={0};
void push(int data){
   stack[top++]=data;
}
int pop(){
   return stack[top--];
}
int detectcycleutil(int u){
   visited[u]=GREY;
   node *p=g[u];
   while(p){
       if(visited[p->vertex]==GREY)
           return 1;
       else if(visited[p->vertex]==WHITE){
           if(detectcycleutil(p->vertex))
               return 1;
       p=p->next;
       }
   }
   visited[u]=BLACK;
   return 0;
}
void detectcycle(uint u){
   int i;
   for(i=0;i<u;i++){
       if(visited[i]==WHITE){
           if(detectcycleutil(i)){
               printf("Cycle detected");
               return;
           }
       }
   }
   printf("Cycle not detected");
}

int main(){
  int vertices,edges;
  int u,v;
  int m;
   printf("enter no of vertices and edges");
   scanf("%d %d",&vertices,&edges);

   printf("enter the edges");


   for(int i=0;i<vertices;i++)
      g[i] = NULL;
 
   for(int i =0;i<edges;i++){
       scanf("%d %d",&u,&v);
       insert(u,v);
   }

    detectcycle(vertices);

}