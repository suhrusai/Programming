#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#ifdef __linux__
#define CLEAR system("clear");
#elif __WIN32
#define CLEAR system("cls");
#else
#define CLEAR system("clear");
#endif
typedef struct {
	int d;
	int m;
	int y;
} DATE_USER;
DATE_USER today;
typedef struct {
char name[100];
char publisher_name[100];
long long int code;
int cost;
char issuestatuts;
long long int roll;
DATE_USER issue_date;
DATE_USER return_date;
} BOOK;
void lost_book_fine(void);
void check_issue(void);
void add_book(void);
void issue_books(void);
void del_book(void);
void display_books(void);
void retrun_book(void);
DATE_USER retrun_date(DATE_USER issue_date,int n);
int days_calculator(DATE_USER date);
void lost_book_fine(void)
{
	CLEAR
	printf("\t\t\t\t\tLibrary management software\n");
	printf("--------------------------------------------------------------------------------------------------------------\n");
	FILE *ptr=fopen("booklog.txt","r");
	FILE *nptr=fopen("booklogtemp.txt","a+");
	long long int bookcode;
	bool check=0;
	int fine;
	BOOK book1;
	label:
	printf("Enter bookcode: ");
	scanf("%lld",&bookcode);
	while(fread(&book1,sizeof(BOOK),1,ptr))
	{
			if(book1.code==bookcode)
			{
				check=1;
				fine=book1.cost*2;
			}
			else
			{
				fwrite(&book1,sizeof(BOOK),1,nptr);
			}
	}
	fclose(nptr);
	fclose(ptr);
	if(check!=1)
	{
		printf("Book not present\n");
		system("erase booklogtemp.txt");
		printf("\n\n Press any key to continue...");
	}

	else
	{
		printf("Fine to be paid is Rs.%d (i.e twice the cost of the book)\n",fine);
    	remove("booklog.txt");
		rename("booklogtemp.txt","booklog.txt");
		printf("Book with code %lld removed succesfully",bookcode);
		printf("\n\a\n Press any key to continue...");
    }
}
int days_calculator(DATE_USER date)
{
    int arr[13]={31,28,31,30,31,30,31,31,30,31,30,31,29};
    int count=0;
	DATE_USER date1;
	date1=today;

    while(date.d!=date1.d || date.m!=date1.m || date.y!=date1.y)
    {
		int days;date.d++;
        int arr[13]={31,28,31,30,31,30,31,31,30,31,30,31,29};
		if(date.m==2 && ( (date.y%100==0 && date.y%400==0) || (date.y%100!=0 && date.y%4==0)))
		{
			days=arr[13];
		}
		else
			days=arr[date.m];
		if(date.d>days)
		{
			date.d=1;
			date.m++;
		}
		if(date.m>12)
		{
			date.m=1;
			date.y++;
		}
		count++;
	}
	return count;
}
DATE_USER retrun_date(DATE_USER date,int n)
{
    int i;
	int arr[13]={31,28,31,30,31,30,31,31,30,31,30,31,29};
	for(i=1;i<n;i++)
	{
		int days;
		if(date.m==2 && ( (date.y%100==0 && date.y%400==0) || (date.y%100!=0 && date.y%4==0)))
		{
			days=arr[13];
		}
		else
			days=arr[date.m];
			date.d++;
		if(date.d>days)
		{
			date.d=1;
			date.m++;
		}
		if(date.m>12)
		{
			date.m=1;
			date.y++;
		}
	}
    return date;
}
void return_book()
{
	CLEAR
	FILE *ptr=fopen("booklog.txt","a+");
	FILE *nptr=fopen("booklogtemp.txt","a");
	BOOK book1;
	long long int roll,bookcode;
	char opt;
	printf("\t\t\t\t\tLibrary management software\n");
	printf("--------------------------------------------------------------------------------------------------------------\n");
	printf("Enter bookcode: ");
	scanf("%lld",&bookcode);
	printf("Enter roll number: ");
	scanf("%lld",&roll);
	while(fread(&book1,sizeof(BOOK),1,ptr))
	{
		if(book1.code==bookcode)
			break;
		fwrite(&book1,sizeof(BOOK),1,nptr);
	}

    if(book1.issuestatuts=='Y')
	{
            printf("Taken by %lld\n",book1.roll);
           if(book1.roll==roll)
	    {

			if((book1.return_date.y>today.y)||(book1.return_date.y==today.y && book1.return_date.m>today.m)||(book1.return_date.y==today.y && book1.return_date.m==today.m && book1.return_date.d>=today.d))
				{
					printf("Return process done");

				}
			else
			{
				int days=days_calculator(book1.return_date);
				printf("Delayed by %d days\nFine to be paid: Rs.%d\nFine Rs.1 per day\n",days,days);
			}
			book1.issuestatuts=0;
			book1.roll=0;

	    }
	    else if(book1.roll!=roll)
		    printf("\n\a\aWrong person");
	    fwrite(&book1,sizeof(BOOK),1,nptr);
		while(fread(&book1,sizeof(BOOK),1,ptr))
		{
			fwrite(&book1,sizeof(BOOK),1,nptr);
		}
        fclose(ptr);
		fclose(nptr);
        remove("booklog.txt");
		rename("booklogtemp.txt","booklog.txt");
    }
	else
    {
		fclose(nptr);
		fclose(ptr);
		remove("booklogtemp.txt");
	}
	printf("\n\n\n\a Press any key to continue...\n");
}

void display_books(void)
{
	CLEAR
	FILE *ptr=fopen("booklog.txt","r");
	BOOK book1;
	char opt;
	printf("\t\t\t\t\tLibrary management software\n");
	printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|Book name                               |Publisher name                          |Issued|Bookcode    |Roll Number |Return Date|\n");
	printf("|------------------------------------------------------------------------------------------------------------------------------|\n");
    while(fread(&book1,sizeof(BOOK),1,ptr))
		{
			printf("|%40s|%40s|     %c|%12lld|%12lld|",book1.name,book1.publisher_name,book1.issuestatuts,book1.code,book1.roll);
			if(book1.issuestatuts=='Y')
				printf("%02d/%02d/%04d |\n",book1.return_date.d,book1.return_date.m,book1.return_date.y);
	else
	printf("           |\n");
	printf("|------------------------------------------------------------------------------------------------------------------------------|\n");
		}
fclose(ptr);
printf("\n\a\nPress any key to continue...");

}
void menu()
{
	char opt;
	//wait();
	CLEAR
	printf("\t\t\t\t\tLibrary management software\n");
	printf("--------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t1.Add books\n");
	printf("\t\t\t\t\t2.Delete Books\n");
	printf("\t\t\t\t\t3.Issue Books\n");
	printf("\t\t\t\t\t4.Check issued books\n");
	printf("\t\t\t\t\t5.Display books\n");
	printf("\t\t\t\t\t6.Book Return\n");
	printf("\t\t\t\t\t7.Lost book fine\n");
	printf("\t\t\t\t\tPress E to exit\n");
	printf("--------------------------------------------------------------------------------------------------------------\n");
	printf("select an option: ");
	scanf("  %c",&opt);
	switch(opt)
	{
		case '1':add_book();break;
		case '2':del_book();break;
		case '3':issue_books();break;
		case '4':check_issue();break;
		case '5':display_books();break;
		case '6':return_book();break;
		case '7':lost_book_fine();break;
		case 'E':exit(1);break;
		case 'e':exit(1);break;
		default :printf("\a\a");
	}
}
void add_book()
{
	label2:
	CLEAR
	FILE *ptr=fopen("booklog.txt","a+");
	if(ptr==NULL)
	{
		printf("NULL\n\n\n\n");
	}
	BOOK book1,temp;
	char opt;
	printf("\t\t\t\t\tLibrary management software\n");
	printf("--------------------------------------------------------------------------------------------------------------\n");
	printf("Enter the BOOK details below\n");
	printf("Book name: ");
	scanf(" %[^\n]s",book1.name);
	printf("Book publisher: ");
	scanf(" %[^\n]s",book1.publisher_name);
	label:
	printf("Book code: ");
	scanf("%lld",&(book1.code));
	while(fread(&temp,sizeof(temp),1,ptr))
	{
		if(temp.code==book1.code)
			{
				printf("\nBook code already present\n\n\a");
				rewind(ptr);
				goto label;
			}
	}

	printf("Book Cost: ");
	scanf("%d",&(book1.cost));
	book1.issuestatuts=0;
	book1.roll=0;
	printf("\n Entered details\nBook name: %s\nBook Publisher Name:%s\nBook code: %lld\nBook cost: %d",book1.name,book1.publisher_name,book1.code,book1.cost);
	fwrite(&book1,sizeof(BOOK),1,ptr);
	label1:
	printf("\a\nDo you want to add another BOOK(Y/N): ");
	scanf(" %c",&opt);
	fclose(ptr);
	switch(opt)
	{
		case 'Y':add_book();break;
		case 'y':add_book();break;
		case 'n':break;
		case 'N':break;
		default :printf("\nIncorrect option");goto label1;break;
	}
	printf("\n\a\n Press any key to continue...");

}
void del_book()
{

	CLEAR
	printf("\t\t\t\t\tLibrary management software\n");
	printf("--------------------------------------------------------------------------------------------------------------\n");
	FILE *ptr=fopen("booklog.txt","r");
	FILE *nptr=fopen("booklogtemp.txt","a+");
	long long int bookcode;
	int check=0;
	BOOK book1;
	label:
	printf("Enter bookcode: ");
	scanf("%lld",&bookcode);
	while(fread(&book1,sizeof(BOOK),1,ptr))
	{
			if(book1.code==bookcode)
			{
				check=1;
			}
			else
			{
				fwrite(&book1,sizeof(BOOK),1,nptr);
			}
	}
	fclose(nptr);
	fclose(ptr);
	if(check!=1)
	{
		printf("Book not present\n");
		system("erase booklogtemp.txt");
		printf("\n\a\n Press any key to continue...");
	}

	else
	{
    	remove("booklog.txt");
		rename("booklogtemp.txt","booklog.txt");
		printf("Book with code %lld removed succesfully",bookcode);
		printf("\n\a\n Press any key to continue...");
    }


}
void issue_books()
{
	CLEAR
	FILE *ptr=fopen("booklog.txt","r");
	FILE *nptr=fopen("booklogtemp.txt","a");
	BOOK book1;
	long long int roll,bookcode;
	char opt;
	bool checker=0;
	printf("\t\t\t\t\tLibrary management software\n");
	printf("--------------------------------------------------------------------------------------------------------------\n");
	printf("Enter Roll number: ");
	scanf("%lld",&roll);
	printf("Enter bookcode: ");
	scanf("%lld",&bookcode);
	while(fread(&book1,sizeof(BOOK),1,ptr))
	{
		if(book1.code==bookcode && book1.issuestatuts==0)
		{
			int n;
			printf("\a\aNumber of days to be issued for(inclusive of today): ");
			scanf("%d",&n);
			book1.issue_date=today;
			book1.return_date=retrun_date(today,n);
			printf("\n\aIt is Present and issueing process done");
			book1.roll=roll;
			book1.issuestatuts='Y';
			checker=1;
			break;
		}

		else if (book1.issuestatuts=='Y' && book1.code==bookcode)
		{
			printf("\n\aBook is already issued\n");
			checker=1;
		}
		else
		{
			fwrite(&book1,sizeof(BOOK),1,nptr);
		}
	}
	if(!(checker))
		{
			printf("\n\aBook not present");
			goto end;
		}
	fwrite(&book1,sizeof(BOOK),1,nptr);
	while(fread(&book1,sizeof(BOOK),1,ptr))
	{
		fwrite(&book1,sizeof(BOOK),1,nptr);
	}
	end:
	fclose(nptr);
	fclose(ptr);
	remove("booklog.txt");
	rename("booklogtemp.txt","booklog.txt");
	printf("\n\a\nPress any key to continue...");
}
void check_issue()
{
	CLEAR
	FILE *ptr=fopen("booklog.txt","a+");
	BOOK book1;
	printf("\t\t\t\t\tLibrary management system\n");
	printf("------------------------------------------------------------------------------------------------------------------------------------\n|Book name                               |Publsiher name                                |Roll number        |Issue Date|Return Date|\n");
	printf("------------------------------------------------------------------------------------------------------------------------------------\n");
		while(fread(&book1,sizeof(BOOK),1,ptr))
	{
		if(book1.issuestatuts=='Y')
		{
			printf("|%40s|\t%40s|\t%12lld|%02d/%02d/%04d|%02d/%02d/%04d |\n",book1.name,book1.publisher_name,book1.roll,book1.issue_date.d,book1.issue_date.m,book1.issue_date.y,book1.return_date.d,book1.return_date.m,book1.return_date.y);
	printf("------------------------------------------------------------------------------------------------------------------------------------\n");
		}
	}
	printf("\n\a\nPress Any key to continue...");
	fclose(ptr);

}
int main(void)
{
	printf("Enter Current date(dd/mm/yyyy): ");
	scanf("%d/%d/%d",&today.d,&today.m,&today.y);
	getchar();
	while(1)
	{
	getchar();
	menu();
	getchar();
	getchar();
	}
return 0;
}
