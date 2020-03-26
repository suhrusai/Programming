package gui;

import java.applet.Applet;

import javax.swing.JButton;

public class dashboard extends Applet{
	public void init() {
		JButton jupcoming=new JButton("Upcoming");
		JButton jorganized=new JButton("Organized");
		JButton jcancelled=new JButton("Cancelled");
		add(jupcoming);
		add(jorganized);
		add(jcancelled);
	}
}
