import java.io.FileReader;
import java.io.Reader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.Scanner;

public class CharCount {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		Reader reader = null;
		try {
			System.out.println("Enter path");
			String path = sc.next();
			
			Reader temp = new FileReader(path);
			reader = new BufferedReader(temp);
		} catch (FileNotFoundException e) {
			System.out.println(e);
		}
		
		int vowelCount = 0;
		int charCount = 0;
		int lineCount = 0;
		int wordCount = 0;
		
		int c = 0;
		while (c != -1) {
			try {
				c = reader.read();

				if ((char)c != ' ' && (char)c != '\n' ) {
					charCount++;
				}
				
				if ((char) c == 'a' || (char) c == 'e' || (char)c == 'i' || (char)c == 'o' || (char)c == 'u') {
					vowelCount++;
				}
				
				if ((char) c == ' ' || (char) c == '\n') {
					wordCount++;
				}
				
				if ((char) c == '\n') {
					lineCount++;
				}
				
			} catch (IOException e) {
				System.out.println(e);
				break;
			}
		}
		
		System.out.println("Vowel count: " + vowelCount);
		System.out.println("Character count: " + charCount);
		System.out.println("Word count: " + (wordCount + 1));
		System.out.println("Line count: " + (lineCount + 1));
		
		try {
			reader.close();
		} catch (IOException e) {
			System.out.println(e);
		}
	}

}
