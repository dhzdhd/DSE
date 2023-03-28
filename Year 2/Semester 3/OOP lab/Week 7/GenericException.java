import java.util.Scanner;

public class GenericException {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		// ArithmeticException
		try {
			int quo = 5 / 0;
		} catch (Exception e) {
			System.out.println(e);
		}
		
		// InputMismatchException
		try {
			System.out.println("Enter a number");
			int c = sc.nextInt();
		} catch (Exception e) {
			System.out.println(e);
		}
		
		// NullPointerException
		try {
			String str= null;
			char[] arr = str.toCharArray();
		} catch (Exception e) {
			System.out.println(e);
		}
		
		// ArrayIndexOutOfBoundsException
		try {
			int[] arr = {1, 2, 3};
			int ele = arr[5];
		} catch (Exception e) {
			System.out.println(e);
		}
		
		// StringIndexOutOfBoundsException
		try {
			String str = "Hello";
			char ele = str.charAt(10);
		} catch (Exception e) {
			System.out.println(e);
		}
		
		// NegativeArraySizeException
		try {
			int[] intArr = new int[-1];
		} catch (Exception e) {
			System.out.println(e);
		}
		
		// ArrayStoreException
		try {
			Object arr[] = new Double[2];
			arr[0] = "hello";
		} catch (Exception e) {
			System.out.println(e);
		}
		
		// NumberFormatException
		try {
			String a = "e";
			Integer.parseInt(a);
		} catch (Exception e) {
			System.out.println(e);
		}
	}

}
