#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int G[MAX][MAX],n,visited[MAX],count1=0;
void create(){
        int j,i;
        printf("Enter the numer of locations: ");
        scanf("%d",&n);
        printf("Enter the adjacency matrix");
        for (i=0;i<n;i++)
                for(j=0;j<n;j++)
                        scanf("%d",&G[i][j]);
        for(i=0;i<MAX;i++)
                G[i][i]=0;
        for (i=0;i<n;i++){
        for(j=0;j<n;j++)
                printf("%d ",G[i][j]);
        printf("\n");
        }

}
int DFS(int v){
        int j;
        //printf(" %d ",v);
        count1++;
        visited[v]=1;
        for(j=0;j<n;j++)
                if(!visited[j]  && G[v][j])
                        DFS(j);
        return count1;
}
int connection_check(int loc)
{
        int i,count=0;
        printf("Connections to %d are: ",loc);
        for(i=0;i<n;i++)
        {
                if(G[loc][i]){
                        count++;
                        printf(" %d",i);
                }
        }
        return count;
}
void main(){
        int i;
        create();
        printf("Enter the node to be searched: ");
        scanf("%d",&i);
        connection_check(i);
//      printf("DFS VALUE: %d",DFS(0));
        printf("\n");
        count1=0;
        if(DFS(0)==n)
                printf("\nThe graph is connected");
        else
                printf("\nGraph is not connected ");
}

