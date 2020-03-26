#include<stdio.h>
int main(void)
{
    FILE *ptr=fopen("text1.txt","r");
    int i,chars=0,lines=0,words=0;
    char ch;
    ch=fgetc(ptr);
    while(ch!=EOF)
    {
        if(ch==' ')
            words++;
        if(ch=='\n')
            {
            lines++;
            words++;
            }
        chars++;
        ch=fgetc(ptr);
    }
    if(ch==EOF)
        words++;
    printf("Letters=%d\nWords=%d\nLines=%d",chars-words+1,words,lines+1);

}