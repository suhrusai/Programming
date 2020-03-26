#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<stdio.h>
/*
 *@suhru
*/
char temp[100];
void convert(char *s){
    
    int i,k=1;
    char prev;
    temp[0]=s[0];
    for(i=1;s[i];i++){
        if((s[i-1]=='*' ||s[i-1]=='/' )&&(s[i]=='*' || s[i]=='/'))
        {
               temp[k++]=s[i+1]-'a'+'A'; 
               i++;
        }
        else if(s[i]=='*' || s[i]=='/'){
            temp[k++]=' ';
        }

        else{
            temp[k++]=s[i];
        }
    }
    s[k]=0;
}
int main(void){
    char s[100];
    scanf(" %[^\n]s",s);
    convert(s);
    printf("\n%s",temp);
}