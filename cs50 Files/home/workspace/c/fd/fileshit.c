#include<stdio.h>
#include<stdlib.h>
typedef    struct
{
    char name[10];
    int roll;
    float marks;
} student;
int main(void)
{
    FILE *fp=fopen("text1.txt","W");
     student student_1 = {"Tina", 12, 88.123};
    fwrite(&student_1,sizeof(student_1), 1, fp);
}