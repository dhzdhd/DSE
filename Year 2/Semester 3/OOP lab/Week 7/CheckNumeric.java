import java.util.Scanner;

public class CheckNumeric {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int arr[] = new int[3];
		
		int count = 0;
		while (count != 3) {
			try {
				System.out.println("Enter a number");
				String str = sc.next();
				
				arr[count] = Integer.parseInt(str);
				count++;
			} catch (NumberFormatException e) {
				System.out.println("Enter a numeric value!");
			}
		}
		
		System.out.println("The output is: ");
		for (int i: arr) {
			System.out.print(i + " ");
		}
		
	}

}
