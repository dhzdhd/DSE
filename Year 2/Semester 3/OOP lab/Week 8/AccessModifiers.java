import java.util.Scanner;

class Demo {

	private String a;
	protected String b;
	String c;
	public String d;
	
	Demo(String a, String b, String c, String d) {
		this.a = a;
		this.b = b;
		this.c = c;
		this.d = d;
	}
	
	String getA() {
		return a;
	}

}

class InheritedDemo extends Demo {
	InheritedDemo(String b) {
		super("", b, "", "");
	}
	
	String getB() {
		return b;
	}
}

public class AccessModifiers {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter 4 strings");
		String a = sc.next();
		String b = sc.next();
		String c = sc.next();
		String d = sc.next();
	
		Demo obj = new Demo(a, b, c, d);
		
		System.out.println("Private var: " + obj.getA());
		System.out.println("Protected var: " + new InheritedDemo(b).getB());
		System.out.println("Default var: " + obj.c);
		System.out.println("Public var: " + obj.d);
	}

}

