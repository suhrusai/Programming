package gui;
import java.applet.Applet;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

import college.Hall;
public class gui extends Applet implements ActionListener{
	JTextField jt4=null;
	JTextField jt1=null;
	JComboBox<String> cb=null; 
	JPanel home=new JPanel();
	public void init() {
		/*
		 * This is for home Screen of the applet
		*/
		//Faculty field
		setSize(1000,1000);
		home.setSize(1000, 1000);		
		JLabel jl1=new JLabel("Faculty");
		//jl1.setFont(new Font("Arial", Font.PLAIN, 40));
		jt1=new JTextField(20);
		//jt1.setPreferredSize(new Dimension(300,40));
		//Hall name field
		JLabel jl2=new JLabel("Hall name");
		//jl2.setFont(new Font("Arial", Font.PLAIN, 40));
		JTextField jt2=new JTextField(20);
		//jt2.setPreferredSize(new Dimension(300,40));
		//Date field
		JLabel jl3=new JLabel("Date");
		//jl3.setFont(new Font("Arial", Font.PLAIN, 40));
		JTextField jt3=new JTextField(20);
		//jt3.setPreferredSize(new Dimension(300,40));
		//Slot Number
		JLabel jl4=new JLabel("Slot");
		//jl4.setFont(new Font("Arial", Font.PLAIN, 40));
		jt4=new JTextField(20);
		//jt4.setPreferredSize(new Dimension(300,40));
		JButton jbsubmit=new JButton("Submit");
		jbsubmit.addActionListener(this);
		JPanel faculty=new JPanel();
		JPanel Hall=new JPanel();
		JPanel Date=new JPanel();
		JPanel Slot=new JPanel();
		faculty.add(jl1);
		faculty.add(jt1);
		String[] choices = { "Ramanujan block ground floor","QEEE","Ground","MCA seminar Hall","Pendaganti Hall"};
		Integer[] darray= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
		Integer[] marray= {1,2,3,4,5,6,7,8,9,10,11,12};
		Integer yarray[]=new Integer[100]; 
				
		for(int i=2000;i<2100;i++) {
			yarray[i-2000]=i;
		}
	    cb = new JComboBox<String>(choices);
	    final JComboBox<Integer> dd= new JComboBox<Integer>(darray);
	    final JComboBox<Integer> mm= new JComboBox<Integer>(marray);
	    final JComboBox<Integer> yy= new JComboBox<Integer>(yarray);
	    //cb.setPreferredSize(new Dimension(300,40));
		home.add(faculty);
		Hall.add(jl2);
		Hall.add(cb);
		Date.add(jl3);
		Date.add(dd);
		//Date.add(jt3);
		Date.add(mm);
		Date.add(yy);
		Slot.add(jl4);
		Slot.add(jt4);
		home.add(Hall);
		home.add(Date);
		home.add(Slot);
		home.add(jbsubmit);
		home.setLayout(new BoxLayout(home,BoxLayout.Y_AXIS));
		//home.setLayout(new BorderLayout());
		add(home);
		JPanel dashboard= new JPanel();
		dashboard.add(new dashboard());
		System.out.println(cb.getSelectedItem());
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		//try {
//			Class c = Class.forName(jt4.getText());
			//Hall hall_obj = (Hall) c.newInstance();
			System.out.println(cb.getSelectedItem());
		try{if((Hall.getInstance()).check_availability(Integer.parseInt(jt4.getText()))) {
			JOptionPane jp=new JOptionPane();
			JOptionPane.showMessageDialog(this,"Slot available");
			home.setVisible(false);
		}
		else {
			JOptionPane.showMessageDialog(this,"Not ", "Eror", JOptionPane.ERROR_MESSAGE);
		}
		}catch(ArrayIndexOutOfBoundsException e11) {
			JOptionPane.showMessageDialog(this,"Please enter slot between 1-6", "Invalid Slot Range", JOptionPane.ERROR_MESSAGE);
		}catch(NumberFormatException e1) {
			JOptionPane.showMessageDialog(this,"Please enter a valid slot number", "Invalid Slot Input", JOptionPane.ERROR_MESSAGE);
		}catch(Exception e1) {
			JOptionPane.showMessageDialog(this,"Unknown Problem", "Unkown Problem", JOptionPane.ERROR_MESSAGE);
		}
	}
	}