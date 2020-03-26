/**
 * 
 */
package Q2;

import java.awt.BorderLayout;
import java.util.HashMap;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

/**
 * @author suhru
 *
 */
 class q11 {
	JFrame login= new JFrame("Login");
	JTextField user,pass;
	private HashMap <String,String>a=new HashMap<String,String>();
	public static void main(String args[]) {
		q11 q= new q11();
		q.initializer();
		q.loginframe();
	}
	public void loginframe() {
		JLabel loginlabel=new JLabel("Login");
		login.setLayout(new BorderLayout());
		login.add(loginlabel,BorderLayout.NORTH);
		loginlabel.setFont(loginlabel.getFont().deriveFont (22.0f));
		JPanel details=new JPanel();
		details.add(new JLabel("Username:"));
		user=new JTextField(20);
		pass=new JTextField(20);
		details.add(new JLabel("Password: "));
	}
	public void initializer() {
		a.put("admin","admin");
	}
	public boolean validator(String username,String password) {
		String Password=a.get(username);
		if(Password!=null && Password.equals(password)) {
			return true;
		}
		return false;
	}
	
}
