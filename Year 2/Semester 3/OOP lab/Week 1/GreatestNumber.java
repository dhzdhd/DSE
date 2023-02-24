package mit.dse.q1;

import java.util.Scanner;

public class GreatestNumber {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("Enter three integers:");
		
		int a = scanner.nextInt();
		int b = scanner.nextInt();
		int c = scanner.nextInt();
		
		System.out.println("The greatest number of the three is: " + getGreatestNum(a, b, c));
		
	}

	
	static int getGreatestNum(int a, int b, int c) {
		if (a == b && b == c) {
			System.out.println("Numbers are equal!");
		}
		return a > b && a > c ? a : b > c ? b : c;
	}
}
