package activity;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import college.Hall;
public class VasaviTalkies extends Event{
	int fee_per_hour;	
	boolean flag=true;
	Common common=new Common();
	public VasaviTalkies(String name,String Resource_person,String Designation,int event_slot[],String[] photos, int fee_per_hour,Common common){
		super(name,Resource_person,Designation,event_slot,photos);
		this.fee_per_hour=fee_per_hour;
		this.common=common;
	}
	private void write(FileOutputStream a,String s) {
		try {
			System.out.println(s);
			a.write(s.getBytes());
			a.flush();
		} catch (Exception e) {
			e.printStackTrace();
		}
		try {
			a.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	synchronized private void photos() {
		FileOutputStream a=null;
		while(flag) {
			try {
				wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		try {
			a=new FileOutputStream("C:\\Users\\suhru\\OneDrive\\Desktop\\Programming\\Java\\Notes.txt",true);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		write(a,"and deadlock too\n");
		System.out.println("1111111111111111111nognfwrgg");
		flag=true;
		notify();
	}
	synchronized private void notes() {
		while(!flag) {
			try {
				wait();
			}
			catch(Exception e) {
				e.printStackTrace();
			}
		}
		FileOutputStream a=null;
		try {
			a=new FileOutputStream("C:\\Users\\suhru\\OneDrive\\Desktop\\Programming\\Java\\Notes.txt",true);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println("0000000000000000000000000000000");
		write(a,"java ");
		flag=false;
		notify();
	}
	public Report getReport()
	{
		return new Report() {
			public String[] TakeNotes() {
				Thread t= new Thread() {
					FileOutputStream a=null;
					public void run() {
						notes();
					}
				};
				t.start();
				return null;}
			public String[] Photos()  {
				Thread t= new Thread() {

					public void run() {
						photos();
					}

				};
				t.start();
				return null;}
			public String[][] SubmitBill(Hall hall_obj,int slotnum,int fee_per_hour){
				String[][] fee=new String[4][2];
				fee[0][0]="Base Price: Rs.";
				fee[0][1]=""+300;
				fee[1][0]="Cost for time: Rs.";
				fee[1][1]=""+hall_obj.cost*slotnum;
				fee[2][0]="Special Charges: Rs.";
				fee[2][1]=""+500;
				fee[3][0]="Charges for speaker ";
				fee[3][1]=""+fee_per_hour*slotnum;
				return fee;
			}
		};
	}
}