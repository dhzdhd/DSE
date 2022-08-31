package Lab3;

import java.util.Scanner;

public class RegdNumber {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("Enter registration number: ");
		int regd = scanner.nextInt();
		
		getYear(regd);
			
	}
	
	static void getYear(int regd) {
		if (regd < 0 || (regd / 100000000 == 0)) {
			System.out.println("Invalid input");
		}
		
		System.out.println("The year of admission is: 20" + regd / 10000000);
	}

}
 