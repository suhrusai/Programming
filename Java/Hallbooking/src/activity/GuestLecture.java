package activity;
public class GuestLecture extends Event{
	GuestLecture(String name,String Resource_person,String Designation,int event_slot[],String[] photos){
		super(name,Resource_person,Designation,event_slot,photos);
	}
	Report getReport()
	{
		return null;
	}
}