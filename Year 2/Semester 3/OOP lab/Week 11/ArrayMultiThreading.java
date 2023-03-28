import java.util.Scanner;

class Union implements Runnable {
	int arr1[], arr2[];
	
	Union(int[] arr1, int[] arr2) {
		this.arr1 = arr1;
		this.arr2 = arr2;
		
		Thread t = new Thread(this);
		t.start();
	}
	
	boolean contains(int i, int[] arr) {
		for (int j: arr) {
			if (i == j) {
				return true;
			}
		}
		return false;
	}
	
	public void run() {
		int[] arr3 = new int[arr1.length + arr2.length];
		int count = 0;
		
		for (int i: arr1) {
			for(int j: arr2) {
			  if (i == j && !contains(j, arr3)) {
				  arr3[count] = i;
				  count++;
			  } else if (!contains(j, arr3)){
				  arr3[count] = j;
				  count++;
			  }
			}
			if (!contains(i, arr3)) {
				arr3[count] = i;
				count++;
			}
		}
		
		System.out.println("Union is");
		for (int i: arr3) {
			if (i != 0) 
			System.out.print(i + " ");
		}
		System.out.println();
	}
}

class Intersection implements Runnable {
	int arr1[], arr2[];
	
	Intersection(int[] arr1, int[] arr2) {
		this.arr1 = arr1;
		this.arr2 = arr2;
		
		Thread t = new Thread(this);
		t.start();
	}
	
	boolean contains(int i, int[] arr) {
		for (int j: arr) {
			if (i == j) {
				return true;
			}
		}
		return false;
	}
	
	public void run() {
		int[] arr3 = new int[arr1.length + arr2.length];
		int count = 0;
		
		for (int i: arr1) {
			for(int j: arr2) {
			  if (i == j && !contains(j, arr3)) {
				  arr3[count] = i;
				  count++;
			  }
			}
		}
		
		System.out.println("Intersection is");
		for (int i: arr3) {
			if (i != 0) 
			System.out.print(i + " ");
		}
		
	}
}

public class ArrayMultiThreading {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n1 = 0, n2 = 0;
		int arr1[], arr2[];
		
		try {
			System.out.println("Enter number of elements in 1st array");
			n1 = sc.nextInt();
			
			System.out.println("Enter number of elements in 2nd array");
			n2 = sc.nextInt();
		
			arr1 = new int[n1]; 
			arr2 = new int[n2];
			
			System.out.println("Enter elements of 1st array");
			for (int i = 0; i < n1; i++) {
				arr1[i] = sc.nextInt();
	 		}
			
			System.out.println("Enter elements of 2nd array");
			for (int i = 0; i < n2; i++) {
				arr2[i] = sc.nextInt();
	 		}
			
			new Union(arr1, arr2);
			new Intersection(arr1, arr2);
		}
		catch (NumberFormatException e) {
			System.out.println(e);
		}
	}

}
