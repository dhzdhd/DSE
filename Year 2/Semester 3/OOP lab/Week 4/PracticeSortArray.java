import java.util.Arrays;

public class PracticeSortArray {

	public static void main(String[] args) {
		
		int arr[] = {12, 67, 87, 34, 90, 23, 67, 88};
		Arrays.sort(arr);
		System.out.println("Sorted array is");
		
		for (int i: arr) {
			System.out.print(i + " ");
		}
	}

}
