import java.util.Scanner;

class Parcel {
	final String name;
	final int id;
	final int weight;
	
	Parcel(String name, int id, int weight) {
		this.name = name;
		this.id = id;
		this.weight = weight;
	}
	
	double getPrice() {
		if (weight <= 2) {
			return 32.5;
		} else {
			return 32.5 + (weight - 2) * 10.5;
		}
	}
}

public class PostOfficeParcel {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter number of parcels");
		final int parcels = sc.nextInt();
		
		if (parcels <= 0) {
			System.out.println("Invalid length");
			return;
		}
		
		final Parcel parcelArr[] = new Parcel[parcels];
		
		for (int i = 0; i < parcels; i++) {
			System.out.println("\nEnter parcels details");
			System.out.println("Enter parcel name");
			final String name = sc.next();
			
			System.out.println("Enter parcel id");
			final int id = sc.nextInt();
			
			System.out.println("Enter parcel weight");
			final int weight = sc.nextInt();
			
			parcelArr[i] = new Parcel(name, id, weight);
			
			System.out.println("The price of the parcel is: " + parcelArr[i].getPrice());
		}
	}

}
