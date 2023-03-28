import java.util.Scanner;

class Area {
	final double height;
	
	Area(double height) {
		this.height = height;
	}
}

class Triangle extends Area {
	final double base;
	
	Triangle(double base, double height) {
		super(height);
		this.base = base;
	}
	
	double area() {
		return 0.5 * base * height;
	}
}

class Rectangle extends Area {
	final double width;
	
	Rectangle(double width, double height) {
		super(height);
		this.width = width;
	}
	
	double area() {
		return width * height;
	}
}

public class AreaTriangleInheritance {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		double base = 0;
		double height = 0;
		double width = 0;
		
		System.out.println("Enter base and height");
		try {
			String str = sc.next();
			base = Double.parseDouble(str);
			str = sc.next();
			height = Double.parseDouble(str);
		} catch (NumberFormatException e) {
			System.out.println("Invalid input!");
		}
			
		if (base < 0 || height < 0) {
			System.out.println("Invalid dimensions");
		}
		
		Triangle tri = new Triangle(base, height);
		
		System.out.println("Enter width");
		try {
			String str = sc.next();
			width = Double.parseDouble(str);
		} catch (NumberFormatException e) {
			System.out.println("Invalid width");
		}
		
		if (width < 0) {
			System.out.println("Invalid dimensions");
		}
		
		Rectangle rect = new Rectangle(width, height);
		
		System.out.println("The area of the triangle is: " + tri.area() + " and rectangle: " + rect.area());
		
	}

}
