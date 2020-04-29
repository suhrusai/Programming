
#include <reg51.h>								//Define 8051 registers
#include<stdio.h>
      
void DelayMs(unsigned int);						//Delay function

//----------------------------------
//	Main Program
//----------------------------------

void Clockwise (void)
{
	unsigned int i;
	for (i=0;i<1000;i++)
	{
		P1 = 0x01;DelayMs(5); 					//Delay 20msec
		P1 = 0x02;DelayMs(5);
		P1 = 0x04;DelayMs(5);
		P1 = 0x08;DelayMs(5);
	}	
}

void AntiClockwise (void)
{
	unsigned int i;
	for (i=0;i<1000;i++)
	{
		P1 = 0x08;DelayMs(5); 					//Delay 20msec
		P1 = 0x04;DelayMs(5);
		P1 = 0x02;DelayMs(5);
		P1 = 0x01;DelayMs(5);	
	}
}

void main (void)
{
	P1 = 0;										//Initialize Port0

	while(1)									//Loop Forever
	{
		Clockwise ();
		DelayMs (100);
		P1	=	0;
		AntiClockwise ();
		DelayMs (100);
		P1 =  0;
	}
}



//---------------------------------              
//		Delay Function
//---------------------------------
void DelayMs(unsigned int n)
{
unsigned int i,j;
	for(j=0;j<n;j++)
	{
	for(i=0;i<900;i++);
	}
}




	
	
 