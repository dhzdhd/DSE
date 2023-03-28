import java.util.Scanner;

class VolumeDemonstration {
	final double length;
	final double breadth;
	
	VolumeDemonstration() {
		this.length = 0;
		this.breadth = 0;
	}
	
	VolumeDemonstration(double length) {
		this.length = length;
		this.breadth = 0;
	}
	
	VolumeDemonstration(double length, double breadth) {
		this.length = length;
		this.breadth = breadth;
	}
	
	double getVolume() {
		return length * breadth * 0;
	}
	
	double getVolume(double height) {
		return length * breadth * height;
	}
}

public class OverloadingDemonstration {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter length");
		double length = sc.nextDouble();
		
		System.out.println("Enter breadth");
		double breadth = sc.nextDouble();
		
		VolumeDemonstration obj = new VolumeDemonstration(length, breadth);
		VolumeDemonstration obj1 = new VolumeDemonstration();
		VolumeDemonstration obj2 = new VolumeDemonstration(length);

		if (length < 0 || breadth < 0) {
			System.out.println("Invalid dimensions!");
		}
		
		System.out.println("Volume without anything passed: " + obj1.getVolume());
		System.out.println("Volume without breadth and height passed: " + obj2.getVolume());
		System.out.println("Volume without height passed: " + obj.getVolume());
		
		System.out.println("Enter height");
		double height = sc.nextDouble();
		
		if (height < 0) {
			System.out.println("Invalid height!");
		}
		
		System.out.println("Volume with height passed: " + obj.getVolume(height));
	}

}
