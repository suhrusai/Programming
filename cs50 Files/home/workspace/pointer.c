#include<stdio.h>
int main(void)
{
    int ar[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int* a=ar;
    int i;
for(i=0;i<=9;i++)
{ 
        printf("%d  ",*(a+i));
    }
}

        
