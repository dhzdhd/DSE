import java.util.Scanner;

public class StringHandling {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int choice = 0;
		
		System.out.println("1) Compare strings");
		System.out.println("2) Convert case");
		System.out.println("3) Check if substring");
		System.out.println("any other number) Exit");
		
		while (true) {
			System.out.println("Enter your choice");
			choice = sc.nextInt();
			
			switch (choice) {
			case 1: {
				System.out.println("Enter two strings");
				String str1 = sc.next();
				String str2 = sc.next();
				
				int comparison = str1.compareTo(str2);
				
				if (comparison == 0) {
					System.out.println("The two strings are equal");
				} else if (comparison < 0) {
					System.out.println("String 1 is smaller than 2");
				} else {
					System.out.println("String 1 is greater than 2");
				}
				break;
			}
			case 2: {
				System.out.println("Enter a string");
				String str = sc.next();
				StringBuffer buffer = new StringBuffer(str.length());
				
				for (char chr: str.toCharArray()) {
					if (Character.isLowerCase(chr)) {
						buffer.append(Character.toUpperCase(chr));
					} else if (Character.isUpperCase(chr)) {
						buffer.append(Character.toLowerCase(chr));
					}
					else {
						buffer.append(chr);
					}
				}
				
				str = buffer.toString();
				System.out.println("The converted case character is: " + str);
				break;
			}
			case 3: {
				System.out.println("Enter string and substring");
				String str = sc.next();
				String sub = sc.next();
				
				if (str.contains(sub)) {
					System.out.println("The given string is a substring of the other");
				} else {
					System.out.println("The given string is not a substring of the other");
					break;
				}
				
				str = str.replaceAll(sub, "Hello");
				System.out.println("The new string is: " + str);
				
				break;
			}
			default: {
				System.exit(0);
			}
			}
		}
	}

}
