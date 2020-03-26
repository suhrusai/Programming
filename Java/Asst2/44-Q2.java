/*Q2.Given a large String, write a program to insert the required
characters in each word, to make all strings inside it as Palindromes.
Input: Tomorrow is a Holiday
Output:
TomorroworromoT sis aa HolidayadiloH
Input: Astalavista
Output:
AstalavistatsivalatsA
Input: SuperepuS
Output:
Already Dual Palindrome*/
import java.util.Scanner;
class Q2{
    public static void main(String[] args) {
    int count=0;
    String delim=new String(" ");
    Scanner scan=new Scanner(System.in);
    String s=scan.nextLine();
    String[] broken=s.split(delim,1000);
    for(int i=0;i<broken.length;i++){
        float mid=(float)broken[i].length()/2;
        //System.out.println((broken[i].substring(0,(int)mid)));
        //System.out.println(reverse(broken[i]));
        if(broken[i].equals(reverse(broken[i])))
        {
            count++;
            //System.out.println("Hello world");
        }
        broken[i]=broken[i]+reverse(broken[i]).substring(1);
    }
    if(count==broken.length)
        System.out.println("Dual palindrome");
    else{
        for(int i=0;i<broken.length;i++)
        {
            System.out.print(broken[i]+" ");
        }
    }
    }
   public static String reverse(String a){
       String s="";
        for(int i=a.length()-1;i>-1;i--){
            s=s+a.charAt(i);
        }
        return s;
   }
}
/*Input:Hello Everyone
Output:HellolleH EveryonenoyrevE

Input: madam
Output:Dual palindrme
Input:Tomorrow is a Holiday
Output: TomorroworromoT isi a HolidayadiloH 
*/
