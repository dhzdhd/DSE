import java.util.Arrays;

public class PracticeArraySumAvg {

	public static void main(String[] args) {
		
		int arr[] = {12, 67, 87, 34, 90, 23, 67, 88};
		
		int sum = 0;
		float avg = 0;
		
		for (int i: arr) {
			sum += i;
		}
		
		avg = (float)sum / arr.length;
		
		System.out.println("The sum is: " + sum + " and the average is: " + avg);

	}

}
