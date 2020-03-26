#include <stdio.h>
main()
{
    char sex,ms;
    int age;
    printf("Enter age: ");
    scanf("%d",&age);
    printf("Enter Sex(M or F): ");
    scanf("%c",&sex);
    printf("Enter Maratial status (M or UM): ");
    scanf("%c",&ms);

    if(ms=='M')
    printf("Driver is insured");
    else
    {
        if (sex=='M')
        {
            if(age>30)
            printf("Driver is insured");
            else
            printf("Driver is not insured");
        }
        else
        {
            if (age>25)
            printf("Driver is insured");
            else
            printf("Driver is not insured");
        }
    }
}
