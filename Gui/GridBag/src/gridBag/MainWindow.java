package gridBag;

import javax.swing.JFrame;
import javax.swing.JPanel;

public class MainWindow 
{

	public static void main(String[] args) 
	{
		JFrame frame = new JFrame();  
		frame.setSize(450,220);  
		frame.setTitle("James Nordquist");  
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
		
		frame.add(new MyPanel());
		
		frame.setVisible(true);
	}

}
