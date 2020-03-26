#include<stdio.h>
#include<math.h>
void greet()
{
    printf("|   |  |------  |       |      |-----|\n");
    printf("|   |  |        |       |      |     |\n");
    printf("|---|  |------  |       |      |     |\n");
    printf("|   |  |        |       |      |     |\n");
    printf("|   |  |------  |______ |_____ |-----| \n\n\n");
    printf("|   |  |------  |------ |----|\n");
    printf("|   |  |        |       |    |\n");
    printf("|   |  |------  |------ |----|\n");
    printf("|   |        |  |       |\\     \n");
    printf("|---|   -----|  |------ | \\    \n");
}
void numbertobinary()
{
    long long int no,bin=0,a,i=1;
    label:
    bin=0;i=1;
    printf("Enter number\n");
    scanf("%lld",&no);
    if((no>0)&&(no!=999))
    {
        printf("The binary no is:\n");

    while(no!=0)
    {
        a=no%2;
        no/=2;
        bin+=(a*i);
        i*=10;
    }
    printf("%lld",bin);
    printf("\n");
    goto label;
    }
    else if(no==999)
    {
        printf("end of the program");
    }

}


void grade()
{
     int m1,m2,m3,m4,m5,per,tot=0;

printf("enter score in subject 1 on scale of 100:        ");
scanf("%d",&m1);
printf("enter the marks in subject 2 on scale of 100:    ");
scanf("%d",&m2);
printf("enter the score in subject 3 on a scale of 100:  ");
scanf("%d",&m3);
printf("enter the score in subject 4 on a scale of 100:  ");
scanf("%d",&m4);
printf("enter the socre in subject 5 on a scale of 100:   ");
scanf("%d",&m5);
tot = m1+m2+m3+m4+m5 ;
per = tot/5;
printf("your percentage is %d \n total is %d \n",per,tot);
if(per>=90)
{
printf("Grade:A1");
}

else if(per>=80)
{
    printf("Grade:A2");

}
    else if (per>=70)
    {
        printf("Grade:B1");
    }
    else if (per>=60)
    {
        printf("Grade:B2");
    }
    else if(per>= 50)
    {
        printf("Grade:C1");
    }
    else if(per>=40)
    {
    printf("Grade:C2");
    }
    else if (per<40)
    {
        printf("FAIL!!!!!");
    }
    printf("\n\n");
}
void ascii()
{
    char c;
    printf("Enter a character: ");
    scanf("%c", &c);

    // %d displays the int
    printf("ASCII value of %c = %d", c, c);
}
void start()
{
    printf("\n give the application number to open\n1-bill generator\n2-sinx evaluator\n");
    printf("3-sum of digits calculator\n4-Quadratic eqn solver\n5-grade calculator\n6-India map\n7-ASCII Value");
    printf("0-Shutdown\n\n\n");


}
void sumofdigits()
{
    int num,t,l,sum;
    sum=0;

    printf("Enter a number:");
    scanf("%d",&num);
    t=num;
    while(t>0)
    {
        l=t%10;
        sum=sum+l;
        t=t/10;
    }
    printf("\nSum=%d\n",sum);

}
void root()
{
    int a,b,c;
    float d,x,x1;
    printf("Enter value of a,b,c in ax^2+bx+c=0");
    scanf("%d %d %d",&a,&b,&c);
    d=(b*b)-(4*a*c);
    if(d<0)
    {
        printf("\nNo real roots");
    }
    else if(a==0)
    {
        printf("\nx=%f",-(float)c/b);
    }

    else if(d==0)
    {
        printf("\n Both roots are equal to %f",(-(float)b/(2*a)));
    }
    else
    {
        x=(-b+sqrt(d))/2*a;
        x1=(-b-sqrt(d))/2*a;
        printf("\n x1=%f\n x2=%f\n",x,x1);

    }
}
void quiz()
{
    int a,b,c;
    int count = 1;
    for (b=c=10;a="- FIGURE?, UMKC,XYZHello Folks,\
    TFy!QJu ROo TNn(ROo)SLq SLq ULo+\
    UHs UJq TNn*RPn/QPbEWS_JSWQAIJO^\
    NBELPeHBFHT}TnALVlBLOFAkHFOuFETp\
    HCStHAUFAgcEAelclcn^r^r\\tZvYxXy\
    T|S~Pn SPm SOn TNn ULo0ULo#ULo-W\
    Hq!WFs XDt!" [b+++21]; )
    for(; a-- > 64 ; )
    putchar ( ++c=='Z' ? c = c/ 9:33^b&1);
}
void sinx()
{

  int i, j, n, fact, sign =  - 1;
  float x, p, sum = 0;


  printf("Enter the value of x(in degrees) : ");
  scanf("%f", &x);
  x=(x*3.1415914159/180);
  printf("Enter the value of n : ");
  scanf("%d", &n);

  for (i = 1; i <= n; i += 2)
  {
    p = 1;
    fact = 1;
    for (j = 1; j <= i; j++)
    {
      p = p * x;
      fact = fact * j;
    }
    sign =  - 1 * sign;
    sum += sign * p / fact;
  }

  printf("sin %0.2f = %f\n", x*180/3.1415914159, sum);
}
void pill()
{
    int qty1,qty2,qty3,p1,p2,p3;
    float tax,total,taxval,subtot;
    printf("Enter the quantity of TV");
    scanf("%d",&qty1);
    printf("Enter the quantity of VCR");
    scanf("%d",&qty2);
    printf("Enter the quantity of CD player");
    scanf("%d",&qty3);
    p1=qty1*8000;
    p2=qty2*9000;
    p3=qty3*11500;

        printf("                          WALMART\n");
        printf("                         Hyderabad\n");
        printf("                           India  \n");
        printf("-----------------------------------------------------\n");

        printf("Qty |\tItem     |\tUnit price|\tTotal Price\n");
if(qty1>0)
{
        printf("%02d  |\tTV       |\t8000.00   |\t%d\n",qty1,p1);
}
if (qty2>0)
{

        printf("%02d  |\tVCR      |\t9000.00   |\t%d\n",qty2,p2);
}
if (qty3>0)
{

        printf("%02d  |\tCD Player|\t11500.00  |\t%d\n",qty3,p3);

}
 printf("-----------------------------------------------------\n");
 tax=8.5;
 subtot=p1+p2+p3;
 taxval=(p1+p2+p3)*tax/100;
        printf("\t\t\t\tSubtotal =%8.2f\n",subtot);
        printf("\t\t\t\tTax[8.5\%]=%8.2f\n",taxval);
        printf("-----------------------------------------------------\n");
        total=subtot+taxval;
        printf("\t\t\t\tTotal    =%8.2f\n",total);
        printf("-----------------------------------------------------\n");
        printf("      Thanks for visiting please visit again\n");
}

int main(void)
{
    int option;
    do
    {

    greet();
    start();
    scanf("%d",&option);
    printf("\v");
    if(option==1)
    {
        printf("\n Bill generator\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        pill();
        printf("\n\n");

    }
    else if(option==2)
    {
        printf("\nSinx calculator\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        sinx();
        printf("\n\n");

    }
    else if(option==3)
    {
        printf("\nSum of digits calculator\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        sumofdigits();
        printf("\n\n");

    }
    else if(option==4)
    {
        printf("\nQuadratic equation solver\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        root();
        printf("\n\n");
    }
    else if(option==5)
    {
        printf("\nGrade calculator\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        grade();
        printf("\n\n");
    }
    else if(option==6)
    {
        printf("\nIndia map\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        quiz();
        printf("\n\n");
    }
    else if (option==0)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nSHUTTING DOWN!!!");

    }
    else if(option==7)
    {
        printf("\nASCII VALUE \n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        ascii();
        printf("\n\n");
    }
    else if(option==8)
    {
        printf("\nDecimal to binary \n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        numbertobinary();
        printf(\n\n);
    }

}while(option!=0);
}