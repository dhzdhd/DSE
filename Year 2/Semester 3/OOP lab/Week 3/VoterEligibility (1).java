import java.util.Scanner;

public class VoterEligibility {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		System.out.println("Enter your age");
		int age = sc.nextInt();
		
		int choice = 0;
		
		if (age < 18 && age >= 0) {
			 choice = 0;
		} else if (age == 18) {
			choice = 1;
		} else if (age > 18 && age <= 100) {
			choice = 2;
		} else {
			choice = 3;
		}
		
		switch (choice) {
		case 0: {
			System.out.println("Candidate is not eligible to vote!");
			break;
		}
		case 1: case 2: {
			System.out.println("Candidate is eligible to vote!");
			break;
		}
		default: {
			System.out.println("Invalid age entered");
		}
		}
	}

}
