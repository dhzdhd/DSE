import java.util.Scanner;

public class MatrixMultiplication {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter order of first matrix");
		int m1 = sc.nextInt();
		int n1 = sc.nextInt();
		
		System.out.println("Enter order of second matrix");
		int m2 = sc.nextInt();
		int n2 = sc.nextInt();
		
		if (n1 <= 0 || m1 <= 0 || n2 <= 0 || m2 <= 0) {
			System.out.println("Invalid order entered");
			System.exit(0);
		}
		
		float matrix1[][] = new float[m1][n1];
		float matrix2[][] = new float[m2][n2];
		float result[][] = new float[50][50];
		
		System.out.println("Enter elements of first matrix");
		for (int i = 0; i < m1; i++) {
			for (int j = 0; j < n1; j++) {
				matrix1[i][j] = sc.nextFloat();
			}
		}
		
		System.out.println("Enter elements of second matrix");
		for (int i = 0; i < m2; i++) {
			for (int j = 0; j < n2; j++) {
				matrix2[i][j] = sc.nextFloat();
			}
		}

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					result[i][j] += matrix1[i][k] * matrix2[k][j];
				}
			}
		}
		
		System.out.println("The resulting matrix is");
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				System.out.print(result[i][j] + " ");
			}
			System.out.println();
		}
		
	}

}
