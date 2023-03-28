import java.io.RandomAccessFile;
import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.IOException;

public class RandomAccessHandling {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter path");
		String path = sc.next();
		
		RandomAccessFile file = null;
		try {
			file = new RandomAccessFile(path, "rw");
		} catch (FileNotFoundException e) {
			System.out.println(e);
		}
		
		System.out.println("Enter content to write");
		int i = sc.nextInt();
		
		try {
			file.writeInt(i);
			
			file.seek(0);
			
			int output = file.readInt();
			System.out.println("The read content: " + output);
			
			System.out.println("Enter content to append");
			int newI = sc.nextInt();
			file.seek(file.length());
			file.writeInt(newI);
		
			System.out.println("Content appended!");
			
		} catch (IOException e) {
			System.out.println(e);
		}
		
		
	}
		
}
