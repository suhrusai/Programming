import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Scanner;
class thread1 implements Runnable{
    Q1 q=null;
    thread1(Q1 q){
        this.q=q;
    }
    public void run(){
        try{
            wait();
        }catch(Exception e){}
        q.thread1(q.s);
    }
}
class thread2 implements Runnable{
    Q1 q=null;
    thread2(Q1 q){
        this.q=q;
    } 
    public void run(){
        q.thread2(q.s);
    }
}
class Q1 implements Runnable{
    String s;
    static Q1 q;

    Q1(Q1 q) {
        this.q = q;
    }

    public static void main(String[] args) {
        q.startprogram();
        } 
    public void startprogram(){
        q=new Q1(null);
        Thread mainthread=new Thread(new Q1(q),"Main thread");
        Thread t1=new Thread(new thread1(q),"Thread t1");
        Thread t2=new Thread(new thread2(q),"Thread t2");
        mainthread.start();
        t1.start();
        t2.start();
        while(mainthread.isAlive()){
            try{Thread.sleep(1000);}
            catch(Exception e){}
    }
}
    public void run(){
        mainthread(q);
    }
    synchronized public void mainthread(Q1 q){
        Scanner scan=new Scanner(System.in);
        FileInputStream fismain=null;
        FileOutputStream fosmain=null;
        try{fosmain=new FileOutputStream("C:\\Users\\suhru\\OneDrive\\Desktop\\Programming\\Java\\Asst2\\files\\mainthread.txt");
        fismain=new FileInputStream("C:\\Users\\suhru\\OneDrive\\Desktop\\Programming\\Java\\Asst2\\files\\mainthread.txt");
    }catch(Exception e){System.out.println("Exception");}
    try {wait();}catch(Exception e){}
        while(true){
        q.s=scan.nextLine();
        try{fosmain.write(s.getBytes());
        System.out.println("M1"+fismain.readAllBytes());}catch(Exception e){}
        }
        try{wait();}catch(Exception e){}
        notify();
    }
    public void thread1(String s){
        System.out.println("Thread 1");
    }
    public void thread2(String s){
        System.out.println("Thread 2");
    }
}