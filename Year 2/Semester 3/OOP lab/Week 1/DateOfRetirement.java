package Lab4;

import java.util.Scanner;

public class DateOfRetirement {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("Enter year of birth");
		int year = scanner.nextInt();
		System.out.println("Enter month of birth");
		int month = scanner.nextInt();
		System.out.println("Enter date of birth");
		int date = scanner.nextInt();
		
		if (year < 0 || month < 0 || date < 0 || month > 12 || date > 31) {
			System.out.println("Invalid input");
		}
		
		System.out.println("The retirement date is: " + date + "/" + month + "/" + (60 + year));
	}

}
