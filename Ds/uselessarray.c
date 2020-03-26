#include<stdio.h>
#include<stdlib.h>
int size=10;
void sort(char a[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=i;j<n;j++)
            if(a[i]>a[j])
            {
                char temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
}
int find(char a[], int lo, int hi,char ele) 
{ 
    if (hi >= lo) { 
        int mid = (lo + hi)/ 2; 
        if (a[mid] == ele) 
            {
                printf("%c present at %d",ele,mid+1);
                return 0;
            } 
        if (a[mid] > ele) 
            return find(a, lo, mid - 1,ele); 
        return find(a, mid + 1, hi,ele); 
    } 
    printf("Element not found!!"); 
} 
int insert(int k,char a[],char ele, int n)
{
    int i;
    if((k<=0 && k>=n )|| k==size)
       { printf("Error!");
        return n;}
    for(i=n-1;i>=k-1;i--)
    {
        a[i+1]=a[i];
    }
    a[k-1]=ele;
    return n+1;
}
int delete(int k,char a[],int n)
{
    int i;
    if(k<0 && k>n)
       { printf("Error!");
        return n;}
    for(i=k-1;i<n;i++)
    {
        a[i]=a[i+1];
    }
    return n-1;
}
int main(void)
{
    
    int n,i,k,x;
    char ele;
    
    printf("Enter the size: ");
    scanf("%d",&n);
    char* a=(char *)calloc(size,sizeof(char));
    for(i=0;i<n;i++)
        scanf(" %c",&a[i]);
    printf("Enter the element to be inserted: ");
    scanf(" %c",&ele);
    printf("Enter the location:");
    scanf("%d",&x);
    n=insert(x,a,ele,n);
    printf("\nArray after insertion: ",n);
    for(i=0;i<n;i++)
       printf("%c  ",a[i]);
    printf("\nEnter the location of the element to be deleted: ");
    scanf("%d",&x);
    n=delete(x,a,n);
    printf("\nArray after deletion ");
    for(i=0;i<n;i++)
       printf("%c  ",a[i]);
    printf("\nEnter the index of the element to be displayed: ");
    scanf("%d",&k);
    if(k>0 || k<=n)
        printf("the %dth term is:%c ",k,a[k-1]);
    else
        printf("Error!");
    sort(a,n);
    printf("\nEnter the element to be found: ");
    scanf(" %c",&ele);
    find(a,0,n-1,ele);
    printf("\n");
    printf("Final array\n");
    for(i=0;i<n;i++)
       printf("%c  ",a[i]);
}