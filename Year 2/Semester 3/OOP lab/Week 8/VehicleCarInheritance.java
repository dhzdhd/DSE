import java.util.Scanner;

class Vehicle {
	protected String engine;
	protected double mileage;
	
	double getMileage() {
		return mileage;
	}
	
	String getEngine() {
		return engine;
	}
}

class Car extends Vehicle {
	final String company;
	final String model;
	
	Car(String engine, double mileage, String company, String model) {
		this.engine = engine;
		this.mileage = mileage;
		this.company = company;
		this.model = model;
	}
	
	String getCompany() {
		return company;
	}
	
	String getModel() {
		return model;
	}
}

public class VehicleCarInheritance {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter engine, mileage, company and model");
		double mileage = 0;
		
		String engine = sc.next();
		try {
			mileage = Double.parseDouble(sc.next());
		} catch (NumberFormatException e) {
			System.out.println(e);
		}
		
		String company = sc.next();
		String model = sc.next();
		
		Car car = new Car(engine, mileage, company, model);
		
		System.out.println("Details of car:\nEngine: " + car.getEngine() + "\nMileage: " + car.getMileage() + "\nCompany: " + car.getCompany() + "\nModel: " + car.getModel());
	}

}
