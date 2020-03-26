#include<stdio.h>
struct node
{
    int row;
    int col;
    int value;
};
struct node a[10],b[10],c[10];
int n,m,nz,i,j,k;
void add()
{
        c[0].row=m;
        c[0].col=n;
    i=1;j=1;k=1;
    while(i<=a[0].value && j<=b[0].value)
    {
        if(a[i].row ==b[j].row && a[i].col == b[j].col)
        {
            c[k].row=a[i].row;
            c[k].col=a[i].col;
            c[k].value=a[i].value+b[j].value;
            i++;j++;k++;
        }
        else
        {
            if(a[i].row<b[j].row)
            {
                c[k].row=a[i].row;
                c[k].col=a[i].col;
                c[k].value=a[i].value;
                i++;k++;
            }
            else if(a[i].row>b[j].row)
            {
            c[k].row=b[j].row;
            c[k].col=b[j].col;
            c[k].value=b[j].value;
            j++;k++;
            }
            else
            {
                if(a[i].col>b[j].col)
                {
                c[k].row=b[j].row;
                c[k].col=b[j].col;
                c[k].value=b[j].value;
                j++;k++;
                }
                else
                {
                c[k].row=a[i].row;
                c[k].col=a[i].col;
                c[k].value=a[i].value;
                i++;k++;
                }
            }
        }
    }
     while(i<=a[0].value)
     {
             c[k].row=a[i].row;
             c[k].col=a[i].col;
             c[k].value=a[i].value;
             i++;k++;
     }
     while(j<=b[0].value)
     {
             c[k].row=a[j].row;
             c[k].col=a[j].col;
             c[k].value=a[j].value;
             j++;k++;
     }
    i=1;
    while(c[i].value)
    {
        printf("%d %d %d\n",c[i].row,c[i].col,c[i].value);
        i++;
    }
}
void main()
{
    printf("enter m,n,nz");
    scanf("%d %d %d",&m,&n,&nz);
    printf("enter elements");
    a[0].row=b[0].row=m;
    a[0].col=b[0].col=n;
    a[0].value=b[0].value=nz;
    for(i=1;i<=nz;i++)
    {
            scanf("%d %d %d",&a[i].row,&a[i].col,&a[i].value);
    }
     for(i=1;i<=nz;i++)
    {
            scanf("%d %d %d",&b[i].row,&b[i].col,&b[i].value);
    }
    add();
    
}