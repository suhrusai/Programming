#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct {
	char name[100];
	char publisher_name[100];
	long long int code;
	int cost;
	char issuestatuts;
	long long int roll;

} book;
int booknum=0;
void check_issue(void);//done
void add_book(void);//done
void issue_books(void);//done
void del_book(void);//done
void display_books(void);//done
void retrun_book(void);//doing
void book_search(void);
void book_search_name();
void book_search_publisher();
void book_search_code();
void wait()
{
	printf("\n\n Enter any key to continue");
	scanf(" ");
	getchar();
}
int string_break(char p[200],char broken_p[200][200]);
int string_break(char p[200],char broken_p[200][200])
{
	/*int i=0,j=0,k=0;
	for(i=0;i<200;i++)
	{
		printf("1\n");
		if(p[i]==' '||p[i]=='\0')
		{
			broken_p[k][j]='\0';
			k++;
			j=0;
		}
		else
		{
			broken_p[k][j]=p[i];
			j++;
		}
	}*/
}
void book_search_publisher()
{

}
void book_search_code()
{
}
void book_search_name()
{
	book book1;
	int i=0,j=0,k=0;
	char p[200],broken_p[200][200];
	FILE *ptr=fopen("booklog.txt","r");
	printf("Enter book name: ");
	scanf(" %[^n]s",p);
	/*scanf(" ");
	gets(p); */
	/*for(i=0;i<200;i++)
	{
		while(fread(&book1,sizeof(book),1,ptr))
			if(strstr(break_string[i],book1.name)==0)
				printf("%-20s\t%-20s\t%lld",book1.name,book1.publisher_name,book1.roll);
	}*/

	for(i=0;i<=strlen(p);i++)
	{
		if(p[i]=='\n')
		{

		}
		else if(p[i]==' '||p[i]=='\0')
		{
			broken_p[k][j]='\0';
			k++;
			j=0;
		}
		else
		{
			broken_p[k][j]=p[i];
			j++;
		}

	}

	for(i=0;i<k;i++)
	{
		printf("%s\n",broken_p[i]);
		while(fread(&book1,sizeof(book),1,ptr))
		{
			if(strstr(broken_p[i],book1.name))
			{
				printf("found\n");
				printf("%-20s\t%-20s\t%lld\n",book1.name,book1.publisher_name,book1.roll);
			}
		}
		rewind(ptr);
	}
	wait();
}
void book_search(void)
{
	int opt;
	printf("Select search category:\n");
	printf("1.Name\n");
	printf("2.Publisher Name\n");
	printf("3.Book Code\n");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:book_search_name();
		case 2:book_search_publisher();
		case 3:book_search_code();
	}
}
void return_book()
{
	system("clear");
	FILE *ptr=fopen("booklog.txt","a+");
	FILE *nptr=fopen("booklogtemp.txt","a");
	book book1;
	long long int roll,bookcode;
	char opt;
	printf("\t\t\t\t\tLibrary management software\n");
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("Enter bookcode: ");
	scanf("%lld",&bookcode);
	printf("Enter roll number: ");
	scanf("%lld",&roll);
	while(fread(&book1,sizeof(book),1,ptr))
	{
		if(book1.code==bookcode)
		{
			printf("Taken by %lld\n",book1.roll);
			break;
		}
		fwrite(&book1,sizeof(book),1,nptr);
	}
	if(book1.roll==roll)
	{
		printf("Return process done");
		book1.roll=0;
		book1.issuestatuts=0;
	}
	if(book1.roll!=roll)
	printf("Wrong person");
		fwrite(&book1,sizeof(book),1,nptr);

		while(fread(&book1,sizeof(book),1,ptr))
		{
			fwrite(&book1,sizeof(book),1,nptr);
		}
		system("mv booklogtemp.txt booklog.txt");
	wait();
}

void display_books(void)
{
	system("clear");
	FILE *ptr=fopen("booklog.txt","r");
	book book1;
	char opt;
	printf("\t\t\t\t\tLibrary management software\n");
	printf("---------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("Book name                      |Publisher name                 |\n");
	while(fread(&book1,sizeof(book),1,ptr))
		printf("%-30s\t%-30s\t%c\t%4d%12lld\n",book1.name,book1.publisher_name,book1.issuestatuts,book1.cost,book1.roll);
	wait();

}
void menu()
{
	char opt;
	system("clear");
	printf("\t\t\t\t\tLibrary management software\n");
	printf("---------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t1.Add books\n");
	printf("\t\t\t\t\t2.Delete Books\n");
	printf("\t\t\t\t\t3.Issue Books\n");
	printf("\t\t\t\t\t4.check issued books\n");
	printf("\t\t\t\t\t5.display books\n");
	printf("\t\t\t\t\t6.Book Return\n");
	printf("\t\t\t\t\t7.Search for a book\n");
	printf("\t\t\t\t\tPress E to exit\n");
	printf("---------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("select an option: ");
	scanf("%c",&opt);
	switch(opt)
	{
		case '1':add_book();break;
		case '2':del_book();break;
		case '3':issue_books();break;
		case '4':check_issue();break;
		case '5':display_books();break;
		case '6':return_book();break;
		case '7':book_search();break;
		case 'E':exit(1);break;
		case 'e':exit(1);break;
	}
}
void add_book()
{
	system("clear");
	FILE *ptr=fopen("booklog.txt","a");
	book book1;
	char opt;
	printf("\t\t\t\t\tLibrary management software\n");
	printf("---------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("Enter the book details below\n");
	printf("Book name: ");
	scanf("\n %[^\n]s",book1.name);
	puts(book1.name);
	printf("\nBook publisher: ");
	scanf("\n %[^\n]s",book1.publisher_name);
	//gets(book1.publisher_name);
	puts(book1.publisher_name);
	printf("\nBook code: ");
	scanf("%lld",&(book1.code));
	printf("\nBook Cost: ");
	scanf("%d",&(book1.cost));
	book1.issuestatuts=0;
	book1.roll=0;
	fwrite(&book1,sizeof(book),1,ptr);
	booknum++;
	printf("\nDo you want to add another book(Y/N): ");
	scanf(" %c",&opt);
	switch(opt)
	{
		case 'Y':add_book();break;
		case 'y':add_book();break;
	}


}
void del_book()
{
	system("clear");
	FILE *ptr=fopen("booklog.txt","r");
	FILE *nptr=fopen("booklogtemp.txt","w");
	long long int bookcode;
	int check=0;
	book book1;
	label:
	printf("Enter bookcode: ");
	scanf("%lld",&bookcode);
	while(fread(&book1,sizeof(book),1,ptr))
	{
			if(book1.code==bookcode)
			{
				check=1;
				booknum--;
				break;
			}
			else
			{
				fwrite(&book1,sizeof(book),1,nptr);
			}
	}
	if(check!=1)
	{
		printf("Book not present");
		goto label;
	}
	system("mv booklogtemp.txt booklog.txt");
	wait();
}
void issue_books()
{
	system("clear");
	FILE *ptr=fopen("booklog.txt","a+");
	FILE *nptr=fopen("booklogtemp.txt","a");
	book book1;
	long long int roll,bookcode;
	char opt;
	printf("\t\t\t\t\tLibrary management software\n");
	printf("---------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("Enter Roll number: ");
	scanf("%lld",&roll);
	printf("Enter bookcode: ");
	scanf("%lld",&bookcode);
	while(fread(&book1,sizeof(book),1,ptr))
	{
		if(book1.code==bookcode)
		{
		printf("\nPresent");
		break;
		}
		fwrite(&book1,sizeof(book),1,nptr);
	}
	book1.roll=roll;
	book1.issuestatuts='Y';
	fwrite(&book1,sizeof(book),1,nptr);
	while(fread(&book1,sizeof(book),1,ptr))
	{
		fwrite(&book1,sizeof(book),1,nptr);
	}
	system("mv booklogtemp.txt booklog.txt");
	wait();
}
void check_issue()
{
	FILE *ptr=fopen("booklog.txt","a+");
	book book1;
		while(fread(&book1,sizeof(book),1,ptr))
	{
		if(book1.issuestatuts=='Y')
			printf("%30s\t%30s\t%10lld\n",book1.name,book1.publisher_name,book1.roll);
	}
	wait();

}
int main(void)
{
while(1)
	menu();
return 0;
}