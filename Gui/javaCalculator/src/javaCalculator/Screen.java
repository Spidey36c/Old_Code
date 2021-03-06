package javaCalculator;
/*
 * Author: James Nordquist
 * 
 * Date: 1/18/2020
 * 
 * Screen that displays calculations as well as the result
 */
import java.util.Scanner;

import javax.swing.JTextField;

public class Screen extends JTextField
{
	String current = "0"; // Digit currently being worked on
	String screen; // What to display
	String prevScreen = ""; //Used to have a reliable display
	Boolean newinput = true; // Used to tell if need to clear
	Boolean newnumber = true;
	Boolean newoperand = true;
	public Screen()
	{
		this.setSize(50,50);
		this.setFont((this.getFont().deriveFont(20f)));
		this.setEditable(false);
		this.setText(current);
	}
	
	public void AddDigit(String digit)
	{
		if(newinput == true)
		{
			this.Clear();
			current = "0";
			newinput = false;
		}
		if(newoperand == false)
		{
			current = current.substring(0, 1);
			screen = prevScreen;
			screen += current;
			prevScreen = screen;
			newoperand = true;
		}
		if(newnumber == true)
		{
			current = "";
			newnumber = false;
		}
		screen = prevScreen; // Go to saved display
		current += digit; // add digit to current number
		screen += current; // add current number to display
		this.setText(screen); // Display
	}
	
	public void AddOperator(String op)
	{
		if(newinput == true)
		{
			this.Clear();
			newinput = false;
		}
		if(newoperand == true)
		{
			screen = prevScreen; //Go to saved display
			screen += current; // add current to screen
			prevScreen = screen; // Save display
			current = op + "0"; // reset current
			screen += current;
			this.setText(screen); // Display
			newnumber = true;
			newoperand = false;
		}
		else
		{
			screen = prevScreen;
			current = op + "0";
			screen += current;
			this.setText(screen);
		}
	}
	
	public void Negate()
	{
		if(newoperand == true)
		{
			if(current.charAt(0) == '-') // if negative make positive
			{
				current = current.substring(1);
			}
			else // if positive make negative
			{
				current = "-" + current;
			}
			
			screen = prevScreen;
			screen += current;
			this.setText(screen);
		}
	}
	
	public void Clear()
	{
		prevScreen = "";
		screen = "";
		if(newinput == true)
		{
			current = "0";
		}
		this.setText(current);
		newnumber = true;
		newoperand = true;
	}
	
	public double GetValue()
	{
		screen = prevScreen;
		screen += current;
		this.setText(screen);
		String value = this.getText();
		double storedvalue;
		double newvalue;
		Scanner sc = new Scanner(value);
		String operator;
		
		storedvalue = Double.parseDouble(sc.findInLine("-?\\d+\\.\\d+|-?\\d+|-?\\.\\d+"));
		// calculation may be too complicated
		while(sc.hasNext())
		{
			operator = sc.findInLine("[-*/+]");
			newvalue = Double.parseDouble(sc.findInLine("-?\\d+\\.\\d+|-?\\d+|-?\\.\\d+"));
			
			switch(operator)
			{
			case "+":
				storedvalue += newvalue;
				break;
			case "-":
				storedvalue -= newvalue;
				break;
			case "*":
				storedvalue *= newvalue;
				break;
			case "/":
				if(newvalue != 0)
				{
				storedvalue /= newvalue;
				}
				else
				{
					this.setText("Cannot Divide by 0");
					newinput = true;
					return Double.MAX_VALUE;
				}
				break;
			default:
				this.setText("Invalid");
				newinput = true;
			}
		}
		sc.close();
		return storedvalue;
	}
	
	public void SetValue(double value)
	{
		screen = Double.toString(value);
		current = screen;
		this.setText(screen);
		newnumber = true;
		newinput = true;
	}
}
