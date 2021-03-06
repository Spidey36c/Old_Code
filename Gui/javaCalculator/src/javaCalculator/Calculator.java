package javaCalculator;
/*
 * Author: James Nordquist
 * 
 * Date: 1/18/2020
 * 
 * Main Display, holds the buttons and screen as wells as the
 * listeners
 */
import javax.swing.JPanel;

import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.LayoutManager;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javaCalculator.Number;
import javaCalculator.Screen;

public class Calculator extends JPanel 
{
	Screen scrn = new Screen();
	public Calculator()
	{
		LayoutManager m_layout;
		m_layout = new GridBagLayout();   
		setLayout(m_layout);    
		GridBagConstraints c = new GridBagConstraints();
		Number num = new Number("C");
		Number num1 = new Number("+/-");
		Number num2 = new Number("/");
		Number num3 = new Number("*");
		Number num4 = new Number("7");
		Number num5 = new Number("8");
		Number num6 = new Number("9");
		Number num7 = new Number("-");
		Number num8 = new Number("4");
		Number num9 = new Number("5");
		Number num10 = new Number("6");
		Number num11 = new Number("+");
		Number num12 = new Number("1");
		Number num13 = new Number("2");
		Number num14 = new Number("3");
		Number num15 = new Number("0");
		Number num16 = new Number(".");
		Number num17 = new Number("=");
		
		c.anchor = GridBagConstraints.NORTHWEST;
		c.weightx = 1;
		c.gridx = 0;
		c.gridy = 0;
		c.gridwidth = 4;
		c.fill = GridBagConstraints.HORIZONTAL;
		add(scrn, c);
		
		c.weighty = 1;
		c.gridwidth = 1;
		c.gridy = 1;
		c.fill = GridBagConstraints.BOTH;
		num.addActionListener(new ClearListener());
		add(num, c);
		c.gridx = 1;
		num1.addActionListener(new NegateListener());
		add(num1,c);
		c.gridx = 2;
		num2.addActionListener(new OperandListener());
		add(num2,c);
		c.gridx = 3;
		num3.addActionListener(new OperandListener());
		add(num3,c);
		
		c.gridy = 2;
		c.gridx = 0;
		num4.addActionListener(new NumberListener());
		add(num4,c);
		c.gridx = 1;
		num5.addActionListener(new NumberListener());
		add(num5,c);
		c.gridx = 2;
		num6.addActionListener(new NumberListener());
		add(num6,c);
		c.gridx = 3;
		num7.addActionListener(new OperandListener());
		add(num7,c);
		
		c.gridy = 3;
		c.gridx = 0;
		num8.addActionListener(new NumberListener());
		add(num8,c);
		c.gridx = 1;
		num9.addActionListener(new NumberListener());
		add(num9,c);
		c.gridx = 2;
		num10.addActionListener(new NumberListener());
		add(num10,c);
		c.gridx = 3;
		num11.addActionListener(new OperandListener());
		add(num11,c);
		
		c.gridy = 4;
		c.gridx = 0;
		num12.addActionListener(new NumberListener());
		add(num12,c);
		c.gridx = 1;
		num13.addActionListener(new NumberListener());
		add(num13,c);
		c.gridx = 2;
		num14.addActionListener(new NumberListener());
		add(num14,c);
		
		c.gridy = 5;
		c.gridwidth = 2;
		c.gridx = 0;
		num15.addActionListener(new NumberListener());
		add(num15,c);
		c.gridwidth = 1;
		c.gridx = 2;
		num16.addActionListener(new NumberListener());
		add(num16,c);
		c.gridheight = 2;
		c.weighty =1;
		c.gridx = 3;
		num17.addActionListener(new EqualListener());
		add(num17,c);
	}
	
	class ClearListener implements ActionListener
	{
		public ClearListener()
		{
		}
		public void actionPerformed(ActionEvent e) 
		{
			scrn.Clear(); 
		}
	}
	class NegateListener implements ActionListener
	{
		public NegateListener()
		{
		}
		public void actionPerformed(ActionEvent e) 
		{
			scrn.Negate();
		}
	}
	class OperandListener implements ActionListener
	{
		public OperandListener()
		{
		}
		public void actionPerformed(ActionEvent e) 
		{
			scrn.AddOperator(e.getActionCommand());
		}
	}
	class NumberListener implements ActionListener
	{
		public NumberListener()
		{
		}
		public void actionPerformed(ActionEvent e) 
		{
			scrn.AddDigit(e.getActionCommand());
		}
	}
	class EqualListener implements ActionListener
	{
		double value;
		public EqualListener()
		{
		}
		public void actionPerformed(ActionEvent e) 
		{
			value = scrn.GetValue();
			if(value != Double.MAX_VALUE)
			{
				scrn.SetValue(value);
			}
		}
	}
}
