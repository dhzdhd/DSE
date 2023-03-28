import java.util.Scanner;

public class RectangularArea {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		System.out.println("Enter the length and breadth of the rectangle");
		double length = sc.nextDouble();
		double breadth = sc.nextDouble();
		
		if (length < 0 || breadth < 0) {
			System.out.println("Invalid dimensions entered");
			System.exit(0);
		}
		
		double area = length * breadth;
		double circ = 2 * (length + breadth);
		
		System.out.println("The area of the rectangle is " + area);
		System.out.println("The circumference of the rectangle is " + circ);
	}

}
