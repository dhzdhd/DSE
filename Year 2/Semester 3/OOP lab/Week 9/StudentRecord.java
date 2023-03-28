import java.util.Scanner;

abstract class Student_Detail {
	String name;
	int id;
	String college_name;
	
	abstract void display_details();
}

class MIT extends Student_Detail {
	MIT(String name, int id, String college_name) {
		this.name = name;
		this.id = id;
		this.college_name = college_name;
	}
	
	void display_details() {
		System.out.println("The student details are:");
		System.out.println("Name: " + name + "\nID: " + id + "\nCollege: " + college_name);
	}
}

public class StudentRecord {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter name, id and college name");
		
		String name = sc.next();
		int id = -1;
		
		while (id < 0) {
			try {
				id = Integer.parseInt(sc.next());
			} catch (NumberFormatException e) {
				System.out.println(e);
			}
			
			if (id < 0) {
				System.out.println("ID has to be positive");
			}
		}
		String college_name = sc.next();
	
		MIT obj = new MIT(name, id, college_name);
		obj.display_details();
	}

}
