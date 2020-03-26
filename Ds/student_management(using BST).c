#include<stdio.h>
#include<stdlib.h>
typedef struct {
char name[30];
long long int roll;
int marks;
} STUDENT;
int insert(STUDENT a[],int k,int n,STUDENT new)
{
        if(k<1 || k>n)
                return n;
        int i;
        a=(STUDENT *)realloc(a,(n+1)*sizeof(STUDENT));
        for(i=n;i>=k;i--)
        {
                a[i]=a[i-1];
        }
        a[k-1]=new;
        return n+1;
}
int delete(STUDENT a[],int n,int k)
{
        int i;
        for(i=k-1;i<n-1;i++)
        {
                a[i]=a[i+1];
        }
        a=(STUDENT *)realloc(a,(n-1)*sizeof(STUDENT));
        n--;
        return n;

}
int main(void)
{
        int n,i,k;
        STUDENT b;
        printf("Enter the number of students:");
        scanf("%d",&n);
        STUDENT *a=malloc(n*sizeof(STUDENT));
        for(i=0;i<n;i++)
        {
                printf("Enter name: ");
                scanf(" %s",a[i].name);
                printf("Enter roll number: ");
                scanf("%lld",&a[i].roll);
                printf("Enter marks: ");
                scanf("%d",&a[i].marks);

        }
        printf("Enter the details of the student to be addded:\n");
        printf("Enter name: ");
         scanf(" %s",b.name);
         printf("Enter roll number: ");
         scanf("%lld",&b.roll);
         printf("Enter marks: ");
         scanf("%d",&b.marks);
        printf("Enter the location to be inseeted at:");
        scanf("%d",&k);
        n=insert(a,k,n,b);
        for(i=0;i<n;i++)
        {
        printf(" %-30s",a[i].name);
        printf("%012lld",a[i].roll);
        printf("  %03d\n",a[i].marks);

        }
        // printf("Enter the location to be deleted at:");
        // scanf("%d",&k);
        for(i=0;i<n;i++)
        {
                if(a[i].marks<35)
                {
                        n=delete(a,n,i+1);
                        i--;
                }
        }
        printf("After removal\n");
        for(i=0;i<n;i++)
        {
        printf(" %-30s",a[i].name);
        printf("%012lld",a[i].roll);
        printf("  %03d\n",a[i].marks);

        }
        printf("Enter the element number to be displayed: ");
        scanf("%d",&i);
        printf(" %-30s",a[i-1].name);
        printf("%012lld",a[i-1].roll);
        printf("  %03d\n",a[i-1].marks);
}