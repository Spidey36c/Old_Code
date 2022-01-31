package gridBag;

import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.LayoutManager;

import javax.swing.JButton;
import javax.swing.JPanel;

public class MyPanel extends JPanel 
{
	public MyPanel() 
	{   
		LayoutManager m_layout;
		m_layout = new GridBagLayout();   
		setLayout(m_layout);    
		GridBagConstraints c = new GridBagConstraints();   
		
		c.weightx = 0.2;
		c.gridx = 0;   
		c.gridy = 0;  
		c.fill = GridBagConstraints.HORIZONTAL;  
		add(new JButton("Button 1"), c);    
		c.weightx = 0.8;
		c.gridx = 1;    
		add(new JButton("Button 2"), c);
		c.weightx = 0.2;
		c.gridx = 2;
		add(new JButton("Button 3"), c);
		c.gridx = 0;
		c.gridy = 1;
		c.weighty = 0.6;
		c.fill = GridBagConstraints.VERTICAL;
		add(new JButton("Button 4"), c);   
		c.gridx = 1;
		c.gridy = 1;
		c.fill = GridBagConstraints.NONE;
		add(new JButton("B4"), c);   
		c.gridx = 2;
		c.gridy = 1;
		c.weighty = 0.6;
		c.fill = GridBagConstraints.BOTH;
		add(new JButton("Button 5"), c);   
		c.weightx = 0.0;
		c.fill = GridBagConstraints.HORIZONTAL;
		c.weighty = 0.7;   
		c.anchor = GridBagConstraints.PAGE_END; 
		c.gridx = 1;       
		c.gridwidth = 2;   
		c.gridy = 2;       
		add(new JButton("Button 6"), c);   
	}
}
