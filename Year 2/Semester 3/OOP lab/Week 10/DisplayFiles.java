import java.io.File;
import  java.util.Scanner;

public class DisplayFiles {
	
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter path");
		//C:\\Users\\dse\\Documents\\210968002\\Week 10
		String path = sc.nextLine();
		
		File f = new File(path);
		try {
			for (String s: f.list()) {
				System.out.println(s);
			}
		} catch (NullPointerException e) {
			System.out.println("The given path does not exist");
		}
	}

}
