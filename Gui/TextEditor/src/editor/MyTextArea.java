package editor;
/*
 * MyTextArea Class
 * Allows us to change the font and Style of the text in the text area
 */
import java.awt.Font;


public class MyTextArea extends javax.swing.JTextArea {
	protected String m_font;
	protected int m_style;
	public MyTextArea()
	{
		this.setEditable(true); //allows the user to edit textarea
	}
	
	public void setMyFont(String font) //change font
	{
		m_font = font; //update current font
		Font newfont = new Font(m_font,m_style, this.getFont().getSize()); //create new font with desired font
		this.setFont(newfont); //change font to desired one
	}
	
	public void setMyStyle(int style) //change style
	{
		m_style = style; //update current style
		Font newfont = new Font(m_font,m_style, this.getFont().getSize()); //create new font with desired style
		this.setFont(newfont); //change font to desired one
	}
}
