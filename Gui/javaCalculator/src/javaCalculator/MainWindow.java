package javaCalculator;
/*
 * Author: James Nordquist
 * 
 * Date 1/18/2020
 * 
 * 
 * Main Window where jframe is created and adds the calculator as a panel
 */
import javax.swing.JFrame;

import javaCalculator.Calculator;

public class MainWindow {

	public static void main(String[] args) 
	{
		JFrame frame = new JFrame();  
		frame.setSize(300,600);  
		frame.setTitle("James Nordquist");  
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
		
		frame.add(new Calculator());
		
		frame.setVisible(true);
	}

}
