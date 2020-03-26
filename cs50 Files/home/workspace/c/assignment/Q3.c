#include<stdio.h>
#include<math.h>

int main(void)
{
    int ddi,mmi,yyyyi,daydiff,monthdiff,yeardiff,yyyyc,mmc,ddc;
    printf("Enter DOB in the format dd/mm/yy");
    scanf("%d/%d/%d",&ddi,&mmi,&yyyyi);
    printf("enter current date in the format dd/mm/yy");
    scanf("%d/%d/%d",&ddc,&mmc,&yyyyc);
    if(ddi<=31 && mmi<=12 && ddc<=31 && mmc<=12 && yyyyc-yyyyi>=0)
    {
        if( ddi> ddc)
        {
                mmc= mmc- 1;
                ddc= ddc + 30;
        }
        if(mmi > mmc)
        {
                yyyyi=yyyyi- 1;
                mmi=mmi + 12;
        }
        daydiff=abs(ddc-ddi);
        monthdiff=abs(mmc-mmi);
        yeardiff=abs(yyyyc-yyyyi);
        if(monthdiff>12)
        {
            monthdiff=monthdiff-12;
            yeardiff=yeardiff+1;
        }
        printf("\n %d year(s),%d month(s),%d day(s)",abs(yeardiff),abs(monthdiff),abs(daydiff));
    }
    else
    {
        printf("\n Enter a valid input next time while running the program ");
    }
}