
#include <reg51.h>
sbit RA = P1^2;
sbit YA	=	P1^1;
sbit GA	=	P1^0;

sbit RB	=	P1^5;
sbit YB	=	P1^4;
sbit GB	=	P1^3;

sbit RC	=	P3^0;
sbit YC	=	P1^7;
sbit GC	=	P1^6;

sbit rD	=	P3^3;
sbit YD	=	P3^2;
sbit GD	=	P3^1;


void Delay (void)
{
	unsigned int i,j;
	for (i=0;i<200;i++)
		for (j=0;j<500;j++);
}

void SuperDelay ()
{
	unsigned int i;
	for (i=0;i<25;i++)
		Delay();
}

void main ()
{
	P3	=	0;

	while (1)
	{
		RA	=	0; 	GA	=	1;	YA	=	0;
		RB	=	1;	GB	=	0;	YB	=	0;
		RC	=	1;	GC	=	0;	YC	=	0;
		rD	=	1;	GD	=	0;	YD	=	0;

		SuperDelay();

		GA	=	0;	YA	=	1;
		Delay();

		RA	=	1; 	GA	=	0;	YA	=	0;
		RB	=	0;	GB	=	1;	YB	=	0;
		RC	=	1;	GC	=	0;	YC	=	0;
		rD	=	1;	GD	=	0;	YD	=	0;

		SuperDelay ();

		GB	=	0;	YB	=	1;
		Delay ();

		RA	=	1; 	GA	=	0;	YA	=	0;
		RB	=	1;	GB	=	0;	YB	=	0;
		RC	=	0;	GC	=	1;	YC	=	0;
		rD	=	1;	GD	=	0;	YD	=	0;

		SuperDelay ();

		GC	=	0;	YC	=	1;
		Delay();

		RA	=	1; 	GA	=	0;	YA	=	0;
		RB	=	1;	GB	=	0;	YB	=	0;
		RC	=	1;	GC	=	0;	YC	=	0;
		rD	=	0;	GD	=	1;	YD	=	0;

		SuperDelay ();

		GD	=	0;	YD	=	1;
		Delay();
		
			
	}
}