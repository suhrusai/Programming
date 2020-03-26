#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define STRING_LENGTH 100
#define NO_OF_WORDS 20
#define WORD_LENGTH 20
typedef struct node{
        char word[WORD_LENGTH];
        int len;
        struct node *next;
} node;
node *first=NULL;
int split(int *a,char *s){
        int i,count=0;
        for(i=0;i<strlen(s);i++)
                if(s[i]==' ')
                {
                        a[count++]=i+1;
                }
return count;
}
void push(char  *ele,int len){
        int i;
        node *temp=(node *)malloc(sizeof(node));
        for(i=0;i<len;i++)
                temp->word[i]=*(ele+i);
        temp->len=len;
        if(!first)
        {
                first=temp;
                temp->next=NULL;
        }
        else{
                temp->next=first;
                first=temp;
        }
}
node* pop(){
        node *temp=first;
        first=first->next;
        return temp;

}
int main(void){
        int a[NO_OF_WORDS],arrlen,i;
        char s[STRING_LENGTH];
        scanf("%[^\n]s",s);
        //printf("Scannning done");
        arrlen=split(a,s);
        //printf("splitting done");
        push(s,a[0]);
        for(i=0;i<arrlen-1;i++){
                //printf("\n%d",a[i+1]-a[i]-1);
                push(&s[a[i]],a[i+1]-a[i]-1);
                //printf("%s",&s[a[i]]);
        }
        push(&s[a[arrlen-1]],strlen(s)-a[arrlen-1]);
        for(i=0;i<(arrlen+1);i++){
                node *p=pop();
                //if(!p){printf("Null \n");}
//      for(i=0;i<p->len;i++)
                        printf("%s ",p->word);
                //      printf("\n");
        free(p);
        }
}


