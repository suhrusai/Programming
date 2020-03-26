package activity;

public abstract class Event{
	String name;
	String Resource_person;
	String Designation;
	int event_slot[];
	public String status="Completed";
	String photos[];
	Event(String name,String Resource_person,String Designation,int event_slot[],String photos[]){
		this.name=name;
		this.Resource_person=Resource_person;
		this.Designation=Designation;
		this.event_slot=event_slot;
		this.photos=photos;
	}
	public void set_slot()
	{	
	}
	public void Report(){

	}   
	int bill(){
		return 0;	
	}
	public void Display(Event a){
		System.out.println("Name="+a.name);
		System.out.println("Resourse person="+a.Resource_person);
		System.out.println("Designation "+a.Designation);
		System.out.println("Event slot "+a.event_slot);   
		for(int i=0;i<a.photos.length;i++){
			System.out.println(a.photos[i]);
		}
	}
}
/*class GuestLecture extends Event{
	GuestLecture(String name,String Resource_person,String Designation,int event_slot[],String[] photos){
		super(name,Resource_person,Designation,event_slot,photos);
	}
}*/
/*class VasaviTalkies extends Event{
	VasaviTalkies(String name,String Resource_person,String Designation,int event_slot[],String[] photos){
		super(name,Resource_person,Designation,event_slot,photos);
	}
}*/
/*class Techtalk extends Event{
	Techtalk(String name,String Resource_person,String Designation,int event_slot[],String[] photos){
		super(name,Resource_person,Designation,event_slot,photos);
	}
}*/