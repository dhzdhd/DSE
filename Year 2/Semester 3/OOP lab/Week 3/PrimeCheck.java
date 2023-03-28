import java.util.Scanner;

public class PrimeCheck {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter the number");
		int num = sc.nextInt();
		
		if (num == 1) {
			System.out.println("1 is neither prime nor composite");
			System.exit(0);
		} else if (num < 0) {
			System.out.println("Invalid input");
			System.exit(0);
		}
		
		boolean isPrime = true;
		for (int i = 2; i < num / 2; i++) {
			if (num % i == 0) {
				isPrime = false;
			}
		}
		
		if (isPrime) {
			System.out.println("The given number is prime");
		} else {
			System.out.println("The given number is not prime");
		}
		
	}

}
