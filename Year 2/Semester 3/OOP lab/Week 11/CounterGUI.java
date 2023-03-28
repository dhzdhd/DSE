import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class GUI extends JFrame {
	JLabel counter;
	JTextField countertf;
	JButton counterbtn;
	
	GUI() {
		setTitle("Counter");
		setSize(400, 200);
		
		getContentPane().setLayout(null);
		
		counter = new JLabel("Counter");
		counter.setBounds(50, 20, 100, 20);
		getContentPane().add(counter);
		
		countertf = new JTextField("0");
		countertf.setBounds(100, 20, 100, 20);
		getContentPane().add(countertf);
		
		counterbtn = new JButton("Count");
		counterbtn.setBounds(200, 20, 100, 20);
		getContentPane().add(counterbtn);
		counterbtn.addActionListener((ActionEvent e) -> {
			String valstr = countertf.getText();
			int val = 0;
			try {
				val = Integer.parseInt(valstr);
			} catch(NumberFormatException ex) {
				System.out.println(ex);
			}
			
			countertf.setText(Integer.toString(val + 6));
		});
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
	}
}

public class CounterGUI {

	public static void main(String[] args) {
		new GUI();

	}

}
