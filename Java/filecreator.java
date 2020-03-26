
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
class somepack {

	public static void main(String[] args) {
		final String file1="C:\\Users\\suhru\\OneDrive\\Desktop\\Programming\\Java\\files\\";
		FileOutputStream n=null;
		try {
			n=new FileOutputStream(file1+"file3.txt",true);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		try {
			while(true)n.write("Hi".getBytes());
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
