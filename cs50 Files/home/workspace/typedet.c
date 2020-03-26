#include<stdio.h>
#include<ctype.h>
int main(void)
{
    char a;
    printf("enter a character");//to detect type of character entered
    scanf("%c",&a);
    if(isalpha(a))
    {
        printf("\nalphabet");
    }
    else if(isdigit(a))
    {
        printf("\n digit");
    }
    else if(ispunct(a))
    {
        printf("\n puntuation");
    }
    else if(isspace(a))
    {
        printf("\n space");
    }
    else
    {
        printf("special charecter");
    }
}