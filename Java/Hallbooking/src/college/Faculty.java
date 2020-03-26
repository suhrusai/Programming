package college;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Set;

import activity.Event;
import activity.Techtalk;
import exception.RPNA;
import exception.SlotNotAvailable;
public class Faculty{
	String Name;
	String branch;
	public int slots[];
	String past_events[];
	public Faculty(String Name,String branch,int slots[],String past_events[]){
		this.Name=Name;
		this.branch=branch;
		this.slots=slots;
		this.past_events=past_events; 
	}
	public void cancelEvent(Event x){
		x.status="Cancelled";
	}
	public void isAvailable(Event x) throws RPNA {
		if(x.status.contentEquals("Cancelled"))
			throw new RPNA();
	}
	int check_availability(Hall hall_obj,int no_of_slots) throws SlotNotAvailable{
		int i;
		boolean check=true;
		for(i=0;i<6-no_of_slots;i++)
		{
			check=true;
			for(int j=0;j<no_of_slots;j++)
				if(slots[i+j]!=1 || !hall_obj.check_availability(i+j))
				{
					check=false;
				}
			if(check==false)
				throw new SlotNotAvailable();
			else
				return i;
		}
		return -1;
	}   
	public void book_slot(Event x,Hall hall_obj,int no_of_slots){
		int check;
		try {
			check=check_availability(hall_obj,no_of_slots);
		} catch (SlotNotAvailable e) {
			// TODO Auto-generated catch block
			System.out.println("booking not possible ");
			//e.printStackTrace();
			return ;
		}
			int j;
			for(j=0;j<no_of_slots;j++)
				slots[j+check]=0;
			hall_obj.book_slot(x,check,no_of_slots);
			System.out.print("Booking done in slots: ");
			for(j=0;j<no_of_slots;j++)
				System.out.print((j+check+1)+" ");
	}
	public void Display(Faculty a){
		System.out.println("Name="+a.Name);
		System.out.println("Branch="+a.branch);
		System.out.println("slots="+a.slots);
		for(int i=0;i<a.past_events.length;i++)
		{
			System.out.println("Past event "+(i+1)+" "+a.past_events[i]);
		}
	}
	public void check_events(LinkedList<Event> ll){
		 HashSet<String> a=new HashSet<String>();
		 a.add("Cancelled");
		 for(int i = 0;i<ll.size();i++)
		 {
			 a.add(ll.get(i).status);
			 if(a.size()==1)
			 {
				 System.out.println("The following event has been cancelled");
				 ll.get(i).Display((Event) ll.get(i));
			 }
			 else{
				 a.remove("Completed");
			 }
		}
	}

}