#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct student{
        char name[20];
        int marks;
        int rollno;
} student;
student *a;
int create(){
        int n,i,rollno;
        printf("Number of students :");
        scanf("%d",&n);
        a=(student *)malloc(n*sizeof(student));
        for(i=0;i<n;i++){
                printf("Roll no:");
                scanf("%d",&a[i].rollno);
                printf("Name:");
                scanf("%s",a[i].name);
                printf("Marks:");
                scanf("%d",&a[i].marks);

        }
        return n;
}
void display(int n){
        int i;
        printf("roll no                 Name marks\n");
       for(i=n-1;i>=0;i--){
"studentinfo.c" printf("%8d",a[i].rollno);
                printf("%20s",a[i].name);
                printf("%8d\n",a[i].marks);
        }

}
void quicksort(int l,int h){
        int i,j;
        student t;
        char key[20];
        if(l<h){
        i=l+1;
        j=h;

        strcpy(key,a[i].name);
        do{
        while(strcmp(a[i].name,key)>0 && i<j)
                i=i+1;
        while(strcmp(a[j].name,key)<0 && i<=j)
                j=j-1;
        if(i<j){
        t=a[i];
        a[i]=a[j];
        a[j]=t;
        }}while(i<j);
        t=a[l];
        a[l]=a[j];
        a[j]=t;
        quicksort(l,j-1);
        quicksort(j+1,h);
        }
}
void main(){
        int n=create();
        display(n);
        quicksort(0,n-1);
        display(n);
}