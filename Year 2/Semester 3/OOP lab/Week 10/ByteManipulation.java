import java.io.InputStream;
import java.io.OutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

class FileHandler {
	InputStream iStream;
	OutputStream oStream;
	
	FileHandler(InputStream iStream, OutputStream oStream) {
		this.iStream = iStream;
		this.oStream = oStream;
	}
	
	void write(char[] arr) {
		try {
			for (char i : arr) {
				oStream.write((byte) i);
			}
		} catch (IOException e) {
			System.out.println(e);
		}
	}
	
	void read() {
		try {
			byte[] arr = iStream.readAllBytes();
			for (byte i : arr) {
				System.out.print((char)i);
			}
			System.out.println();
		} catch (IOException e) {
			System.out.println(e);
		}
	}
	
	void copy(OutputStream oStream2) {
		try {
			byte[] arr = iStream.readAllBytes();
			for (byte i : arr) {
				oStream2.write(i);
			}
			
			System.out.println("Contents copied!");
		} catch (IOException e) {
			System.out.println(e);
		}
	}
}

public class ByteManipulation {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter file name");
		String fileName = sc.next();
		
		InputStream iStream = null;
		OutputStream oStream = null;
		
		try {
			iStream = new FileInputStream(fileName);
			oStream = new FileOutputStream(fileName);
		} catch (FileNotFoundException e) {
			System.out.println(e);
		}
		
		int choice = 0;
		
		System.out.println("1) Write to file");
		System.out.println("2) Read to file");
		System.out.println("3) Copy bytes from one file to another");
		System.out.println("Else) Exit");
		
		while (true) {
			System.out.println("Enter choice");
			
			try {
				choice = Integer.parseInt(sc.next());
			} catch (NumberFormatException e) {
				System.out.println("Enter a number!");
				continue;
			}
			
			FileHandler file = new FileHandler(iStream, oStream);
			
			switch (choice) {
			case 1 : {
				System.out.println("Enter content to write to file");
				file.write(sc.next().toCharArray());
				break;
			}
			case 2 : {
				file.read();
				break;
			}
			case 3: {
				OutputStream oStream2 = null;
				
				System.out.println("Enter file name");
				String fileName2 = sc.next();
				
				try {
					oStream2 = new FileOutputStream("e");
				} catch (FileNotFoundException e) {
					System.out.println("File not found!");
					continue;
				}
				file.copy(oStream2);
				break;
			} 
			default:{
				System.exit(0);
				break;
			}
			}
		}
	}

}
