package mit.dse.q1;

import java.util.Scanner;

public class TypeConversion {
    public static void main(String[] args) {
        System.out.println("Enter an int, double and char");

        Scanner sc = new Scanner(System.in);

        int i = sc.nextInt();
        double d = sc.nextDouble();
        char c = sc.next().charAt(0);

        byte intToByte = (byte) i;
        int charToInt = (int) c;
        byte doubleToByte = (byte) d;
        int doubleToInt = (int) d;

        System.out.println("The typecasted results are: " + intToByte + " " + charToInt + " " + doubleToByte + " " + doubleToInt);
    }
}
