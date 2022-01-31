package javaCalculator;
/*
 * Author: James Nordquist
 * 
 * Date: 1/18/2020
 * 
 * Class that the calculator class will use to have buttons
 */
import javax.swing.JButton;

public class Number extends JButton 
{
	String value; // Allow digits operands and anything else I may need
	public Number(String nvalue)
	{
		value = nvalue;
		this.setText(value);
	}

	public String GetValue()
	{
		return value;
	}
}
