import java.util.Scanner;
import java.util.Arrays;

public class ConditionalArraySum {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of elements in the array");
		int n = sc.nextInt();
		
		if (n <=0 ) {
			System.out.println("Invalid length entered");
		}

		float arr[] = new float[n];
		
		System.out.println("Enter the elements");
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextFloat();
		}
		
		float sum = 0;
		if (n % 2 == 0) {
			sum += arr[0] + arr[arr.length - 1];
		} else {
			sum += arr[0] + arr[arr.length - 1] + arr[(arr.length) / 2];
		}
		
		System.out.println("The sum is: " + sum);
	}

}
