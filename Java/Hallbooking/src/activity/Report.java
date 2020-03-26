package activity;

import college.Hall;

public interface Report{
	String[] TakeNotes();
	String[] Photos();
	String[][] SubmitBill(Hall hall_obj,int slotnum,int fee_per_hour);
}