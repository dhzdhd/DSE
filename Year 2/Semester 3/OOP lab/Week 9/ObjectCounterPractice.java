import java.util.Scanner;

abstract class Counter {
	static int counter = 0;
	
	Counter() {
		Counter.counter++;
	}
}

class Helper extends Counter {
	Helper() {
		super();
	}
}

public class ObjectCounterPractice {

	public static void main(String[] args) {
		new Helper();
		new Helper();
		new Helper();
		new Helper();
		new Helper();
		
		System.out.println("Number of objects created: " + Counter.counter);
	}

}
