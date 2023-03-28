import java.util.Scanner;

class IntegerArray {
	final int intArr[]; 
	
	IntegerArray() {
		intArr = new int[0];
	}
	
	IntegerArray(int num[]) {
		intArr = num;
	}
	
	void print() {
		System.out.println("The contents of the array are");
		for (int i: intArr) {
			System.out.println(i + " ");
		}
	}

	void search(int num) {
		for (int i: intArr) {
			if (i == num) {
				System.out.println(num + " found!");
				return;
			}
		}
		System.out.println("Number not found!");
	}

	void compare(IntegerArray obj) {
		if (this.equals(obj)) {
			System.out.println("The two objects are equal!");
			return;
		}
		System.out.println("The two objects are not equal");
	}
}

public class IntegerArrayClass {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter the number of elements in the array");
		int n = sc.nextInt();
		
		if (n <= 0) {
			System.out.println("Invalid length entered!");
			return;
		}
		
		int arr[] = new int[n];
		
		System.out.println("Enter the elements");
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		
		IntegerArray obj = new IntegerArray(arr);

		int choice = 1;
		while (choice != 0) {
			System.out.println("\n0) Exit");
			System.out.println("1) Display the array");
			System.out.println("2) Search for a number");
			System.out.println("3) Compare objects");
			System.out.println("Enter your choice");
			
			choice = sc.nextInt();
			
			switch (choice) {
			case 0: {
				System.exit(0);
				break;
			}
			case 1: {
				obj.print();
				break;
			}
			case 2: {
				System.out.println("Enter number to search");
				int num = sc.nextInt();
				
				obj.search(num);
				break;
			}
			case 3: {
				System.out.println("Enter the number of elements in the array");
				
				int temp_n = sc.nextInt();
				if (temp_n <= 0) {
					System.out.println("Invalid length entered!");
					continue;
				}
				
				int temp_arr[] = new int[temp_n];
				
				System.out.println("Enter the elements");
				for (int i = 0; i < temp_n; i++) {
					arr[i] = sc.nextInt();
				}
				
				IntegerArray temp_obj = new IntegerArray(temp_arr);
				
				obj.compare(temp_obj);
				break;
			}
			default: {
				System.out.println("Invalid choice entered!");
			}
			}
		}
	}

}
