import java.util.Scanner;

public class FloatArraySum {

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
		for (float element: arr) {
			sum += element;
		}
		
		System.out.println("The sum of the elements in the array is: " + sum);
	}

}
