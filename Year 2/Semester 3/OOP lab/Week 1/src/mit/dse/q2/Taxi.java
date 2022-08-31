package Lab2;

import java.util.Scanner;

public class Taxi {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("Enter cost");
		double cost = scanner.nextDouble();
		
		getDistance(cost);
	
	}
	
	static void getDistance(double doubleCost) {
		if (doubleCost < 0) {
			System.out.println("Invalid cost!");
			return;
		}
		
		int cost = (int) doubleCost;
				
		if (cost <= 50) {
			System.out.println(cost / 10);
		} else if (cost <= (50 + 10 * 8)) {
			System.out.println( 5 + (cost - 50) / 8);
		} else if (cost <= 300) {
			System.out.println(5 + 10 + ((cost - 50 - 80) / 5));
		} else {
			System.out.println("Maximum cost exceeded!");
		}
	 
	}	
}
