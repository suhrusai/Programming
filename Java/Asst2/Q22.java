import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FilterOutputStream;
import java.io.IOException;
import java.util.Scanner;
class threads {
}
class thread1 implements Runnable{
	Q22 q;
	String s;
	thread1(Q22 q,String s){
		this.q=q;
		this.s=s;
		Thread t=new Thread(this,"Thread 1");
		t.start();
	}

	@Override
	public void run() {
		q.thread1(s);	
	}


}
class thread2 implements Runnable{
	Q22 q=null;
	String s=null;
	thread2(Q22 q,String s){
		this.q=q;
		this.s=s;
		Thread t=new Thread(this,"Thread 2");
		t.start();
	}

	@Override
	public void run() {
		q.thread2(s);	
	}


}
public class Q22 {
	String s;
	final String file1="C:\\Users\\suhru\\OneDrive\\Desktop\\Programming\\Java\\files\\";
	boolean value=false;
	boolean mainval=true;
	FileOutputStream fos,fos1,fosmain;
	FileInputStream fismain,fis,fis1;
	Q22 q=null;
	public static void main(String[] args) throws IOException {
		String s;
		while(true) {
			new Q22().mainthread();
		}
	}
	//For main thread
	synchronized void mainthread()  {
		byte[] b = null;
		while(!mainval) {
			try{wait();}catch (Exception e) {};
		}
		try {
			System.out.print("Input: ");
			String s=(new Scanner(System.in)).nextLine();
			System.out.print("\nMT: ");
			FileOP("mainthread.txt",s);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		q=new Q22();
		new thread1(q,s);
		new thread2(q,s);
		mainval=false;
		notify();
	}
	void FileOP(String file2,String s) throws Exception {
		fis=new FileInputStream(file1+file2);
		fos=new FileOutputStream(file1+file2,true);
		byte[] b = this.fis.readAllBytes();
		System.out.println(new String(b));
		fos.write(s.getBytes());
		fos.flush();
		fis.close();
		fos.close();		
	}
	synchronized void thread1(String s) {
		while(value&& mainval) 
			try {
				wait();
			}catch(Exception e) {}
		try {
			System.out.print("T1: ");
			FileOP("file1.txt",s);
		} catch (Exception e) {
			// TODO Auto-generated catch block
		}
		//for(int i=0;i<s.getBytes().length;i++)
			//System.out.println(s.getBytes()[i]);
		value=true;
		notify();
	}
	synchronized void thread2(String s) {
		while(!value && mainval) {
			try {
				wait();
			}catch(Exception e) {}}
		try {
			System.out.print("T2: ");
			FileOP("file2.txt",s);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println("Hello2");
		value=false;
		notify();
	}
}

