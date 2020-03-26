import java.util.LinkedList;
import java.util.Collections.*;

import college.Faculty;
import college.Hall;
import exception.RPNA;
import activity.Common;
import activity.Event;
import activity.Report;
import activity.Techtalk;
import activity.VasaviTalkies;
public class Mainclass {

	public static void main(String[] args) {
		LinkedList<Event> ll=new LinkedList<Event>();
		/*create_hall(200,"EEE",200,"EEE block");*/
		Hall hall_obj=Hall.getInstance();
		hall_obj.branch="CSE";
		hall_obj.cost=200;
		hall_obj.location="Ramanujan Block";
		String past_events[]={"AI","Java"};
		int fac_avalibility[]={0,1,1,1,1,1};
		Faculty shasi= new Faculty("Shasi","CSE",fac_avalibility,past_events);
		String photos[]={"C:/jpeg.jpeg","C:/jpeg1.jpeg","C:/jpeg2.jpeg"};
		int event_slot[]={0,1,1,0,0,0};
		Techtalk AI=new Techtalk("AI","Somebody","Professor",event_slot,photos,200,new Common()); 
		ll.add(AI);
		System.out.println("\nHall details:\n"); 
		hall_obj.Display(hall_obj);
		System.out.println("\nFaculty details:\n"); 
		shasi.Display(shasi);
		System.out.println("\nEvent details:\n"); 
		AI.Display(AI);
		System.out.print("Booking status: ");
		//shasi.book_slot(AI,hall_obj,4); 
		System.out.println();  
		for(int i=0;i<6;i++)
		{	System.out.print(shasi.slots[i]+" ");
		}
		Report a=AI.getReport();
		String[][] Bill=a.SubmitBill(hall_obj,4,200);
		System.out.println();
		for (int j = 0; j < Bill.length; j++) {
			System.out.println(Bill[j][0]+" "+Bill[j][1]);
		}
		VasaviTalkies something=new VasaviTalkies("Someevent","Suhrut","XYZ",event_slot,photos, 200,new Common());
		VasaviTalkies something1=new VasaviTalkies("Someevent","Suhrut","XYZ",event_slot,photos, 200,new Common());
		shasi.cancelEvent(something);
		try{
			shasi.isAvailable(something);
		}catch(RPNA e) {

		}
		ll.add(something);
		ll.add(something1);
		shasi.check_events(ll);
		Techtalk somethingtech=new Techtalk(null, null, null, event_slot, photos, 0,new Common());
		String[][] Bill1= (something.getReport()).SubmitBill(hall_obj,4,200);
		Report a1=somethingtech.getReport();
		a1.TakeNotes();
		a1.Photos();
		for (int j = 0; j < Bill1.length; j++) {
			System.out.println(Bill1[j][0]+" "+Bill1[j][1]);
		}
	}
}
