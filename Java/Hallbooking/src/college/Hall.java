package college;
import activity.*;
public class Hall{
	private static Hall hall_obj;
	int Capacity=200;
	Event slots[]={null,null,null,null,null,null};
	public String branch;
	public int cost;
	public String location;
	private Hall(int Capacity,String branch,int cost,String location){
	this.Capacity=Capacity;
     this.branch=branch;
     this.cost=cost;
     this.location=location;
	}
	/**
	 * 
	 */
	public Hall() {
		// TODO Auto-generated constructor stub
	}
	public static Hall getInstance(){
		if (hall_obj == null)
			hall_obj = new Hall();
		return hall_obj;
	}
	public boolean check_availability(int slot){
		if(slots[slot]==null)
			return true;
		return false;
	}
	void book_slot(Event x, int slot,int no_of_slots){
		for(int j=0;j<no_of_slots;j++)
			slots[slot+j]=x;
	}
	public void Display(Hall a){
		System.out.println("Capacity="+a.Capacity);
		System.out.println("slots="+a.slots);
		System.out.println("Branch="+a.branch);
		System.out.println("Cost=Rs."+a.cost);
		System.out.println("Location="+a.location);
	}
}