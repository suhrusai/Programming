#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//#include<conio.h>
 int main(void)
 {
     FILE *ptr=fopen("file1.txt","r");
     char ch=fgetc(ptr);
	while(ch!=EOF)
	{
		printf("%c",ch);
		ch=fgetc(ptr);
		
	}
	fclose(ptr);
	FILE *ptr2=fopen("file2.txt","w");
	FILE *ptr1=fopen("file1.txt","r");
	ch=fgetc(ptr1);
		while(ch!=EOF)
	{
		putc(ch,ptr2);
		ch=fgetc(ptr1);
	}
	
}