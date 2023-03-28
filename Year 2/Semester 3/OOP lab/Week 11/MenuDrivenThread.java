import java.util.Scanner;

class ThreadInheritance extends Thread {
	ThreadInheritance() {
		start();
	}
	
	@Override
	public void run() {
		System.out.println("Inheritance in thread");
	}
}

class ThreadInterface implements Runnable {
	ThreadInterface() {
		Thread t = new Thread(this);
		t.start();
	}
	
	@Override
	public void run() {
		System.out.println("Interfacing in thread");
	}
}

public class MenuDrivenThread {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int choice = 0;
		
		System.out.println("1) Inheritance\n2) Interface\nElse) Exit");
		
		while (true) {
			System.out.println("Enter choice");
			try {
				choice = Integer.parseInt(sc.next());
			} catch (NumberFormatException e) {
				System.out.println(e);
			}
			
			switch (choice) {
			case 1: {
				new ThreadInheritance();
				break;
			}
			case 2: {
				new ThreadInterface();
				break;
			}
			default: System.exit(0);
			}
		}
			
	}

}
