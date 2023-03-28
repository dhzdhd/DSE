import java.util.Scanner;

class Book {
	String fieldName;
	int id;
	double price;
	
	Book(String fieldName, int id, double price) {
		this.fieldName = fieldName;
		this.id = id;
		this.price = price;
	}
	
	String getFieldName() {
		return fieldName;
	}
	
	int getID() {
		return id;
	}
	
	double getPrice() {
		return price;
	}
}

public class BookRepr {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter name, id and price of the book");
		String fieldName = sc.next();
		int id = sc.nextInt();
		double price = sc.nextDouble();
		
		if (price < 0 || id <= 0) {
			System.out.println("Invalid price entered");
			System.exit(0);
		}
		
		Book book = new Book(fieldName, id, price);
		
		System.out.println("The name of the book is: " + book.getFieldName());
		System.out.println("The id of the book is: " + book.getID());
		System.out.println("The price of the book is: " + book.getPrice());
		
	}

}
