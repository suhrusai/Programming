import java.util.Scanner;
class Student
{
String Name, Rollno, email; // Student details
long phone;// Student details
Backlogs back; //Class reference to maintain Backlog details
Attendance att;// Class reference to maintain Attendance details
Accounts acc; // Class reference to maintain Account details
Student(String Name,String Rollno,String email,long phone,String backlogs[],int[] year_of_exam,float attendance,float dues[],String department[],int costofexam){
    this.Name=Name;
    this.Rollno=Rollno;
    this.email=email;
    this.phone=phone;
    this.back=new Backlogs(backlogs,year_of_exam);
    this.att=new Attendance(attendance);
    this.acc=new Accounts(dues,department,costofexam);
}
String number_to_word(int n){
    if(n==0)
        return "ZERO";
    if(n==1)
        return "ONE";
    else if(n==2)
        return "TWO";
    else if(n==3)
        return "THREE";
    else if(n==4)
        return "FOUR";
    else if(n==5)
        return "FIVE";
    else 
        return "MORE THAN FIVE";
}
public void display(){
    System.out.print("Hi "+Name+": ");
    String[] backlog=back.listOfBacklogs();
    
    System.out.print("You have "+number_to_word(backlog.length)+" backlogs:");
    for (int i=0;i<backlog.length;i++) {
        if(i!=backlog.length-1)
            System.out.print(backlog[i]+",");
        else
            System.out.println(backlog[i]);
        }
    if(backlog.length==0)
        System.out.println();
    float total_amount=acc.duesTotal();
    float attendance=att.attendance();
    System.out.println("Your attendance % is "+attendance);
    if(attendance<=75 && attendance>=65){
        System.out.println("Your medical condonation is 300");
        total_amount+=300;
        }
    else if(attendance<65){
        System.out.println("You can't write the exam");
        return ;}

    System.out.println("The exam fee is Rs: 1150 for the regular subjects");
    System.out.println("Total amount to be paid Rs: "+total_amount);

}
}
class Backlogs
{
private String backlogs[];// List of subjects having backlogs. Student to be eligible for taking exams of 3-1, shouldn’t have backlogs in First year. Similarly no backlogs in Second year to be eligible for 4-1 exams. Throw exceptions where applicable
private int year_of_exam[];
Backlogs(String[] backlogs,int[] year_of_exam){
    this.backlogs=backlogs;
    this.year_of_exam=year_of_exam;
}
public String[] listOfBacklogs() {
    return backlogs;//Returns list of backlogs
}
}
class Attendance
{
private float attendance;//Overall attendance should be greater than 65%. Throw exceptions where applicable, i.e., when student has attendance between 65-75% and less than 65%
Attendance(float attendance){
    this.attendance=attendance;
}
public float attendance(){
    return attendance;
}//Returns attendance
}
class Accounts
{
private float dues[];//Dues in Rupees for each department
private String department[]; //Library, Sports, Labs, etc
private float costOfExam; //cost for each exam
 //Total dues across departments and backlogs registered
Accounts(float dues[],String department[],int costofexam)
        {
           this.dues=dues;
           this.department=department;
           this.costOfExam=costofexam;
         }
public float duesTotal(){
    float Total=0;
    for(float i:dues)
        Total+=i;
    Total+=1150;
    return Total;
}
}
class Main{
    public static void main(String[] args) {
    Scanner scan=new Scanner(System.in);
    String Roll=scan.nextLine();
    String failed_sub[]={"C programming"};
    int year_of_exam[]={1};
    float dues[]={100.0f,100.0f,100.0f};
    String due_dept[]={"Sports","library","some dept"};
    //String Name,String Rollno,String email,long phone,String backlogs[],int[] year_of_exam,float attendance,int dues[],String department[],int costofexam
    Student a=new Student("Sai suhrut","160218733044","email.com",92302,failed_sub,year_of_exam,94.09f,dues,due_dept,1000);
    a.display();
}
}
void decimal(int a[])
{
    sum=0;
    int i,j=0;
    for(i=col-1;i<=0;i++)
    {
        sum+=a[i]*pow(2,j);
        j++;
    }
}