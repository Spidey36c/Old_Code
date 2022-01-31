package editor;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

import javax.swing.JFileChooser;
import javax.swing.JFrame;
/*
 * MyMenu Class
 * Creates menus and adds menu Items to the appropriate menus
 */
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;

public class MyMenu extends JMenuBar {
	private MyTextArea textArea;
	private JFrame myFrame;
	public MyMenu(MyTextArea e, JFrame frame)
	{
		textArea = e;
		myFrame = frame;
		// Creating Menus
		JMenu File;
		File = new JMenu("File");
		add(File);
		
		JMenu Font;
		Font = new JMenu("Font");
		add(Font);
		
		JMenu Style;
		Style = new JMenu("Style");
		add(Style);
		
		// Adding MenuItems to Menus
		JMenuItem menuItem;
		menuItem = new JMenuItem("Load");
		menuItem.addActionListener(new FileListener("Load", textArea, myFrame));
		File.add(menuItem);
		menuItem = new JMenuItem("Save");
		menuItem.addActionListener(new FileListener("Save", textArea, myFrame));
		File.add(menuItem);
		menuItem = new JMenuItem("Exit");
		menuItem.addActionListener(new FileListener("Exit", textArea, myFrame));
		File.add(menuItem);
	
		menuItem = new JMenuItem("Mono");
		menuItem.addActionListener(new FontListener(java.awt.Font.MONOSPACED, textArea));
		Font.add(menuItem);
		menuItem = new JMenuItem("Serif");
		menuItem.addActionListener(new FontListener(java.awt.Font.SERIF, textArea));
		Font.add(menuItem);
		menuItem = new JMenuItem("Sans-Serif");
		menuItem.addActionListener(new FontListener(java.awt.Font.SANS_SERIF, textArea));
		Font.add(menuItem);
		
		menuItem = new JMenuItem("Plain");
		Style.add(menuItem);
		menuItem.addActionListener(new StyleListener(java.awt.Font.PLAIN, textArea));
		menuItem = new JMenuItem("Italics");
		Style.add(menuItem);
		menuItem.addActionListener(new StyleListener(java.awt.Font.ITALIC, textArea));
		menuItem = new JMenuItem("Bold");
		Style.add(menuItem);
		menuItem.addActionListener(new StyleListener(java.awt.Font.BOLD, textArea));
	}
}

/*
 * FontListener Class
 * Changes the Font of the text in the JTextArea when the appropriate MenuItem is selected
 */
class FontListener implements ActionListener
{
	private MyTextArea textArea;
	private String Font;
	public FontListener(String e, MyTextArea s) //get textarea and what font they wanted to change to
	{
		Font = e;
		textArea = s;
	}
	public void actionPerformed(ActionEvent e) 
	{
		textArea.setMyFont(Font); //set the font with the desired font
	}
}

/*
 * StyleListener Class
 * Changes the Style of the text in the JTextArea when the appropriate MenuItem is selected
 */
class StyleListener implements ActionListener
{
	private MyTextArea textArea;
	private int Style;
	public StyleListener(int e, MyTextArea s) //get textarea and what style they wanted to change to
	{
		textArea = s;
		Style = e;
	}
	public void actionPerformed(ActionEvent e) 
	{
		textArea.setMyStyle(Style); //change the style to the desired style
	}
	
}

/*
 * File Listener Class
 * Checks for saves,loads and exits
 */
class FileListener implements ActionListener
{
	private MyTextArea textArea;
	private String select;
	private JFrame frame;
	public FileListener(String selection, MyTextArea e, JFrame s) //get the textarea frame and selection
	{
		textArea = e;
		select = selection;
		frame = s;
	}
	public void actionPerformed(ActionEvent e) 
	{
		int userSelection;
		JFileChooser filechooser = new JFileChooser();
		switch(select)
		{
		case "Exit": //if user wants to exit
			frame.dispatchEvent(new WindowEvent(frame, WindowEvent.WINDOW_CLOSING)); //exit
			break;
		case "Save"://if user wants to save
			filechooser.setDialogTitle("Specify a file to save"); //open dialog box
			
			userSelection = filechooser.showSaveDialog(frame);
			
			if(userSelection == JFileChooser.APPROVE_OPTION)
			{
				File filetosave = filechooser.getSelectedFile(); //get filename
				try {
					FileWriter fw = new FileWriter(filetosave.getAbsoluteFile());
					textArea.write(fw); //write to file
					} 
				catch (IOException except)
				{
					System.out.println("File was incorrect");
				}
			}
			break;
		case "Load": //if user wants to load
			filechooser.setDialogTitle("Specifiy a file to Open"); //open dialog box
			
			userSelection = filechooser.showOpenDialog(frame);
			
			if(userSelection == JFileChooser.APPROVE_OPTION)
			{
				File filetoopen = filechooser.getSelectedFile(); //get filename
				try {
					FileReader fr = new FileReader(filetoopen.getAbsoluteFile());
					textArea.read(fr,filetoopen.getAbsoluteFile()); //read file
				}
				catch(IOException except)
				{
					System.out.println("File not Found");
				}
			}
			break;
		}
		
	}
}
