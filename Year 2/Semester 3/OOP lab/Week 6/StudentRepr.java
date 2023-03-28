import java.util.Scanner;

class Student {
	int id;
	double[] marks;
	double sum;
	
	Student(int id, double[] marks) {
		this.id = id;
		this.marks = marks;
		this.sum = 0;
	}
	
	void calcScore() {
		for (double i: marks) {
			sum += i;
		}
		
		System.out.println("The total marks of the student is: " + sum);
	}
	
	void passOrFail() {
		for (int i = 0; i < 5; i++) {
			if (marks[i] >= 40) {
				System.out.println("The student passed in subject " + (i + 1));
			} else {
				System.out.println("The student failed in subject " + (i + 1));
			}
		}
	}
}

public class StudentRepr {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter student id");
		int id = sc.nextInt();
		
		if (id <= 0) {
			System.out.println("Invalid ID!");
			System.exit(0);
		}
		
		double[] marks = new double[5];
		System.out.println("Enter marks in 5 subjects");
		for (int i = 0; i < 5; i++) {
			double mark = sc.nextDouble();
			if (mark < 0 || mark > 100) {
				System.out.println("Invalid mark entered");
				System.exit(0);
			}
			marks[i] = mark;
		}
		
		Student obj = new Student(id, marks);
		obj.calcScore();
		obj.passOrFail();
	}

}
