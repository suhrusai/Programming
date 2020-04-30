#include<reg51.h>
#include<stdio.h>
sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;
void lcdcmd(unsigned char);
void lcddat(unsigned char);
void delay();
void printstring(char a[],int len);
void main()
{
	P2=0x00;
	while(1)
	{
	lcdcmd(0x38);
	delay();
	lcdcmd(0x01);
	delay();
	lcdcmd(0x10);
	delay();
	lcdcmd(0x0c);
	delay();
	lcdcmd(0x81);
	delay();	
	printstring("GOOD NIGHT",10);
	}
}
void printstring(char a[],int len){
	int i;	
	for(i=0;i<len;i++)
		{
			lcddat(a[i]);
			delay();
		}
}
void lcdcmd(unsigned char val)
{
P2=val;
rs=0;
rw=0;
en=1;
delay();
en=0;
}

void lcddat(unsigned char val)
{
P2=val;
rs=1;
rw=0;
en=1;
delay();
en=0;
}

void delay()
{
unsigned int i;
for (i=0;i<12000;i++);
}