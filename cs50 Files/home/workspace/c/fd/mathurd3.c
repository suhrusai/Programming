#include<stdio.h>
int main(void)
{
    int i=0;
    char a[5544];
    printf("ENter Letters to find their count");
    do{
    scanf("%c",&a[i]);
    i+=1;
    }
    while(a[i-1]!='0');
    ;printf("NUMBER OF ELEMENTS=%d",((i-1)/2));

}