import java.util.Scanner;

class Invalid_File_Extn extends Exception {
	Invalid_File_Extn() {
		super("Invalid file extension!");
	}
}

public class CheckFileExt {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter number of filenames to enter");

		int n = 0;
		while (n <= 0) {
			try {
				n = Integer.parseInt(sc.next());
				
				if (n <= 0) {
					System.out.println("Enter a positive value");
				}
			} catch(NumberFormatException e) {
				System.out.println("Enter integer!");
			}
		}
		
		String arr[] = new String[n];
		
		for (int i = 0; i < n; i++) {
			arr[i] = sc.next();
		}
		
		String[] split = arr[0].split("[.]");
		String ext = split[split.length - 1];
		try {
			for (String file: arr) {
				String[] splitStr = arr[0].split("[.]");
				
				if (!ext.contentEquals(splitStr[splitStr.length - 1]))  {
					throw new Invalid_File_Extn();
				}
			}
			
			System.out.println("All file extensions are the same");
		} catch (Invalid_File_Extn e) {
			System.out.println(e);
		}
		
	}

}
