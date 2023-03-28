import java.util.Scanner;

interface Sports {
	public default int getNumberOfGoals() {
		Scanner sc = new Scanner(System.in);
		
		int goal = -1;
		while (goal < 0) {
			try {
				goal = Integer.parseInt(sc.next());
			} catch (NumberFormatException e) {
				System.out.println(e);
			}
			
			if (goal < 0) {
				System.out.println("Goal has to be positive");
			}
		}
		
		return goal;
	}

	public default String[] dispTeam() {
		Scanner sc = new Scanner(System.in);
		
		String arr[] = new String[11];
		
		for (int i = 0; i < 11; i++) {
			arr[i] = sc.next();
		}
		
		return arr;
	}
}

class Hockey implements Sports {
	public int getGoals() {
		System.out.println("Enter number of goals in hockey");
		return getNumberOfGoals();
	}
	
	public String[] getTeam() {
		System.out.println("Enter hockey team members");
		return dispTeam();
	}
}

class Football implements Sports {
	public int getGoals() {
		System.out.println("Enter number of goals in football");
		return getNumberOfGoals();
	}
	
	public String[] getTeam() {
		System.out.println("Enter football team members");
		return dispTeam();
	}
}


public class SportsInterface {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		Hockey india = new Hockey();
		System.out.println("Goals in India:" + india.getGoals());
		String[] indianTeam = india.getTeam();
		System.out.println("Team members in India:");
		for (String s: indianTeam) {
			System.out.print(s + ", ");
		}
		System.out.println();
		
		Football brazil = new Football();
		System.out.println("Goals in Brazil:" + brazil.getGoals());
		String[] brazilianTeam = brazil.getTeam();
		System.out.println("Team members in Brazil:");
		for (String s: brazilianTeam) {
			System.out.print(s + ", ");
		}
		System.out.println();
	}

}
