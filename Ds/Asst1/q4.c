#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int user;
    int song;
    int val;
} sparse;
sparse a[101];
int song_k(int k){
    int current_user=0,i,j;
    for(i=1;i<=a[0].val;i++)
            if(a[i].song==k && a[i].val>0)
                current_user++;
    return current_user;
}
void user_k(int k){
    int i,j;
    for(i=1;i<=a[0].val;i++)
            if(a[i].user==k && a[i].val>0)
                printf("song %d \n",a[i].song);
}
int user_k_songcount(int k){
    int i,j,c=0;
    for(i=1;i<=a[0].val;i++)
            if(a[i].user==k && a[i].val>0)
                c++;
    return c;
}
void main()
{
    int song,user,listened,i;
    printf("Enter the number of song and users: ");
    scanf("%d %d",&a[0].song,&a[0].user);
    printf("Number of non zero elements: ");
    scanf("%d",&a[0].val);
    int k=1;
    for(i=1;i<=a[0].val;i++)
    {
        scanf("%d %d %d",&a[i].song,&a[i].user,&a[i].val);
    }
    printf("Which song do you want to know about? ");
    scanf("%d",&k);
    printf("Song %d is listened by %d users\n",k,song_k(k));
    printf("Which user song list you want to know: ");
    scanf("%d",&k);
    printf("Song listened by %d user ",k);
    user_k(k);
    int max=1;
    for(i=2;i<=a[0].song;i++)
    {
        max=song_k(max)>song_k(i)?max:i;
    }
    printf("Maximum  song listened by users is %d",max);
    max=1;
    for(i=2;i<=a[0].user;i++)
    {
        max=user_k_songcount(max)>user_k_songcount(i)?max:i;
    }
    printf("\nMaximum  songs are listened by user %d",max);
}