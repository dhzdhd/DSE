import java.util.Scanner;

abstract class Area {
	double height;
	
	abstract double getArea();
}

class Square extends Area {
	Square(double height) {
		super.height = height;
	}
	
	double getArea() {
		return height * height;
	}
}

class Triangle extends Area {
	double base;
	
	Triangle(double height, double base) {
		super.height = height;
		this.base = base;
	}
	
	double getArea() {
		return 0.5 * base * height;
	}
}

public class AreaComputationPractice {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter height and base");
		
		double height = -1;
		double base = -1;
		
		while (height < 0) {
			try {
				height = Double.parseDouble(sc.next());
			} catch (NumberFormatException e) {
				System.out.println(e);
			}
			
			if (height < 0) {
				System.out.println("Height has to be positive");
			}
		}
		
		while (base < 0) {
			try {
				base = Double.parseDouble(sc.next());
			} catch (NumberFormatException e) {
				System.out.println(e);
			}
			
			if (base < 0) {
				System.out.println("Base has to be positive");
			}
		}
		
		Square square = new Square(height);
		Triangle tri = new Triangle(height, base);
		
		System.out.println("The area of square is: " + square.getArea() + "\nThe area of triangle is: " + tri.getArea());
		
	}

}
